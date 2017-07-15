//date: 17.7.2

#include <stdio.h>

#define MAXLINE 1000	//max input line size

int max;				// maximum length seen so far
char line[MAXLINE];		// current input line
char longest[MAXLINE];	// longest line saved here

int get_line(void);
void copy(void);



//print longest input line; specialized version
int main(int argc, char const *argv[])
{
	int len;
	extern int max;
	extern char  longest[];

	max = 0;
	while ((len = get_line()) > 0) {
		if (len > max) {
			max = len;
			copy();
		}
	}
	if (max > 0) {		// there was a line
		printf("%s\n", longest);
	}


	return 0;
}

// getline: specialzed version
int get_line(void)
{
	int c, i;
	extern char line[];

	for (i = 0; i < MAXLINE - 1
		&& (c=getchar()) != EOF && c != '\n'; ++i) {
		line[i] = c;
	}

	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}


// copy: specialzed version
void copy(void)
{
	int i;
	extern char line[], longest[];

	i = 0;
	while ((longest[i] = line[i]) != '\0') {
		++i;
	}
}
