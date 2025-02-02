/* Generated by re2c */
// re2c $INPUT -o $OUTPUT -ci
#include <stdint.h>
#include <limits.h>
#include <assert.h>

static const uint64_t ERROR = ~0lu;
enum YYCONDTYPE {
	yycinit,
	yycbin,
	yycdec,
	yychex,
	yycoct,
};


template<int BASE> static void adddgt(uint64_t &u, unsigned int d) {
    u = u * BASE + d;
    if (u > UINT32_MAX) u = ERROR;
}

static uint64_t parse_u32(const char *s) {
    const char *YYMARKER;
    int c = yycinit;
    uint64_t u = 0;

    
{
	char yych;
	switch (c) {
		case yycinit: goto yyc_init;
		case yycbin: goto yyc_bin;
		case yycdec: goto yyc_dec;
		case yychex: goto yyc_hex;
		case yycoct: goto yyc_oct;
	}
/* *********************************** */
yyc_init:
	yych = *s;
	switch (yych) {
		case '0': goto yy2;
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy4;
		default: goto yy1;
	}
yy1:
	++s;
	{ return ERROR; }
yy2:
	yych = *(YYMARKER = ++s);
	switch (yych) {
		case 'B':
		case 'b': goto yy5;
		case 'X':
		case 'x': goto yy7;
		default: goto yy3;
	}
yy3:
	c = yycoct;
	goto yyc_oct;
yy4:
	++s;
	s -= 1;
	c = yycdec;
	goto yyc_dec;
yy5:
	yych = *++s;
	switch (yych) {
		case '0':
		case '1': goto yy8;
		default: goto yy6;
	}
yy6:
	s = YYMARKER;
	goto yy3;
yy7:
	yych = *++s;
	switch (yych) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f': goto yy9;
		default: goto yy6;
	}
yy8:
	++s;
	s -= 1;
	c = yycbin;
	goto yyc_bin;
yy9:
	++s;
	s -= 1;
	c = yychex;
	goto yyc_hex;
/* *********************************** */
yyc_bin:
	yych = *s;
	switch (yych) {
		case 0x00: goto yy11;
		case '0':
		case '1': goto yy13;
		default: goto yy12;
	}
yy11:
	++s;
	{ return u; }
yy12:
	++s;
	{ return ERROR; }
yy13:
	++s;
	{ adddgt<2> (u, s[-1] - '0');      goto yyc_bin; }
/* *********************************** */
yyc_dec:
	yych = *s;
	switch (yych) {
		case 0x00: goto yy15;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy17;
		default: goto yy16;
	}
yy15:
	++s;
	{ return u; }
yy16:
	++s;
	{ return ERROR; }
yy17:
	++s;
	{ adddgt<10>(u, s[-1] - '0');      goto yyc_dec; }
/* *********************************** */
yyc_hex:
	yych = *s;
	switch (yych) {
		case 0x00: goto yy19;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': goto yy21;
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F': goto yy22;
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f': goto yy23;
		default: goto yy20;
	}
yy19:
	++s;
	{ return u; }
yy20:
	++s;
	{ return ERROR; }
yy21:
	++s;
	{ adddgt<16>(u, s[-1] - '0');      goto yyc_hex; }
yy22:
	++s;
	{ adddgt<16>(u, s[-1] - 'A' + 10); goto yyc_hex; }
yy23:
	++s;
	{ adddgt<16>(u, s[-1] - 'a' + 10); goto yyc_hex; }
/* *********************************** */
yyc_oct:
	yych = *s;
	switch (yych) {
		case 0x00: goto yy25;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7': goto yy27;
		default: goto yy26;
	}
yy25:
	++s;
	{ return u; }
yy26:
	++s;
	{ return ERROR; }
yy27:
	++s;
	{ adddgt<8> (u, s[-1] - '0');      goto yyc_oct; }
}

}

int main() {
    assert(parse_u32("1234567890") == 1234567890);
    assert(parse_u32("0b1101") == 13);
    assert(parse_u32("0x7Fe") == 2046);
    assert(parse_u32("0644") == 420);
    assert(parse_u32("9999999999") == ERROR);
    assert(parse_u32("") == ERROR);
    return 0;
}
