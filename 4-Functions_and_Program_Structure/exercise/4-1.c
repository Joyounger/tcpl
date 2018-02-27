// date:17.6.17
// author: linyang <942510346@qq.com>



/*
Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost occurrence of
t in s, or -1 if there is none.
*/

#include <stdio.h>
#include <string.h>

int strindex(char* s, char* t)
{
	int i,j;
	int slen = strlen(s);
	int tlen = strlen(t);
	int count = 0;
	for(i = slen-1, j = tlen-1; i >=0 && j >= 0; ) {
		while(s[i] == t[j] && (i >=0 && j >= 0)) {
			i--; j--;
			count++;
		}

		if (count == tlen) {
			return (i+1);
		}

		i--; j = tlen - 1;
		count = 0;
	}

	return -1;
}


int main(int argc, char const *argv[])
{
	char* s1 = "Hello world"; // 7
	char* s2 = "This string is littered with iiiis"; // 32
	char* s3 = "No 'see' letters in here"; // -1

	printf("o in s1 rightmost is %d\n", strindex(s1, "o"));
	printf("i in s2 rightmost is %d\n", strindex(s2, "i"));
	printf("c in s3 rightmost is %d\n", strindex(s3, "c"));

	return 0;
}


/*
kolya@asus ~/src/tcpl/4-Functions_and_Program_Structure/exercise $ ./4-1 
o in s1 rightmost is 7
i in s2 rightmost is 32
c in s3 rightmost is -1
*/