//date: 17.7.3

#define ALLOCSIZE 10000 			/* size of available space */
static char allocbuf[ALLOCSIZE]; 	/* storage for alloc */
static char *allocp = allocbuf; 	/* next free position */

void afree(char *p) /* free storage pointed to by p */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}