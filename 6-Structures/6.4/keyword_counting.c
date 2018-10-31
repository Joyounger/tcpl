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

struct key* binsearch(char*, struct key*, int);
int getword(char*, int);
char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0;  // next free position in buf


// count C keywords
int main(int argc, char const *argv[])
{
	char word[MAXWORD];
  struct key* p;

	while (getword(word, MAXWORD) != EOF) {
		if (isalpha(word[0])) {
			if ((p = binsearch(word, keytab, NKEYS)) != NULL) {
				p->count++;
			}
		}
	}

	for (p = keytab; p < keytab + NKEYS; p++)	{
		if (p->count > 0) {
			printf("%4d %s\n", p->count, p->word);
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
struct key *
binsearch(char* word, struct key* tab, int n)
{
	int cond;
	struct key* low = &tab[0];
  struct key* high = &tab[n];
  struct key* mid;

	while(low < high) {
		mid = low + (high - low) / 2;
		if((cond = strcmp(word, mid->word)) < 0) {
			high = mid ;
		} else if (cond > 0) {
			low = mid + 1;
		} else {			// found match
			return mid;
		}
	}

	return NULL; // no match
}



/*
$ ./keyword_counting.exe < keyword_counting.c
   2 auto
   3 break
   2 case
  11 char
   3 const
   2 continue
   2 default
   2 do
   2 double
   5 else
   2 enum
   2 extern
   2 float
   5 for
   2 goto
  11 if
  17 int
   2 long
   2 register
   8 return
   2 short
   2 signed
   6 sizeof
   2 static
  12 struct
   2 switch
   2 typedef
   2 union
   2 unsigned
   6 void
   2 volatile
   5 while

*/