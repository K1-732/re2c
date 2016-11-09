/* Generated by re2c */

#include <stdio.h>
#include <stdlib.h> /* malloc, free */

static void *read_file
    ( const char *fname
    , size_t unit
    , size_t padding
    , size_t *pfsize
    )
{
    void *buffer = NULL;
    size_t fsize = 0;

    /* open file */
    FILE *f = fopen(fname, "rb");
    if(f == NULL) {
        goto error;
    }

    /* get file size */
    fseek(f, 0, SEEK_END);
    fsize = (size_t) ftell(f) / unit;
    fseek(f, 0, SEEK_SET);

    /* allocate memory for file and padding */
    buffer = malloc(unit * (fsize + padding));
    if (buffer == NULL) {
        goto error;
    }

    /* read the whole file in memory */
    if (fread(buffer, unit, fsize, f) != fsize) {
        goto error;
    }

    fclose(f);
    *pfsize = fsize;
    return buffer;

error:
    fprintf(stderr, "error: cannot read file '%s'\n", fname);
    free(buffer);
    if (f != NULL) {
        fclose(f);
    }
    return NULL;
}

#define YYCTYPE unsigned char
#define YYKEYTYPE unsigned char
#define YYPEEK() *cursor
#define YYSKIP() ++cursor
#define YYLESSTHAN(n) (limit - cursor) < n
#define YYFILL(n) { break; }

static int action_line28
    ( unsigned int i
    , const YYKEYTYPE *keys
    , const YYCTYPE *start
    , const YYCTYPE *token
    , const YYCTYPE **cursor
    , YYKEYTYPE rule_act
    )
{
    const long pos = token - start;
    const long len_act = *cursor - token;
    const long len_exp = (long) keys [3 * i + 1];
    const YYKEYTYPE rule_exp = keys [3 * i + 2];
    if (rule_exp == 255) {
        fprintf
            ( stderr
            , "warning: lex_line28: control flow is undefined for input"
                " at position %ld, rerun re2c with '-W'\n"
            , pos
            );
    }
    if (len_act == len_exp && rule_act == rule_exp) {
        const YYKEYTYPE offset = keys[3 * i];
        *cursor = token + offset;
        return 0;
    } else {
        fprintf
            ( stderr
            , "error: lex_line28: at position %ld (iteration %u):\n"
                "\texpected: match length %ld, rule %u\n"
                "\tactual:   match length %ld, rule %u\n"
            , pos
            , i
            , len_exp
            , rule_exp
            , len_act
            , rule_act
            );
        return 1;
    }
}

int lex_line28()
{
    const size_t padding = 1; /* YYMAXFILL */
    int status = 0;
    size_t input_len = 0;
    size_t keys_count = 0;
    YYCTYPE *input = NULL;
    YYKEYTYPE *keys = NULL;
    const YYCTYPE *cursor = NULL;
    const YYCTYPE *limit = NULL;
    const YYCTYPE *token = NULL;
    const YYCTYPE *eof = NULL;
    unsigned int i = 0;

    input = (YYCTYPE *) read_file
        ("repeat-07_default.gir--skeleton.c.line28.input"
        , sizeof (YYCTYPE)
        , padding
        , &input_len
        );
    if (input == NULL) {
        status = 1;
        goto end;
    }

    keys = (YYKEYTYPE *) read_file
        ("repeat-07_default.gir--skeleton.c.line28.keys"
        , 3 * sizeof (YYKEYTYPE)
        , 0
        , &keys_count
        );
    if (keys == NULL) {
        status = 1;
        goto end;
    }

    cursor = input;
    limit = input + input_len + padding;
    eof = input + input_len;

    for (i = 0; status == 0 && i < keys_count; ++i) {
        token = cursor;
        YYCTYPE yych;

        if (YYLESSTHAN (1)) YYFILL(1);
        yych = YYPEEK ();
        {
            static void *yytarget[256] = {
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy4,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy6,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy8,  &&yy10, &&yy12, &&yy14, &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2
            };
            goto *yytarget[yych];
        }
yy2:
        YYSKIP ();
        status = action_line28(i, keys, input, token, &cursor, 5);
        continue;
yy4:
        YYSKIP ();
        status = action_line28(i, keys, input, token, &cursor, 254);
        continue;
yy6:
        YYSKIP ();
        status = action_line28(i, keys, input, token, &cursor, 4);
        continue;
yy8:
        YYSKIP ();
        status = action_line28(i, keys, input, token, &cursor, 0);
        continue;
yy10:
        YYSKIP ();
        status = action_line28(i, keys, input, token, &cursor, 1);
        continue;
yy12:
        YYSKIP ();
        status = action_line28(i, keys, input, token, &cursor, 2);
        continue;
yy14:
        YYSKIP ();
        status = action_line28(i, keys, input, token, &cursor, 3);
        continue;

    }
    if (status == 0) {
        if (cursor != eof) {
            status = 1;
            const long pos = token - input;
            fprintf(stderr, "error: lex_line28: unused input strings left at position %ld\n", pos);
        }
        if (i != keys_count) {
            status = 1;
            fprintf(stderr, "error: lex_line28: unused keys left after %u iterations\n", i);
        }
    }

end:
    free(input);
    free(keys);

    return status;
}

