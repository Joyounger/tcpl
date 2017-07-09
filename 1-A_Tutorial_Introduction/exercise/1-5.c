// date:17.4.6
// author: linyang <942510346@qq.com>


/*
Exercise 1-5. Modify the temperature conversion program to print the table in reverse order, that is, from 300
degrees to 0.
*/

#include <stdio.h>


int main(int argc, char const *argv[])
{
	int fahr;

	for (fahr = 300; fahr >= 0; fahr -= 20) {
		printf("%3d %6.1f\n", fahr, (5.0 / 9.0)*(fahr - 32));
	}

	return 0;
}