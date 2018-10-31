#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/*
strdup不在标准库中,但很多编译器会支持
因此如果不使用string.h中的strdup,就要在程序中自己声明和定义strdup,gcc编译时要加上-ansi -pedantic参数
如果使用string.h中的strdup,就不能在程序中自己声明和定义strdup,编译时不带-ansi -pedantic,采用默认编译参数

$ gcc -ansi -pedantic word_counting.c -o word_counting
$ ./word_counting.exe < word_counting.c
   3 BUFSIZE
   2 EOF
   3 MAXWORD
   5 NULL
   6 a
   1 add
   6 addtree
   1 ansi
   1 argc
   1 argv
   1 arrived
   1 at
   2 back
   1 below
   1 break
   4 buf
   1 buffer
   5 bufp
   9 c
  15 char
   4 character
   2 child
   3 cond
   1 const
   5 count
   2 counting
   1 ctype
   1 d
   2 define
   1 duplicate
   4 else
   3 for
   1 free
   1 freq
   1 from
   1 gcc
   2 get
   4 getch
   1 getchar
   4 getword
   1 greater
   4 h
   1 has
  10 if
   2 in
   4 include
   2 input
  13 int
   2 into
   1 isalnum
   2 isalpha
   1 isspace
   7 left
   1 less
   2 lim
   1 main
   3 make
   2 malloc
   1 many
   2 n
   2 new
   2 next
   3 node
   1 number
   1 o
   1 occurrences
   3 of
   1 on
   2 or
   1 order
  22 p
   1 pedantic
   1 points
   1 position
   1 possibly
   1 print
   2 printf
   1 push
   1 pushed
   1 repeated
   8 return
   7 right
   5 root
   5 s
   1 sizeof
   1 stdio
   1 stdlib
   5 str
   1 strcmp
   1 strcpy
   3 strdup
   1 string
   1 strlen
  14 struct
   2 subtree
   4 talloc
   1 text
   2 than
   2 the
  15 tnode
   1 to
   1 too
   2 tree
   6 treeprint
   5 ungetch
   8 void
  13 w
   2 while
   1 with
  17 word
*/


#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
char *strdup(char *);

struct tnode {             /* the tree node */
	char* word;            /* points to the text */
	int count;             /* number of occurrences */
	struct tnode* left;    /* left child */
	struct tnode* right;   /* right child */
};
struct tnode *talloc(void);

/* word freq count */
int main(int argc, char const *argv[])
{
	struct tnode* root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD) != EOF) {
		if (isalpha(word[0])) {
			root = addtree(root, word);
		}
	}

	treeprint(root);

	return 0;
}


/* addtree: add a node with w, at or below p */
struct tnode * addtree(struct tnode *p, char *w)
{
    int cond;
    if (p == NULL) { /* a new word has arrived */
        p = talloc(); /* make a new node */
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if((cond = strcmp(w, p->word)) == 0) {
        p->count++; /* repeated word */
    } else if(cond < 0) { /* less than into left subtree */
        p->left = addtree(p->left, w);
    } else {  /* greater than into right subtree */
        p->right = addtree(p->right, w);
    }

    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
    if (p == NULL) {
        return;
    }

    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);
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

/* make a duplicate of s */
char* strdup(char* s)
{
    char *str;
    str = (char *)malloc(strlen(s) + 1); /* +1 for '\0' */
    if (str != NULL) {
        strcpy(str, s);
    }

    return str;
}