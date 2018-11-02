/*
Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print
the length of arbitrary long input lines, and as much as possible of the text.
*/

/* #include <stdio.h> */
#ifndef EOF
# define EOF (-1)
#endif
#define MAXLINE 1000 /* max input line size */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main(int argc, char const *argv[])
{
    int len;				/* current line length */
    int max;				/* maximum length seen so far */
    char line[MAXLINE];		/* current input line */
    char longest[MAXLINE];	/* longest line saved here */

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0) {
    	printf("%d, %s\n", len, line);
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {			/* there was a line */
		printf("%s", longest);
	}

	return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
	int c, i, j;

	j = 0;
	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i < lim-2) {
			s[j] = c; /* line still in boundries */
			++j;
		}
		if (c == '\n') {
			s[j] = c;
			++j;
			++i;
		}
		s[j] = '\0';
	}
	return i;
}

/* copy: copy 'from' into 'to': assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while (to[i] = from[i] != '\0') {
		++i;
	}
}


/*
$ gcc -ansi -pedantic 1-16.c -o 1-16
$ ./1-16.exe < 1-16.c

*/