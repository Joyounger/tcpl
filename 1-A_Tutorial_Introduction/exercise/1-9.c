// date:17.4.6
// author: linyang <942510346@qq.com>

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int c;
	int meetblank = 0;
	while ((c = getchar()) != EOF) {
		if (c != ' ') {
			putchar(c);
			meetblank = 0;
		} else {
			if (meetblank == 0) {
				putchar(' ');
				meetblank = 1;
			} else {
				continue;
			}
		}
	}

	return 0;
}



/*
kolya@asus ~/src/tcpl/1-A_Tutorial_Introduction $ ./1-9
    123
 123
wwwwww123 344  55565
wwwwww123 344 55565
wwwwww         ffffffffff
wwwwww ffffffffff
*/