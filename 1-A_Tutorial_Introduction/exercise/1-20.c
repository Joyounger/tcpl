/*
Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter?
*/

#include <stdio.h>

#define TABINC 8 /* tab incremental */

/* replace tabs with the proper number of blanks */
int main(int argc, char const *argv[])
{
	int c, nb, pos;

	nb = 0;    /* number of blanks necessary */
	pos = 1;   /* position of character in line */
	while ((c = getchar()) != EOF) {
		if (c == '\t') { /* position of char in line */
            nb = TABINC - (pos - 1) % TABINC;
            while(nb > 0) {
                putchar(' ');
                ++pos;
                --nb;
            }
		} else if (c == '\n') { /* newline character */
            putchar(c);
            pos = 1;
        } else {                /* all other character */
            putchar(c);
            ++pos;
        }
	}

	return 0;
}

