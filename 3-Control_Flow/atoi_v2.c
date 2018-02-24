// date:17.6.17
// author: linyang <942510346@qq.com>

#include <stdio.h>
#include <ctype.h>

int atoi(char s[])
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++)
		;

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (n = 0; isdigit(s[i]); i++)
		n = n * 10 + (s[i] - '0');
	return sign * n;
}


int main(int argc, char const *argv[])
{
	char* s = "+128";
	printf("string %s equals to %d\n", s, atoi(s));
	char* s2 = "-128";
	printf("string %s equals to %d\n", s2, atoi(s2));

	return 0;
}



