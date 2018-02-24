// date:17.6.16
// author: linyang <942510346@qq.com>


/*
Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into visible
escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the other
direction as well, converting escape sequences into the real characters
*/

#include <stdio.h>

void escape(char* s, char* t);

int main(int argc, char const *argv[])
{
	char s[100] = { 0 };
	char *t = "\aHello,\n\tWorld! Mistakee\b was \"Extra'e'\"!\n";
	escape(s, t);
	printf("s--%s\n", s);

	return 0;
}


void escape(char* s, char* t)
{
    char* p = s;
    char* q = t;
    while (*q) {
        switch (*q) {
            case '\x09':	// HT (horizontal tab)
                *p = '\\';
                p++;
                *p = 't';
                break;
            case '\x0a':	// LF (NL line feed, new line)
                *p = '\\';
                p++;
                *p = 'n';
                break;
            case '\x0b':	// VT (vertical tab)
                *p = '\\';
                p++;
                *p = 'v';
                break;
            case '\x0c':	// FF (NP form feed, new page)
                *p = '\\';
                p++;
                *p = 'f';
                break;
            case '\x0d':	// CR (carriage return)
                *p = '\\';
                p++;
                *p = 'r';
                break;
            default :
                *p = *q;
                break;
        }
        p++; q++;
    }
    *p = '\0';
}

/*
s--Hello,\n\tWorld! Mistake was "Extra'e'"!\n
*/
