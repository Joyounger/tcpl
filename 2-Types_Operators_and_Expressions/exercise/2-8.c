/*
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated
to the right by n positions.
*/


/*  */
unsigned rightrot(unsigned x, int n)
{
    int wordlength(void);
    int rbit;               /* rightmost bit */

    while(n-- > 0) {
        rbit = (x & 1) << (wordlength() - 1);
        x = x >> 1;     /* shift x 1 position right */
        x = x | rbit;   /* compete one rotation */
    }

    return x;
}

/* wordlengthL computes word length of the machine */
int wordlength(void)
{
    int i;
    unsigned v = (unsigned) ~0;

    for (i = 1; (v = v >> 1) > 0; i++) {
        ;
    }

    return i;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}


/*
$ gcc -ansi -pedantic 2-8.c -o 2-8

*/