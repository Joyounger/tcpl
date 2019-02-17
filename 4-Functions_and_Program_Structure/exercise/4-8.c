/*
4-8 Suppose there will never be more than one character of pushback. Modify getch and ungetch accordingly. 
*/



#define BUFSIZE 100

char buf = 0; 		/* buffer for ungetch */

/* get a (possibly pushed-back) character */
int getch(void)
{
	int c;

	if (buf != 0) {
		c = buf;
	} else {
		c = getchar();
	}

	buf = 0;
	return c;
}

/* push character back on input */
void ungetch(int c)
{
	if (buf != 0) {
		printf("ungetch: too many characters\n");
	} else {
		buf = c;
	}
}