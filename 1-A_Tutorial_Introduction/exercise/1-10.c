// date:17.4.6
// author: linyang <942510346@qq.com>


/*
Exercise 1-10. Write a program to copy its input to its output, replacing each tab by \t, each backspace by
\b, and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way.
*/


#include <stdio.h>

int main(int argc, char const *argv[])
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			putchar('\\');
			putchar('t');
		} else if (c == '\b') {
			putchar('\\');
			putchar('b');
		} else if (c == '\\') {
			putchar('\\');
			putchar('\\');
		} else {
			putchar(c);
		}
	}

	return 0;
}