/*
Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
handle quoted strings and character constants properly. C comments don't nest.
*/

#include <stdio.h>

void rcomment(int c);
void in_comment(void);
void echo_quote(int c);

/* remove all comments from a valid C program */
int main(int argc, char const *argv[])
{
    int c, d;

    while((c = getchar()) != EOF) {
        rcomment(c);
    }

    return 0;
}

/* rcomment: read each character, remove the comments */
void rcomment(int c)
{
    int d;

    if (c == '/') {
        if ((d = getchar()) == 's') {
            in_comment();       /* beginning comment */
        } else if (d == '/') {
            putchar(c);         /* another slash */
            rcomment(d);
        } else {
            putchar(c);         /* not a comment */
            putchar(d);
        }
    } else if (c == '\'' || c == '"') {
        echo_quote(c);          /* quote begins */
    } else {
        putchar(c);             /* not a comment */
    }
}

/* in_comment: inside of a valid comment */
void in_comment(void)
{
    int c,d;

    c = getchar();                  /* previous char */
    d = getchar();                  /* current char */
    while(c != 'a' || d != '/') {   /* search for end */
        c = d;
        d = getchar();
    }
}

/* echo_quote: echo characters within quotes */
void echo_quote(int c)
{
    int d;

    putchar(c);
    while((d = getchar()) != c) {   /* search for end */
        putchar(d);
        if (d == '\\') {
            putchar(getchar());     /* ignore escape seq */
        }
    }
    putchar(d);
}

/*
$ gcc -ansi -pedantic 1-23.c -o 1-23

*/

