// date:17.4.6
// author: linyang <942510346@qq.com>

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int c;
	int has_newline = 0;
	while((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (has_newline == 0) {
				putchar('\n');
				has_newline = 1;
			}
		} else {
			putchar(c);
			has_newline = 0;
		}
	}

	return 0;
}


/*
kolya@asus ~/src/tcpl/1-A_Tutorial_Introduction/exercise $ ./1-12
abc 	wwe 			rrr
abc
wwe
rrr
*/