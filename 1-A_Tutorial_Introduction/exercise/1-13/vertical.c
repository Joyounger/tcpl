/*
Exercise 1-13. Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
*/


#include <stdio.h>

#define MAXHIST 15 /* max length of histogram */
#define MAXWORD 11 /* max length of a word */
#define IN      1  /* inside a word */
#define OUT		0  /* outside a word */

/* print vertical histogram */
int main(int argc, char const *argv[])
{
	int c, i, j, nc, state;

	int maxvalue;    /* maximum value for wl[] */
	int ovflow; 	 /* number of overflow words */
	int wl[MAXWORD]; /* word length counters */
	state = OUT;
	nc = 0;          /* number of chars in a word */
	ovflow = 0;      /* number of words >= MAXWORD */
	for (i = 0; i < MAXWORD; ++i) {
		wl[i] = 0;
	}
	while((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			if (nc > 0) {
				if (nc < MAXWORD) {
					++wl[nc];
				} else {
					++ovflow;
				}
			}
			nc = 0;
		} else if (state == OUT) {
			state = IN;
			nc = 1; /* beginning of a new word */
		} else {
			++nc;  /* inside a word */
		}
	}
    maxvalue = 0;
    for (i = 1; i < MAXWORD; ++i) {
        if (wl[i] > maxvalue) {
            maxvalue = wl[i];
        }
    }
    for (i = MAXHIST; i > 0; --i) {
        for (j = 1; j < MAXWORD; ++j) {
        	if (wl[j] * MAXHIST / maxvalue >= i) {
        		printf(" * ");
        	} else {
        		printf("   ");
        	}
        }
        putchar('\n');
    }
    for (i = 1; i < MAXWORD; ++i) {
    	printf("%4d ", i);
    }
    putchar('\n');
    for (i = 1; i < MAXWORD; ++i) {
    	printf("%4d ", wl[i]);
    }
    putchar('\n');
    if (ovflow > 0) {
        printf("There are %d words >= %d\n", ovflow, MAXWORD);
    }

}


/*
$ gcc -ansi -pedantic vertical.c -o vertical

$ ./vertical.exe < vertical.c
    *
    *
    *
 *  *
 *  *
 *  *
 *  *
 *  *
 *  *
 *  *
 *  *
 *  *  *
 *  *  *  *
 *  *  *  *  *        *
 *  *  *  *  *  *  *  *
   1    2    3    4    5    6    7    8    9   10
 105  124   41   26   19   13   15   19    8    6
There are 9 words >= 11

*/