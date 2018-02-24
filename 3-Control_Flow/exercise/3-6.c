// date:17.6.16
// author: linyang <942510346@qq.com>


/*
Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into a base b character
representation in the string s. In particular, itob(n,s,16) formats s as a hexadecimal integer in s.
*/

#include <stdio.h>
#include <string.h>

void reverse(char* s)
{
	int len = strlen(s);

	int i;
	int temp;
	for (i = 0; i < len/2 ; i++) {
		temp = s[i];
		s[i] = s[len - i -1];
		s[len - i -1] = temp;
	}
}

void itoa(int n, char s[], int width)
{
	int i = 0;
	int flag = 0;
	int digits = 0;
	int j;
	if (n < 0) {
		n = n * -1;
		flag = 1;
	}

	do {
		s[i++] = n % 10 + '0';
		digits++;
	} while (( n /= 10) > 0);

	if (flag == 1) {
		s[i++] = '-';
		digits++;
	}
	for (j = 0; j < width - digits; j++) {
		s[i++] = '0';
	}

	s[i] = '\0';

	reverse(s);
}

int main(int argc, char const *argv[])
{
	int a = 123;
	int b = -123;
	char s[100];
	int width = 5;

	itoa(a, s, width);
	printf("in %d width, %d string is %s\n", width, a, s);
	itoa(b, s, width);
	printf("in %d width, %d string is %s\n", width, b, s);

	return 0;
}


/*
kolya@asus ~/src/tcpl/3-Control_Flow/exercise $ ./3-6
in 5 width, 123 string is 00123
in 5 width, -123 string is 0-123
*/
