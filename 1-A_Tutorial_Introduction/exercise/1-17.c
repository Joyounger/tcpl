// date:17.4.7
// author: linyang <942510346@qq.com>


/*
Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int c;
	char line[81];
	int count = 0;
	int i;

	while ((c = getchar()) != EOF) {
		if (c != '\n' && count < 80) {
			line[count] = c;
			count++;
		} else if (c == '\n') {
			if (count < 80) {
				for (i = 0; i < count; i++) {
					printf("%c", line[i]);
				}
				printf("\n");
			}
			count = 0;
		}
	}

	return 0;
}


/*
kolya@asus ~/src/tcpl/1-A_Tutorial_Introduction/exercise $ ./1-17
11111111111111111111111111111111111111111111111111111111111111111111111111111111  // 81 chars no output
2222222222222222222222222222222222222222222222222222222222222222222222222222222	  // 80 chars
2222222222222222222222222222222222222222222222222222222222222222222222222222222
*/