/*
Exercise 1-22. Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n -th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column.
*/

#include <stdio.h>

#define MAXCOL 10   /* maximum column of input */
#define TABINC 8    /* tab incremental size */

char line[MAXCOL];  /* input size */

int exptab(int pos);
int findblnk(int pos);
int newpos(int pos);
void printl(int pos);

/* fold long input lines into two or more shorter lines */
int main(int argc, char const *argv[])
{
    int c, pos;

    pos = 0;                /* position in the line */
    while ((c = getchar()) != EOF) {
        line[pos] = c;      /* store current character */
        if (c == '\t') {
            pos = exptab(pos);
        } else if (c == '\n') {
            printl(pos);    /* print current input line */
            pos = 0;
        } else if (++pos >= MAXCOL) {
            pos = findblnk(pos);
            printl(pos);
            pos = newpos(pos);
        }
    }

    return 0;
}

/* printl: print line until pos column */
void printl(int pos)
{
    int i;
    for (i = 0; i < pos; ++i) {
        putchar(line[i]);
    }
    if (pos > 0) {      /* any chars printed? */
        putchar('\n');
    }
}

/* exptab: expand tab into blanks */
int exptab(int pos)
{
    line[pos] = ' ';    /* tab is at least one blank */
    for (++pos; pos < MAXCOL && pos % TABINC != 0; ++pos) {
        line[pos] = ' ';
    }
    if (pos < MAXCOL) { /* room left in current line */
        return pos;
    } else {            /* current line is full */
        printl(pos);
        return 0;       /* reset current position */
    }
}

/* findblnk: find blank's position */
int findblnk(int pos)
{
    while (pos > 0 && line[pos] != ' ') {
        --pos;
    }
    if (pos == 0) {     /* no blanks in the line */
        return MAXCOL;
    } else {            /* at least one blank */
        return pos+1;   /* position after the blank */
    }
}

/* new pos: rearrange line with new position */
int newpos(int pos)
{
    int i, j;

    if (pos <= 0 || pos >= MAXCOL) {
        return 0;   /* nothing to rerrange */
    } else {
        i = 0;
        for (j = 0; j < MAXCOL; ++j) {
            line[i] = line[j];
            ++i;
        }
        return i;   /* new position */
    }
}

/*
$ gcc -ansi -pedantic 1-22.c -o 1-22
*/


