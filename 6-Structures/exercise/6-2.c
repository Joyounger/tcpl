#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


struct tnode {			/* the tree node */
	char* word;			/* pointers to the text */
	int match;			/* match found */
	struct tnode *left; /* left child */
	struct tnode *right;
};

#define MAXWORD 100
#define YES		1
#define NO 		0

struct tnode *addtreex(struct tnode *, char *, int, int *);
void treexprint(struct tnode *);
int getword(char *, int);
/* strdup不在标准库中,但很多编译器会支持
因此如果不使用string.h中的strdup,就要在程序中自己声明和定义strdup,gcc编译时要加上-ansi -pedantic参数
如果使用string.h中的strdup,就不能在程序中自己声明和定义strdup,编译时不带-ansi -pedantic,采用默认编译参数 */
char *strdup(char *); 

/* print in alphabetic order each group of variable names
identical in the first num characters(default 6) */
int main(int argc, char const *argv[])
{
	struct tnode* root;
	char word[MAXWORD];
	int found = NO; /* YES if match was found */
	unsigned int num;		/* number of the first ident chars */

	num = (--argc && (*++argv)[0] == '-') ? atoi(argv[0]+1) : 6;
	root = NULL;
	while(getword(word, MAXWORD) != EOF) {
		if (isalpha(word[0]) && strlen(word) >= num) {
			root = addtreex(root, word, num, &found);
		}
		found = NO;
	}
	treexprint(root);

	return 0;
}

struct tnode *talloc(void);
int compare(char *, struct tnode *, int, int *);

/* addtreex: add a node with w, at or below p */
struct tnode *addtreex(struct tnode *p, char *w, int num, int *found)
{
    int cond;

    if (p == NULL) { /* a new word has arrived */
        p = talloc(); /* make a new node */
        p->word = strdup(w);
        p->match = *found;
        p->left = p->right = NULL;
    } else if((cond = compare(w, p, num, found)) < 0) {
        p->left = addtreex(p->left, w, num, found);
    } else if(cond > 0) { 
        p->right = addtreex(p->right, w, num, found);
    }

    return p;
}

/* compare: compare words and update p->match */
int compare(char *s, struct tnode *p, int num, int *found)
{
	int i;
	char *t = p->word;

	for (i = 0; *s == *t; i++, s++, t++) {
		if (*s == '\0')	{
			return 0;
		}
	}
	if (i >= num) {
		*found = YES;
		p->match = YES;
	}

	return *s - *t;
}

/* treexprint: in-order print of tree p if p->match == YES */
void treexprint(struct tnode *p)
{
    if (p != NULL) {
    	treexprint(p->left);
    	if (p->match) {
    		printf("%s\n", p->word);	
    	}
    	treexprint(p->right);
    }
}

/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;  /* next free position in buf */
/* get a(possibly pushed back) character */
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c)
{
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many character\n");
	} else {
		buf[bufp++] = c;
	}
}

/* getword: get next word or character from input */
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

char* strdup(char* s)
{
    char *str;
    str = (char *)malloc(strlen(s) + 1);
    if (str != NULL) {
        strcpy(str, s);
    }

    return str;
}

/*
$ gcc -W -Wall -ansi -pedantic 6-2.c -o 6-2

$ ./6-2.exe < 6-2.c
character
characters
comment
comments
constant
constants
define
defined
escape
escapes
handle
handles
identical
identifier
identifiers
indicates
indicating
return
returned
returns


*/

