// date:17.4.6
// author: linyang <942510346@qq.com>

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