#undef YYCTYPE
#undef YYKEYTYPE
#undef YYPEEK
#undef YYSKIP
#undef YYLESSTHAN
#undef YYFILL

#define YYCTYPE unsigned short
#define YYKEYTYPE unsigned char
#define YYPEEK() *cursor
#define YYSKIP() ++cursor
#define YYLESSTHAN(n) (limit - cursor) < n
#define YYFILL(n) { break; }

static int action_line46
    ( unsigned int i
    , const YYKEYTYPE *keys
    , const YYCTYPE *start
    , const YYCTYPE *token
    , const YYCTYPE **cursor
    , YYKEYTYPE rule_act
    )
{
    const long pos = token - start;
    const long len_act = *cursor - token;
    const long len_exp = (long) keys [3 * i + 1];
    const YYKEYTYPE rule_exp = keys [3 * i + 2];
    if (rule_exp == 255) {
        fprintf
            ( stderr
            , "warning: lex_line46: control flow is undefined for input"
                " at position %ld, rerun re2c with '-W'\n"
            , pos
            );
    }
    if (len_act == len_exp && rule_act == rule_exp) {
        const YYKEYTYPE offset = keys[3 * i];
        *cursor = token + offset;
        return 0;
    } else {
        fprintf
            ( stderr
            , "error: lex_line46: at position %ld (iteration %u):\n"
                "\texpected: match length %ld, rule %u\n"
                "\tactual:   match length %ld, rule %u\n"
            , pos
            , i
            , len_exp
            , rule_exp
            , len_act
            , rule_act
            );
        return 1;
    }
}

int lex_line46()
{
    const size_t padding = 1; /* YYMAXFILL */
    int status = 0;
    size_t input_len = 0;
    size_t keys_count = 0;
    YYCTYPE *input = NULL;
    YYKEYTYPE *keys = NULL;
    const YYCTYPE *cursor = NULL;
    const YYCTYPE *limit = NULL;
    const YYCTYPE *token = NULL;
    const YYCTYPE *eof = NULL;
    unsigned int i = 0;

    input = (YYCTYPE *) read_file
        ("repeat-07_default.gir--skeleton.c.line46.input"
        , sizeof (YYCTYPE)
        , padding
        , &input_len
        );
    if (input == NULL) {
        status = 1;
        goto end;
    }

    for (i = 0; i < input_len; ++i) {
        /* from little-endian to host-endian */
        unsigned char *p = (unsigned char*)&input[i];
        input[i] = p[0] + (p[1] << 8u);
    }

    keys = (YYKEYTYPE *) read_file
        ("repeat-07_default.gir--skeleton.c.line46.keys"
        , 3 * sizeof (YYKEYTYPE)
        , 0
        , &keys_count
        );
    if (keys == NULL) {
        status = 1;
        goto end;
    }

    cursor = input;
    limit = input + input_len + padding;
    eof = input + input_len;

    for (i = 0; status == 0 && i < keys_count; ++i) {
        token = cursor;
        YYCTYPE yych;

        if (YYLESSTHAN (1)) YYFILL(1);
        yych = YYPEEK ();
        if (yych & ~0xFF) {
        } else {
            static void *yytarget[256] = {
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy4,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy6,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy8,  &&yy10, &&yy12, &&yy14, &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2
            };
            goto *yytarget[yych];
        }
yy2:
        YYSKIP ();
        status = action_line46(i, keys, input, token, &cursor, 5);
        continue;
yy4:
        YYSKIP ();
        status = action_line46(i, keys, input, token, &cursor, 254);
        continue;
yy6:
        YYSKIP ();
        status = action_line46(i, keys, input, token, &cursor, 4);
        continue;
yy8:
        YYSKIP ();
        status = action_line46(i, keys, input, token, &cursor, 0);
        continue;
yy10:
        YYSKIP ();
        status = action_line46(i, keys, input, token, &cursor, 1);
        continue;
yy12:
        YYSKIP ();
        status = action_line46(i, keys, input, token, &cursor, 2);
        continue;
yy14:
        YYSKIP ();
        status = action_line46(i, keys, input, token, &cursor, 3);
        continue;

    }
    if (status == 0) {
        if (cursor != eof) {
            status = 1;
            const long pos = token - input;
            fprintf(stderr, "error: lex_line46: unused input strings left at position %ld\n", pos);
        }
        if (i != keys_count) {
            status = 1;
            fprintf(stderr, "error: lex_line46: unused keys left after %u iterations\n", i);
        }
    }

end:
    free(input);
    free(keys);

    return status;
}

