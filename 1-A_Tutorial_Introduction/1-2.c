// date:17.4.6
// author: linyang <942510346@qq.com>

#include <stdio.h>

int main(int argc, char const *argv[])
{
	printf("Audible or visual alert. \a\n");
	printf("Form feed. \f\n");
	printf("This escape, \r, moves the active position to the initial position of the current line.\n");
	printf("Vertical tab \v is tricky, as its behaviour is unspecified under certain conditions.\n");

	return 0;
}


/*
kolya@asus ~/src/tcpl/1-A_Tutorial_Introduction $ ./1-2 
Audible or visual alert. 
Form feed. 

, moves the active position to the initial position of the current line.
Vertical tab 
              is tricky, as its behaviour is unspecified under certain conditions.
*/