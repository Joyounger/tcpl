/*
Exercise 4-6. Add commands for handling variables. (It's easy to provide twenty-six variables with single-letter names.)
Add a variable for the most recently printed value.
*/


#include <stdio.h>
#include <string.h>
#include <string.h>
#include <ctype.h>
#include <math.h> /* for atof() */

#define MAXOP 100       /* max size of operand or operator */
#define NUMBER '0'      /* signal that a number was found */
#define NAME   'n'      /* signal that a name was found */
#define BUFSIZE 100
#define MAXVAL 100

char buf[BUFSIZE];      /* buffer for ungetch */
double val[MAXVAL];     /* value stack */
int bufp = 0;           /* next free position in buf */
int sp = 0;             /* next free stack position */


int getop(char []);
void push(double);
double pop(void);
void mathfnc(char []);
int getch(void);
void ungetch(int);

/* reverse Polish calculator */
int main(int argc, char const *argv[])
{
    int i, type, var = 0;
    double op2, v;
    char s[MAXOP];
    double variable[26];

    for (i = 0; i < 26; ++i) {
        variable[i] = 0.0;
    }
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '=':
                pop();
                if (var >= 'A' && var <= 'Z') {
                    variable[var - 'A'] = pop();
                } else {
                    printf("error: no variable name\n");
                }
                break;
            case '\n':
                v = pop();
                printf("\t%.8g\n", v);
                break;
            default:
                if (type >= 'A' && type <= 'Z') {
                    push(variable[type - 'A']);
                } else if (type == 'v') {
                    push(v);
                } else {
                    printf("error: unknown command %s\n", s);
                }
                break;
        }
        var = type;
    }

    return 0;
}

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
    return 0.0;
    }
}

/* getop: get next character, numeric operand, or math fnc */
int getop(char s[])
{
    int c,i;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;

    if (islower(c)) {   /* command or NAME */
        while (islower(s[++i] = c = getch()))
            ;
        s[i] = '\0';
        if (c != EOF) {
            ungetch(c);     /* went one char too far */
        }
        if (strlen(s) > 1) {
            return NAME;    /* >1 char: it is NAME */
        } else {
            return c;       /* it may be a command */
        }
    }

    if (!isdigit(c) && c != '.') {
        return c;       /* not a number */
    }
    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}


int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/*
$ gcc -ansi -pedantic 4-6.c -o 4-6


*/