#undef YYCTYPE
#undef YYKEYTYPE
#undef YYPEEK
#undef YYSKIP
#undef YYLESSTHAN
#undef YYFILL

#define YYCTYPE unsigned int
#define YYKEYTYPE unsigned char
#define YYPEEK() *cursor
#define YYSKIP() ++cursor
#define YYLESSTHAN(n) (limit - cursor) < n
#define YYFILL(n) { break; }

static int action_line64
    ( unsigned int i
    , const YYKEYTYPE *keys
    , const YYCTYPE *start
    , const YYCTYPE *token
    , const YYCTYPE **cursor
    , YYKEYTYPE rule_act
    )
{
    const long pos = token - start;
    const long len_act = *cursor - token;
    const long len_exp = (long) keys [3 * i + 1];
    const YYKEYTYPE rule_exp = keys [3 * i + 2];
    if (rule_exp == 255) {
        fprintf
            ( stderr
            , "warning: lex_line64: control flow is undefined for input"
                " at position %ld, rerun re2c with '-W'\n"
            , pos
            );
    }
    if (len_act == len_exp && rule_act == rule_exp) {
        const YYKEYTYPE offset = keys[3 * i];
        *cursor = token + offset;
        return 0;
    } else {
        fprintf
            ( stderr
            , "error: lex_line64: at position %ld (iteration %u):\n"
                "\texpected: match length %ld, rule %u\n"
                "\tactual:   match length %ld, rule %u\n"
            , pos
            , i
            , len_exp
            , rule_exp
            , len_act
            , rule_act
            );
        return 1;
    }
}

int lex_line64()
{
    const size_t padding = 1; /* YYMAXFILL */
    int status = 0;
    size_t input_len = 0;
    size_t keys_count = 0;
    YYCTYPE *input = NULL;
    YYKEYTYPE *keys = NULL;
    const YYCTYPE *cursor = NULL;
    const YYCTYPE *limit = NULL;
    const YYCTYPE *token = NULL;
    const YYCTYPE *eof = NULL;
    unsigned int i = 0;

    input = (YYCTYPE *) read_file
        ("repeat-07_default.gir--skeleton.c.line64.input"
        , sizeof (YYCTYPE)
        , padding
        , &input_len
        );
    if (input == NULL) {
        status = 1;
        goto end;
    }

    for (i = 0; i < input_len; ++i) {
        /* from little-endian to host-endian */
        unsigned char *p = (unsigned char*)&input[i];
        input[i] = p[0] + (p[1] << 8u) + (p[2] << 16u) + (p[3] << 24u);
    }

    keys = (YYKEYTYPE *) read_file
        ("repeat-07_default.gir--skeleton.c.line64.keys"
        , 3 * sizeof (YYKEYTYPE)
        , 0
        , &keys_count
        );
    if (keys == NULL) {
        status = 1;
        goto end;
    }

    cursor = input;
    limit = input + input_len + padding;
    eof = input + input_len;

    for (i = 0; status == 0 && i < keys_count; ++i) {
        token = cursor;
        YYCTYPE yych;

        if (YYLESSTHAN (1)) YYFILL(1);
        yych = YYPEEK ();
        if (yych & ~0xFF) {
        } else {
            static void *yytarget[256] = {
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy4,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy6,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy8,  &&yy10, &&yy12, &&yy14, &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
                &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2
            };
            goto *yytarget[yych];
        }
yy2:
        YYSKIP ();
        status = action_line64(i, keys, input, token, &cursor, 5);
        continue;
yy4:
        YYSKIP ();
        status = action_line64(i, keys, input, token, &cursor, 254);
        continue;
yy6:
        YYSKIP ();
        status = action_line64(i, keys, input, token, &cursor, 4);
        continue;
yy8:
        YYSKIP ();
        status = action_line64(i, keys, input, token, &cursor, 0);
        continue;
yy10:
        YYSKIP ();
        status = action_line64(i, keys, input, token, &cursor, 1);
        continue;
yy12:
        YYSKIP ();
        status = action_line64(i, keys, input, token, &cursor, 2);
        continue;
yy14:
        YYSKIP ();
        status = action_line64(i, keys, input, token, &cursor, 3);
        continue;

    }
    if (status == 0) {
        if (cursor != eof) {
            status = 1;
            const long pos = token - input;
            fprintf(stderr, "error: lex_line64: unused input strings left at position %ld\n", pos);
        }
        if (i != keys_count) {
            status = 1;
            fprintf(stderr, "error: lex_line64: unused keys left after %u iterations\n", i);
        }
    }

end:
    free(input);
    free(keys);

    return status;
}

