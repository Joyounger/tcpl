// date:17.6.25
// author: linyang <942510346@qq.com>


/*
Exercise 5-4. Write the function strend(s,t), which returns 1 if the string t occurs at the end of the
string s, and zero otherwise.
*/

#include <stdio.h>

int strend(char* s, char* t)
{
	int slen = 1;
	while(*s != '\0') {
		s++;
		slen++;
	}

	int tlen = 1;
	while(*t != '\0') {
		t++;
		tlen++;
	}

	while(*t == *s) {
		s--;
		t--;
		slen--;
		tlen--;	
	}

	if (tlen == 0 && slen >= 0) {
		return 1;
	} else {
		return 0;
	}

}


int main(int argc, char const *argv[])
{
	char *s1 = "some really long string.";
	char *s2 = "ng.";
	char *s3 = "ng";
	if(strend(s1,s2)) {
		printf("The string (%s) has (%s) at the end.\n", s1, s2);
	} else {
		printf("The string (%s) doesn't have (%s) at the end.\n", s1, s2);
	}

	if(strend(s1,s3)) {
		printf("The string (%s) has (%s) at the end.\n", s1, s3);
	} else {
		printf("The string (%s) doesn't have (%s) at the end.\n", s1, s3);
	}
	

	return 0;
}


/*
kolya@asus ~/src/tcpl/5_Pointers_and_Arrays/exercise $ ./5-4
The string (some really long string.) has (ng.) at the end.
The string (some really long string.) doesn't have (ng) at the end.
*/