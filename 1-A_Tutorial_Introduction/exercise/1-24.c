/*
Exercise 1-24. Write a program to check a C program for rudimentary syntax errors like
unmatched parentheses, brackets and braces. Don't forget about quotes, both single and
double, escape sequences, and comments. (This program is hard if you do it in full
generality.)
*/

#include <stdio.h>

int brace, brack, paren;

void in_quote(int c);
void in_comment(void);
void search(int c);

/* rudimwntary syntax checker for C program */
int main(int argc, char const *argv[])
{
    int c;
    extern int brace, brack, paren;

    while ((c = getchar()) != EOF) {
        if (c == '/') {
            if ((c = getchar()) == '*') {
                in_comment();   /* inside comment */
            } else {
                search(c);
            }
        } else if (c == '\'' || c == '"') {
            in_quote(c);        /* inside quote */
        } else {
            search(c);
        }

        if (brace < 0) {    /* output errors */
            printf("Unbalanced braces\n");
            brace = 0;
        } else if (brack < 0) {
            printf("Unbalanced brackets\n");
            brack = 0;
        } else if (paren < 0) {
            printf("Unbalanced parentheses\n");
            paren = 0;
        }
    }

    if (brace > 0) {    /* output errors */
        printf("Unbalanced braces\n");
    }
    if (brack > 0) {
        printf("Unbalanced brackets\n");
    }
    if (paren > 0) {
        printf("Unbalanced parentheses\n");
    }


    return 0;
}

/* search: search for rudimentary syntax */
void search(int c)
{
    extern int brace, brack, paren;

    if (c == '{') {
        ++brace;
    } else if (c == '}'){
        --brace;
    } else if (c == '['){
        ++brack;
    } else if (c == ']'){
        --brack;
    } else if (c == '('){
        ++paren;
    } else if (c == ')'){
        --paren;
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

/* in_quote: inside quote */
void in_quote(int c)
{
    int d;

    while((d = getchar()) != c) { /* search end quote */
        if (d == '\\') {
            getchar();            /* ignore escape seq */
        }
    }
}

/*
$ gcc -ansi -pedantic 1-24.c -o 1-24

*/