#undef YYCTYPE
#undef YYKEYTYPE
#undef YYPEEK
#undef YYSKIP
#undef YYLESSTHAN
#undef YYFILL

int main()
{
    if(lex_line28() != 0) {
        return 1;
    }
    if(lex_line46() != 0) {
        return 1;
    }
    if(lex_line64() != 0) {
        return 1;
    }
    return 0;
}
 	
 !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`efghijklmnopqrstuvwxyz{|}~��������������������������������������������������������������������������������������������������������������������������������abcd������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������  	 !"#$%&'()*+,-./023456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`efghijklmnopqrstuvwxyz{|}~��������������������������������������������������������������������������������������������������������������������������������
1abcd�           	                        ! " # $ % & ' ( ) * + , - . / 0 1 3 4 5 6 7 8 9 : ; < = > ? @ A B C D E F G H I J K L M N O P Q R S T U V W X Y Z [ \ ] ^ _ ` e eeeeeeeee	e
eeeeeeeeeeeeeeeeeeeeee e!e"e#e$e%e&e'e(e)e*e+e,e-e.e/e0e1e2e3e4e5e6e7e8e9e:e;e<e=e>e?e@eAeBeCeDeEeFeGeHeIeJeKeLeMeNeOePeQeReSeTeUeVeWeXeYeZe[e\e]e^e_e`eaebecedeeefegeheiejekelemeneoepeqereseteuevewexeyeze{e|e}e~ee�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e�e���
 2 a b c d �                             	                                                                      !   "   #   $   %   &   '   (   )   *   +   ,   -   .   /   0   1   2   4   5   6   7   8   9   :   ;   <   =   >   ?   @   A   B   C   D   E   F   G   H   I   J   K   L   M   N   O   P   Q   R   S   T   U   V   W   X   Y   Z   [   \   ]   ^   _   `   e   e  e"  e3  eD  eU  ef  ew  e�  e�  e�  e�  e�  e�  e�  e�  e e! e2 eC eT ee ev e� e� e� e� e� e� e� e� e e  e1 eB eS ed eu e� e� e� e� e� e� e� e� e e e0 eA eR ec et e� e� e� e� e� e� e� e� e e e/ e@ eQ eb es e� e� e� e� e� e� e� e� e e e. e? eP ea er e� e� e� e� e� e� e� e� e e e- e> eO e` eq e� e� e� e� e� e� e� e� e
 e e, e= eN e_ ep e� e� e� e� e� e� e� e� e	 e e+ e< eM e^ eo e� e� e� e� e� e� e� e� e	 e	 e*	 e;	 eL	 e]	 en	 e	 e�	 e�	 e�	 e�	 e�	 e�	 e�	 e
 e
 e)
 e:
 eK
 e\
 em
 e~
 e�
 e�
 e�
 e�
 e�
 e�
 e�
 e e e( e9 eJ e[ el e} e� e� e� e� e� e� e� e e e' e8 eI eZ ek e| e� e� e� e� e� e� e� e e e& e7 eH eY ej e{ e� e� e� e� e� e� e� e e e% e6 eG eX ei ez e� e� e� e� e� e� e� e e e$ e5 eF eW eh ey e� e� e� e� e� e� e� e e e# e4 eE eV eg ex e� e� e� e� e� e� e� �� 
   3   a   b   c   d   � 