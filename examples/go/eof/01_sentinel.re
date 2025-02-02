//go:generate re2go $INPUT -o $OUTPUT
package main

// Expect a null-terminated string.
func lex(str string) int {
	var cursor int
	count := 0

	for {/*!re2c
		re2c:yyfill:enable = 0;
		re2c:define:YYCTYPE = byte;
		re2c:define:YYPEEK = "str[cursor]";
		re2c:define:YYSKIP = "cursor += 1";

		*      { return -1 }
		[\x00] { return count }
		[a-z]+ { count += 1; continue }
		[ ]+   { continue }
	*/}
}

func main() {
	assert_eq := func(x, y int) { if x != y { panic("error") } }
	assert_eq(lex("\000"), 0)
	assert_eq(lex("one two three\000"), 3)
	assert_eq(lex("f0ur\000"), -1)
}
