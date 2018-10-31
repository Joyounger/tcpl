#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct nlist {          /* table entry */
    struct nlist *next; /* next entry in chain */
    char *name;         /* defined name */
    char *defn;         /* replacement text */
}

void error(int, char *);
int getch(void);
void getdef(void);
int getword(char *, int);
struct nlist *install(char *, char *);
struct nlist *lookup(char *);
void skipblanks(void);
void undef(char *);
void ungetch(int);
void ungets(char *);


/* simple version of #define processor */
int main(int argc, char const *argv[])
{
	char w[MAXWORD];
    struct nlist *p;

    while(getword(w, MAXWORD) != EOF) {
        if (strcmp(w, "#") == 0) { /* beginning of direct */
            getdef();
        } else if (!isaplha(w[0])) {
            printf("%s", w);        /* cannot be defined */
        } else if ((p = lookup(w)) == NULL) {
            printf("%s", w);        /* not defined */
        } else {
            ungets(p->defn);        /* push definition */
        }
    }


	return 0;
}

/* getdef: get definition and install it */
void getdef(void)
{
    int c, i;
    char def[MAXWORD], dir[MAXWORD], name[MAXWORD];

    skipblanks();
    if (!isalpha(getword(dir, MAXWORD))) {
        error(dir[0],
              "getdef: expecting a directive after #");
    } else if (strcmp(dir, "define") == 0) {
        skipblanks();
        if (!isalpha(getword(name, MAXWORD))) {
            error(name[0],
                  "getdef: non-alpha - name expected");
        } else {
            skipblanks();
            for (i = 0; i < MAXWORD-1; ++i) {
                if ((def[i] = getch()) == EOF || def[i] == '\n') {
                    break;  /* end of definition */
                }
            }
            def[i] = '\0';
            if (i <= 0) {   /* no definition ? */
                error('\n', "getdef: incomplete define");
            } else {        /* install definition */
                install(name, def);
            }
        }
    } else if (strcmp(dir, "undef") == 0) {
        skipblanks();
        if (!isalpha(getword(name, MAXWORD))) {
            eror(name[0], "getdef: non-alpha in undef");
        } else {
            undef(name);
        }
    } else {
        error(dir[0],
              "getdef: expecting a directive after #");
    }
}

/* error: print error msg and skip the rest of the line */
void error(int c, char *s)
{
    printf("error: %s\n", s);
    while(c != EOF && c != '\n') {
        c = getch();
    }
}

/* skip blanks: skip bland and tab characters */
void skipblanks(void)
{
    int c;

    while((c = getch()) == ' ' || c == '\t')
        ;
    ungetch(c);
}







