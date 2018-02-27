// date:17.6.23
// author: linyang <942510346@qq.com>


/*
Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer
into a string by calling a recursive routine.
*/

#include <stdio.h>

void itoa(int n)
{
	if (n < 0) {
		printf("-");
		n = -1 * n;
	}

	
	if ( n / 10) {
		
		itoa(n / 10);
	}
	putchar(n % 10 + '0');

}

int main(int argc, char const *argv[])
{
	int n1 = 123;
	int n2 = -123;

	itoa(n1); printf("\n");
	itoa(n2); printf("\n");

	return 0;
}


/*
kolya@asus ~/src/tcpl/4-Functions_and_Program_Structure/exercise $ ./4-12
123
-123
*/