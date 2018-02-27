// date:17.6.25
// author: linyang <942510346@qq.com>


/*
Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2: strcat(s,t)
copies the string t to the end of s.
*/

#include <stdio.h>


// a pointer version of strcat
void strcat(char* s, char* t) 
{
	while (*s != '\0') {
		s++;
	}

	while(*t != '\0') {
		*s = *t;
		s++;
		t++;
	}

	*s = '\0';
}


int main(int argc, char const *argv[])
{
	/*error :can't use char* s = "123" and char* t = "abcd" because
	pmessage is a pointer, initialized to point to a string constant; the pointer may
	subsequently be modified to point elsewhere, but the result is undefined if you try to modify the string
	contents.*/
	char s[] = "123"; 
	char t[] = "abcd";
	printf("copy string %s to the end of string %s is string", t, s);
	strcat(s, t);
	printf(" %s\n", s);
	
	

	return 0;
}


/*
/*error :can't use char* s = "123" and char* t = "abcd" because
pmessage is a pointer, initialized to point to a string constant; the pointer may
subsequently be modified to point elsewhere, but the result is undefined if you try to modify the string
contents.*/
*/