#include <stdio.h>
#include <stdlib.h>

#define MAXBOT  3   /* maximum # lines at bottom page */
#define MAXHDR  5   /* maximum # lines at head of page */
#define MAXLINE 100 /* maximum size at head of page */
#define MAXPAGE 66  /* maximum # lines on  */

/* print: print files - each new one on a new page */
int main(int argc, char *argv[])
{
    FILE *fp;
    void fileprint(FILE *fp, char *fname);

    if (argc == 1) { /* no arg; print standard input */
        fileprint(stdin, " ");
    } else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "print: can't open %s\n", *argv);
                exit(1);
            } else {
                fileprint(fp, *argv);
                fclose(fp);
            }
        }
    }

    return 0;
}

/* fileprint: print file fname */
void fileprint(FILE *fp, char *fname)
{
    int lineno, pageno = 1;
    char line[MAXLINE];
    int heading(char *fname, int pageno);

    lineno = heading(fname, pageno++);
    while (fgets(line, MAXLINE, fp) != NULL) {
        if (lineno == 1) {
            fprintf(stdout, "\f");
            lineno = heading(fname, pageno++);
        }
        fputs(line, stdout);
        if (++lineno > MAXPAGE - MAXBOT) {
            lineno = 1;
        }
    }
    fprintf(stdout, "\f"); /* page eject after the file */
}


/* heading: put heading end enough blank lines */
int heading(char* fname, int pageno)
{
    int ln = 3;

    fprintf(stdout, "\n\n");
    fprintf(stdout, "%s page %d\n", fname, pageno);
    while (ln++ < MAXHDR) {
        fprintf(stdout, "\n");
    }

    return ln;
}


/*
$ gcc -ansi -pedantic 7-8.c -o 7-8

*/