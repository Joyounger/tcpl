#include <stdio.h>
#include <ctype.h>


#define MAXLINE 100 /* max number of chars in one time */
#define OCTLEN    6 /* length of an octal */

/* print arbitrary input in a sensible way */
int main(int argc, char const *argv[])
{
	int c, pos;
	int inc(int pos, int n);

	pos = 0;
	while((c = getchar()) != EOF) {
		if (iscntrl(c) || c == ' ') {
			/* non-graphic  */
			pos = inc(pos, OCTLEN);
			printf("\\%03o \n", c);
			/* newline character? */
			if (c == '\n') {
				pos = 0;
				putchar('\n');
			}
		} else {
			/* graphic character */
			pos = inc(pos, 1);
			putchar(c);
		}
	}

	return 0;
}

/* inc: incremental position counter for output */
int inc(int pos, int n)
{
	if (pos + n < MAXLINE) {
		return pos+n;
	} else {
		putchar('\n');
		return n;
	}
}
