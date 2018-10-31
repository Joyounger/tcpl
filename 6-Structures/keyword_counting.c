#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
usage: 
$ ./keyword_counting.exe < /path/to/textfile
cat /path/to/textfile | ./keyword_counting.exe
*/
#define MAXWORD 100
#define BUFSIZE 100

struct key {
    char* word;
    int count;
} keytab[] = {
    { "auto",     0 },
    { "break",    0 },
    { "case",     0 },
    { "char",     0 },
    { "const",    0 },
    { "continue", 0 },
    { "default",  0 },
    { "do",       0 },
    { "double",   0 },
    { "else",     0 },
    { "enum",     0 },
    { "extern",   0 },
    { "float",    0 },
    { "for",      0 },
    { "goto",     0 },
    { "if",       0 },
    { "int",      0 },
    { "long",     0 },
    { "register", 0 },
    { "return",   0 },
    { "short",    0 },
    { "signed",   0 },
    { "sizeof",   0 },
    { "static",   0 },
    { "struct",   0 },
    { "switch",   0 },
    { "typedef",  0 },
    { "union",    0 },
    { "unsigned", 0 },
    { "void",     0 },
    { "volatile", 0 },
    { "while",    0 }
};
#define NKEYS (sizeof keytab / sizeof(struct key)) // the num of C keywords
// alternative method:#define NKEYS (sizeof keytab / sizeof keytab[0])

int binsearch(char* word, struct key tab[], int n);
int getword(char* word, int lim);
char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0;  // next free position in buf


// count C keywords
int main(int argc, char const *argv[])
{
	int n;
	char word[MAXWORD];

	while (getword(word, MAXWORD) != EOF) {
		if (isalpha(word[0])) {
			if ((n = binsearch(word, keytab, NKEYS)) >= 0) {
				keytab[n].count++;
			}
		}
	}

	for (n = 0; n < NKEYS; n++)	{
		if (keytab[n].count > 0) {
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
		}
	}

	return 0;
}

// getword: get next word or character from input
int getword(char* word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char* w = word;

	while(isspace(c = getch()))
		;
	if (c != EOF) {
		*w++ = c;
	}
	if(!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++) {
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}


// get a(possibly pushed back) character
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

// push character back on input
void ungetch(int c)
{
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many character\n");
	} else {
		buf[bufp++] = c;
	}
}

// binsearch: find x in v[0] <= v[1] <= ... <= v[n-1]
int binsearch(char* word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;
	while(low <= high) {
		mid = (low + high) / 2;
		if((cond = strcmp(word, tab[mid].word)) < 0) {
			high = mid - 1;
		} else if (cond > 0) {
			low = mid + 1;
		} else {			// found match
			return mid;
		}
	}

	return -1; // no match
}



/*
$ ./keyword_counting.exe < keyword_counting.c
   1 auto
   2 break
   1 case
  10 char
   2 const
   1 continue
   1 default
   1 do
   1 double
   4 else
   1 enum
   1 extern
   1 float
   4 for
   1 goto
  10 if
  20 int
   1 long
   1 register
   7 return
   1 short
   1 signed
   5 sizeof
   1 static
   5 struct
   1 switch
   1 typedef
   1 union
   1 unsigned
   5 void
   1 volatile
   4 while
*/