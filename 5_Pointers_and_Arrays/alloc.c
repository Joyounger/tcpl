//date: 17.7.3


#define ALLOCSIZE 10000 			/* size of available space */
static char allocbuf[ALLOCSIZE]; 	/* storage for alloc */
static char *allocp = allocbuf; 	/* next free position */

char *alloc(int n) 					/* return pointer to n characters */
{
	if (allocbuf + ALLOCSIZE - allocp >= n) { 	/* it fits */
		allocp += n;
		return allocp - n; 						/* old p */
	} else										/* not enough room */

	return 0;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}