// date:17.4.6
// author: linyang <942510346@qq.com>

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int c;
	while((c = getchar()) != EOF) {
		if (c != ' ' && c!= '\t') {
			putchar(c);
		}
	}

	return 0;
}