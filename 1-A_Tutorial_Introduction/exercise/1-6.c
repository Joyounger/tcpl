// date:17.4.6
// author: linyang <942510346@qq.com>


/*
Exercsise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("input ctrl + z in win or ctrl + d in linux\n");
	printf("getchar() != EOF is %d\n", (getchar() != EOF));
	printf("input some characters\n");
	printf("getchar() != EOF is %d\n", (getchar() != EOF));
	return 0;
}