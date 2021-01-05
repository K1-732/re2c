#include <assert.h>
#include <string.h>
#include <time.h>

#include "benchmarks/common/common.h"
#include "benchmarks/common/strings_atom.h"
#include "benchmarks/common/strings_date.h"
#include "benchmarks/common/strings_http.h"
#include "benchmarks/common/strings_ipv4.h"
#include "benchmarks/common/strings_ipv6.h"
#include "benchmarks/common/strings_uri.h"
#include "lib/regex.h"


const benchmark_t benchmarks[] = {
    {"re2c-tnfa-leftmost",        ENGINE_RE2C, REG_NFA | REG_LEFTMOST},
    {"re2c-tnfa-leftmost-trie",   ENGINE_RE2C, REG_NFA | REG_LEFTMOST | REG_TRIE},
    {"re2",                       ENGINE_RE2,  0},
    {"re2c-tnfa-posix-gor1",      ENGINE_RE2C, REG_NFA | REG_GTOP},
    {"re2c-tnfa-posix-gtop",      ENGINE_RE2C, REG_NFA},
    {"re2c-tnfa-posix-gor1-slow", ENGINE_RE2C, REG_NFA | REG_SLOWPREC},
    {"re2c-tnfa-posix-gor1-trie", ENGINE_RE2C, REG_NFA | REG_TRIE},
    {"re2c-tnfa-posix-kukl-gor1", ENGINE_RE2C, REG_NFA | REG_KUKLEWICZ},
    {"re2c-tnfa-posix-back-gor1", ENGINE_RE2C, REG_NFA | REG_BACKWARD}
};

const size_t nbenchmarks = sizeof(benchmarks) / sizeof(benchmark_t);

void show(const std::vector<Result> &results)
{
    const size_t n = results.size();
    assert(n > 0);

    const uint64_t ticks0 = results[0].ticks_run;

    for (size_t i = 0; i < n; ++i) {
        const Result &r = results[i];
        if (r.ticks_run == UNAVAIL) {
            fprintf(stderr, "%30s:%10s%10s\n", r.title, "-", "-");
        } else {
            fprintf(stderr, "%30s:%10.2lf%10.3lfs%10lu\n", r.title,
                double(r.ticks_run) / double(ticks0),
                double(r.ticks_run) / CLOCKS_PER_SEC,
                r.ticks_run);
        }
    }
}

int main()
{
    const char *regexp;
    std::vector<std::string> strings;
    static const size_t VERY_LONG = (1 << 13) + 1;
    char *longstring = new char[VERY_LONG + 1];

    // http
    LOAD_STRINGS(strings, http);
    regexp = MESSAGE_HEAD;
    bench(regexp, strings, 10, REG_BACKWARD | REG_STADFA, 0);
    regexp = MESSAGE_HEAD2;
    bench(regexp, strings, 10, REG_BACKWARD, 0);

    // uri
    LOAD_STRINGS(strings, uri);
    regexp = URI;
    bench(regexp, strings, 10, REG_BACKWARD | REG_STADFA, 0);
    regexp = URI2;
    bench(regexp, strings, 10, 0, 0);

    // ipv6
    LOAD_STRINGS(strings, ipv6);
    regexp = IPV6;
    bench(regexp, strings, 100, REG_BACKWARD, 0);
    regexp = IPV62;
    bench(regexp, strings, 100, 0, REG_NFA); // DFA is very large

    // ipv4
    LOAD_STRINGS(strings, ipv4);
    regexp = IPV4;
    bench(regexp, strings, 10000, 0, 0);
    regexp = IPV42;
    bench(regexp, strings, 10000, 0, 0);

    // date
    LOAD_STRINGS(strings, date);
    regexp = DATE;
    bench(regexp, strings, 1000, 0, 0);
    regexp = DATE2;
    bench(regexp, strings, 1000, 0, 0);

    // atom
    LOAD_STRINGS(strings, atom);
    regexp = PACKAGE_ATOM;
    bench(regexp, strings, 10, 0, 0);
    regexp = PACKAGE_ATOM2;
    bench(regexp, strings, 10, 0, 0);

    longstring[VERY_LONG] = 0;
    memset(longstring, 'a', VERY_LONG);
    longstring[VERY_LONG] = 0;
    strings.clear();
    strings.push_back(longstring);

    regexp = "(a{2}|a{3}|a{5})*";
    bench(regexp, strings, 1, 0, 0);
    regexp = "(a{7}|a{13}|a{19})*";
    bench(regexp, strings, 1, 0, 0);
    regexp = "(a{29}|a{41}|a{53})*";
    bench(regexp, strings, 1, 0, 0);
    regexp = "(a{67}|a{83}|a{103})*";
    bench(regexp, strings, 1, 0, 0);
    regexp = "(a{127}|a{151}|a{179})*";
    bench(regexp, strings, 1, 0, 0);
    regexp = "(a{199}|a{239}|a{271})*";
    bench(regexp, strings, 1, 0, 0);

    regexp = "(((a){2})|((a){3})|((a){5}))*";
    bench(regexp, strings, 1, 0, 0);
    regexp = "(((a){7})|((a){13})|((a){19}))*";
    bench(regexp, strings, 1, 0, 0);
    regexp = "(((a){29})|((a){41})|((a){53}))*";
    bench(regexp, strings, 1, 0, 0);
    regexp = "(((a){67})|((a){83})|((a){103}))*";
    bench(regexp, strings, 1, 0, 0);
    regexp = "(((a){127})|((a){151})|((a){179}))*";
    bench(regexp, strings, 1, 0, 0);
    regexp = "(((a){199})|((a){239})|((a){271}))*";
    bench(regexp, strings, 1, 0, 0);

    regexp = "(a{0,16})*";
    bench(regexp, strings, 1, 0, 0);
    regexp = "(a{0,64})*";
    bench(regexp, strings, 1, 0, 0);
    regexp = "(a{0,256})*";
    bench(regexp, strings, 1, 0, 0);

    regexp = "((a){0,16})*";
    bench(regexp, strings, 1, 0, 0);
    regexp = "((a){0,64})*";
    bench(regexp, strings, 1, 0, 0);
    regexp = "((a){0,256})*";
    bench(regexp, strings, 1, 0, 0);

    // Pathological case for constant-memory POSIX algorithms that use naive
    // (worst-case cubic in the size of TNFA) algorithm for precedence matrix
    // computation. Cubic behaviour is caused by quadratic-time computation
    // of precedence matrix on each step (the number of core items in closure
    // approaches TNFA size), multiplied by the length of compared histores
    // (which also approaches TNFA size). Trie-based algorithms are not
    // affected, but they consume memory proportional to the length of input,
    // and so are also not practical.

    regexp = "((a?){0,16})*";
    bench(regexp, strings, 1, 0, 0);
    regexp = "((a?){0,64})*";
    bench(regexp, strings, 1, 0, 0);
    regexp = "((a?){0,256})*";
    bench(regexp, strings, 1, 0, 0);

    regexp = "((a*){0,16})*";
    bench(regexp, strings, 1, 0, 0);
    regexp = "((a*){0,64})*";
    bench(regexp, strings, 1, 0, 0);
    regexp = "((a*){0,256})*";
    bench(regexp, strings, 1, 0, 0);

    delete[] longstring;
    return 0;
}

