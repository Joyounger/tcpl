// date:17.4.9
// author: linyang <942510346@qq.com>

/*
Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.
*/


#include <stdio.h>

int main(int argc, char const *argv[])
{
	//for (i = 0; i < lim -1 && (c = getchar()) != '\n' && c != EOF; ++i)
	//	s[i] = c;

	int i = 0, c;
	int lim = 100;
	char s[100];

	while (i < lim - 1) {
		c = getchar();
		if (c != '\n') {
			if (c != EOF) {
				s[i] = c;
				i++;
			} else {
				break;
			}
		} else {
			break;
		}
	}

	return 0;
}