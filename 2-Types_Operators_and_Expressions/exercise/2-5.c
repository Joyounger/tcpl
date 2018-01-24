// date:17.5.10
// author: linyang <942510346@qq.com>

/*
Exercise 2-5. Write the function any(s1,s2), which returns the first location in a string s1 where any
character from the string s2 occurs, or -1 if s1 contains no characters from s2. (The standard library
function strpbrk does the same job but returns a pointer to the location.)
*/

#include <stdio.h>

int any(char s1[], char s2[])
{
	int i,j;
	i = j = 0;

	while(s2[j] != '\0') {
		if(s1[i] == s2[j]) {
			return i;
		} else {
			i++;
			if (s1[i] == '\0') {
				i = 0;
				j++;
				continue;
			}
		}
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	char* s1 = "adcdzfg";
	char* s2 = "xzy";
	int loc = any(s1, s2);
	printf("the location is %d\n", loc);

	return 0;
}