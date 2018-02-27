// date:17.6.23
// author: linyang <942510346@qq.com>

/*
Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the string s in place.
*/


#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char* reverse(char* s)
{
	int len = strlen(s);
	char* ret = (char *)malloc(len + 1);
	static int i = 0;
	static int j = 0;

	if (s[i++]) {
		reverse(&s[i]);
	}
	printf("%c\n", s[i]);
	//ret[j++] = s[i];
	//ret[j] = '\0';
	return ret;

}



int main(int argc, char const *argv[])
{
	char* s = "123456abd";
	printf("%s reverse is %s\n", s, reverse(s));

	return 0;
}