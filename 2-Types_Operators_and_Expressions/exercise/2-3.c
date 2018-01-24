// date:17.4.9
// author: linyang <942510346@qq.com>

/*
Exercise 2-3. Write a function htoi(s), which converts a string of hexadecimal digits (including an
optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A
through F.
*/
#include <stdio.h>

int htoi(char hex[])
{
	int i = 0;
	long int sum = 0;
	int len = 0;
	while(hex[i] != '\0') {
		len++;
		i++;
	}

	for(i = 0; i < len; i++) {
		if (hex[i] >= '0' && hex[i]<= '9')
			hex[i] -= '0';
		if (hex[i] >= 'A' && hex[i]<= 'F')
			hex[i] -= 55;
		if (hex[i] >= 'a' && hex[i]<= 'f')
			hex[i] -= 87;
		
		sum = sum*16 + hex[i];

	}


	return sum;
}

int main()
{
	char hex[] = {'a', '8', 'D', '\0'};

	int sum = htoi(hex);

	printf("sum:%d\n", sum);

	return 0;
}
