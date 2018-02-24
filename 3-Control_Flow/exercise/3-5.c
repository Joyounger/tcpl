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

void itob(int n, char* s, int b)
{
	int i, flag;
	i = 0;
	flag = 0;

	if (n < 0) {
		flag = 1;
		n = n * -1;
	}

	do {
		int temp = n % b + '0';
		if(temp > '9' ) {
			s[i++] = 'A' + (temp - '9' - 1);
		} else {
			s[i++] = n % b + '0';
		}
	} while ( (n /= b) > 0);

	if (flag) {
		s[i++] = '-';
	}
	s[i] = '\0';


	reverse(s);
}

int main(int argc, char const *argv[])
{
	int a = -1024;
	char s[100];
	int base = 16;
	itob(a, s, base);
	printf("%d base %d string is %s\n", a, base, s);
	return 0;
}

/*
multi-character character constant
*/