// date:17.6.27
// author: aquanox@163.com



#include <stdio.h>
#include <string.h>

#define MAXLINES 5000	//max #line to be stored
#define MAXLINE 1000	//max length of any input line

char *lineptr[MAXLINES];

int readlines(char* lineptr[], int nlines, char* p);
void writelines(char* lineptr[], int nlines);
void qsort(char* lineptr[], int left, int right);
int getline(char *, int);
char *alloc(int);


int main(int argc, char const *argv[])
{
	int nlines;
	char line[MAXLINE] = { 0 };

	if ((nline = readlines(lineptr, MAXLINE, line)) >= 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}

}

int readlines(char lines[][MAXLINE], int maxlines)
{
	int len, nlines;
	

	nlines = 0;
	while((len = getline(lines[nlines], MAXLINE)) > 0) {
		if (nlines >= maxlines)
			return -1;
		else {
			lines[nlines++][len-1] = '\0'; //delete newline;

		}
	}


	return nlines;
}






