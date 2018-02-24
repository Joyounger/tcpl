// date:17.6.17
// author: linyang <942510346@qq.com>


/*
Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1
into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be
prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken
literally.
*/

#include <string.h>
#include <stdio.h>
#include <ctype.h>

void expand2(char* s1, char* s2)
{
	int len = strlen(s1);

	int i,j,k;

	for (i = 0; i < len-3; i++) {
		for (j = 0; j < len-2; j++) {
			for (k = 0; k < len-1; k++) {
				if (s1[j] == '-' && islower(s1[i]) && islower(s1[k])) {
					for (*s2 = s1[i]; *s2 <= s1[k]; ) {
						s2++; *s2 = ++s1[i];
					}
				} else {
					//*s2 = s1[i];
					//s2++;
					//*s2 = s1[j];
					//s2++;
					//*s2 = s1[k];
					//s2++;
				}
			}
		}
	}

	*s2 = '\0';
}

void expand(char* s1, char* s2)
{
	static char upper_alph[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	static char lower_alph[27] = "abcdefghijklmnopqrstuvwxyz";
	static char digits[11] = "0123456789";

	int i = 0, j = 0;
	char* start;
	char* end;

	while(s1[i]) {
		switch (s1[i]) {
			case '-':
				if(i== 0 || s1[i+1] == '\0') {
					s2[j++] = s1[i];
					i++;
					break;
				} else {
					if(islower(s1[i-1]) && islower(s1[i+1]))
						;
					else if(isupper(s1[i-1]) && isupper(s1[i+1]))
						;
					else if(isdigit(s1[i-1]) && isdigit(s1[i+1]))
						;
					else {

						break;
					}
					for(s2[j]= )
				}

		}
	}
}


int main(int argc, char const *argv[])
{
	char * s1 = "a-z1234";
	char s2[100];
	printf("s1--%s\n", s1);
	expand(s1, s2);
	printf("expand s1--%s\n", s2);

	return 0;
}