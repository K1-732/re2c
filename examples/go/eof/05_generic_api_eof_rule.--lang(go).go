// Code generated by re2c, DO NOT EDIT.
//line "go/eof/05_generic_api_eof_rule.--lang(go).re":1
//go:generate "${RE2C}" --lang go "${GOFILE}" -o example_test.go
package main

import "testing"

// Returns "fake" terminating null if cursor has reached limit.
func peek(str string, cursor int, limit int) byte {
	if cursor >= limit {
		return 0 // fake null
	} else {
		return str[cursor]
	}
}

// Expects a string without terminating null.
func lex(str string) int {
	var cursor, marker int
	limit := len(str)
	count := 0
loop:
	
//line "go/eof/05_generic_api_eof_rule.--lang(go).go":25
{
	var yych byte
	yych = peek(str, cursor, limit)
	switch (yych) {
	case ' ':
		goto yy4
	case '\'':
		goto yy7
	default:
		if (cursor >= limit) {
			goto yyeof1
		}
		goto yy2
	}
yy2:
	cursor += 1
yy3:
//line "go/eof/05_generic_api_eof_rule.--lang(go).re":31
	{ return -1 }
//line "go/eof/05_generic_api_eof_rule.--lang(go).go":45
yy4:
	cursor += 1
	yych = peek(str, cursor, limit)
	switch (yych) {
	case ' ':
		goto yy4
	default:
		goto yy6
	}
yy6:
//line "go/eof/05_generic_api_eof_rule.--lang(go).re":34
	{ goto loop }
//line "go/eof/05_generic_api_eof_rule.--lang(go).go":58
yy7:
	cursor += 1
	marker = cursor
	yych = peek(str, cursor, limit)
	if (yych >= 0x01) {
		goto yy9
	}
	if (cursor >= limit) {
		goto yy3
	}
yy8:
	cursor += 1
	yych = peek(str, cursor, limit)
yy9:
	switch (yych) {
	case '\'':
		goto yy10
	case '\\':
		goto yy12
	default:
		if (cursor >= limit) {
			goto yy13
		}
		goto yy8
	}
yy10:
	cursor += 1
//line "go/eof/05_generic_api_eof_rule.--lang(go).re":33
	{ count += 1; goto loop }
//line "go/eof/05_generic_api_eof_rule.--lang(go).go":88
yy12:
	cursor += 1
	yych = peek(str, cursor, limit)
	if (yych <= 0x00) {
		if (cursor >= limit) {
			goto yy13
		}
		goto yy8
	}
	goto yy8
yy13:
	cursor = marker
	goto yy3
yyeof1:
//line "go/eof/05_generic_api_eof_rule.--lang(go).re":32
	{ return count }
//line "go/eof/05_generic_api_eof_rule.--lang(go).go":105
}
//line "go/eof/05_generic_api_eof_rule.--lang(go).re":35

}

func TestLex(t *testing.T) {
	var tests = []struct {
		res int
		str string
	}{
		{0, ""},
		{3, "'qu\000tes' 'are' 'fine: \\'' "},
		{-1, "'unterminated\\'"},
	}

	for _, x := range tests {
		t.Run(x.str, func(t *testing.T) {
			res := lex(x.str)
			if res != x.res {
				t.Errorf("got %d, want %d", res, x.res)
			}
		})
	}
}
