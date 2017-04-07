// date:17.4.6
// author: linyang <942510346@qq.com>

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int c;
	int lines = 0;
	int blanks = 0;
	int tabs = 0;

	while((c = getchar()) != EOF) {
		if (c == '\n') {
			lines++;
		} else if (c == '\t') {
			tabs++;
		} else if (c == ' ') {
			blanks++;
		}
	}
	printf("%d blanks, %d tabs, %d lines\n", blanks, tabs, lines);

	return 0;
}