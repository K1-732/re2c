// Code generated by re2c, DO NOT EDIT.
//line "go/fill/02_fill.re":1
//go:generate re2go $INPUT -o $OUTPUT
package main

import (
	"os"
	"strings"
)

//line "go/fill/02_fill.go":12
var YYMAXFILL int = 1
//line "go/fill/02_fill.re":9

const BUFSIZE int = 4096

type Input struct {
	file   *os.File
	data   []byte
	cursor int
	token  int
	limit  int
	eof    bool
}

func fill(in *Input, need int) int {
	if in.eof { return -1 } // unexpected EOF

	// Error: lexeme too long. In real life can reallocate a larger buffer.
	if in.token < need { return -2 }

	// Shift buffer contents (discard everything up to the current token).
	copy(in.data[0:], in.data[in.token:in.limit])
	in.cursor -= in.token
	in.limit -= in.token
	in.token = 0

	// Fill free space at the end of buffer with new data from file.
	n, _ := in.file.Read(in.data[in.limit:BUFSIZE])
	in.limit += n

	// If read less than expected, this is end of input => add zero padding
	// so that the lexer can access characters at the end of buffer.
	if in.limit < BUFSIZE {
		in.eof = true
		for i := 0; i < YYMAXFILL; i += 1 { in.data[in.limit+i] = 0 }
		in.limit += YYMAXFILL
	}

	return 0
}

func lex(in *Input) int {
	count := 0
	for {
		in.token = in.cursor
	
//line "go/fill/02_fill.go":59
{
	var yych byte
	if (in.limit-in.cursor < 1) {
		if r := fill(in, 1); r != 0 { return r }
	}
	yych = in.data[in.cursor]
	switch (yych) {
	case 0x00:
		goto yy1
	case ' ':
		goto yy3
	case '\'':
		goto yy5
	default:
		goto yy2
	}
yy1:
	in.cursor += 1
//line "go/fill/02_fill.re":59
	{
			// Check that it is the sentinel, not some unexpected null.
			if in.token == in.limit - YYMAXFILL { return count } else { return -1 }
		}
//line "go/fill/02_fill.go":83
yy2:
	in.cursor += 1
//line "go/fill/02_fill.re":65
	{ return -1 }
//line "go/fill/02_fill.go":88
yy3:
	in.cursor += 1
	if (in.limit-in.cursor < 1) {
		if r := fill(in, 1); r != 0 { return r }
	}
	yych = in.data[in.cursor]
	switch (yych) {
	case ' ':
		goto yy3
	default:
		goto yy4
	}
yy4:
//line "go/fill/02_fill.re":64
	{ continue }
//line "go/fill/02_fill.go":104
yy5:
	in.cursor += 1
	if (in.limit-in.cursor < 1) {
		if r := fill(in, 1); r != 0 { return r }
	}
	yych = in.data[in.cursor]
	switch (yych) {
	case '\'':
		goto yy6
	case '\\':
		goto yy7
	default:
		goto yy5
	}
yy6:
	in.cursor += 1
//line "go/fill/02_fill.re":63
	{ count += 1; continue }
//line "go/fill/02_fill.go":123
yy7:
	in.cursor += 1
	if (in.limit-in.cursor < 1) {
		if r := fill(in, 1); r != 0 { return r }
	}
	goto yy5
}
//line "go/fill/02_fill.re":66
}
}

func main() () {
	fname := "input"
	content := "'qu\000tes' 'are' 'fine: \\'' ";

	// Prepare input file: a few times the size of the buffer, containing
	// strings with zeroes and escaped quotes.
	f, _ := os.Create(fname)
	f.WriteString(strings.Repeat(content, BUFSIZE))
	f.Seek(0, 0)
	count := 3 * BUFSIZE // number of quoted strings written to file

	// Prepare lexer state and fill buffer.
	in := &Input{
		file:   f,
		data:   make([]byte, BUFSIZE+YYMAXFILL),
		cursor: BUFSIZE,
		token:  BUFSIZE,
		limit:  BUFSIZE,
		eof:    false,
	}
	fill(in, 1)

	// Run the lexer.
	if lex(in) != count { panic("error"); }

	// Cleanup: remove input file.
	f.Close();
	os.Remove(fname);
}
