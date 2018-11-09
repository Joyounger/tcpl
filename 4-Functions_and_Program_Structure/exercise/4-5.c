/* date:17.6.18
 author: linyang <942510346@qq.com>
*/

/*
Exercise 4-5. Add access to library functions like sin, exp, and pow. See <math.h> in Appendix B, Section 4.
*/


#include <stdio.h>
#include <stdlib.h> 	/* for atof() */
#include <ctype.h>

#define MAXOP 100 		/* max size of operand or operator */
#define NUMBER '0' 		/* signal that a number was found */
#define IDENTIFIER   1
#define MAXVAL 100 		/* maximum depth of val stack */
#define BUFSIZE 100

char buf[BUFSIZE]; 		/* buffer for ungetch */
double val[MAXVAL]; 	/* value stack */
int bufp = 0; 			/* next free position in buf */
int sp = 0; 			/* next free stack position */


int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);


double print_stack_top(void)
{
	if (sp > 0) {
		printf("%f\n", val[sp]);
		return val[sp];
	} else {
		printf("error: stack empty\n");
		exit(-1);
	}
}

void copy_stack_top(void)
{
	if (sp < MAXVAL) {
		push(print_stack_top());
	} else {
		printf("error: stack full\n");
	}
}

void swap_stack_top2(void)
{
	double top1 = pop();
	double top2 = pop();

	push(top1);
	push(top2);
}

void clear_stack(void)
{
	int i;
	for (i = 0; i < sp; i++) {
		val[i] = 0;
	}
}

/* reverse Polish calculator */
int main(int argc, char const *argv[])
{
	int type;
	double op2;
	char s[MAXOP];
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
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
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

/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;	/* not a number */
	
	i = 0;

	if (isalpha(c)) {
		while (isalpha(s[i++] = c = getch())) {
			c = getch();
		}
		s[i - 1] = '\0';
		if (c != EOF) {
			ungetch(c);
		}

		return IDENTIFIER;
	}

	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') /* collect fraction part */
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
