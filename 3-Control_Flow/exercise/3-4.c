/*
Exercise 3-4. In a two's complement number representation, our version of itoa does not
handle the largest negative number, that is, the value of n equal to -(2 wordsize-1 ). Explain why
not. Modify it to print that value correctly, regardless of the machine on which it runs.
*/

#include <string.h>

#define abs(x)  ((x) < 0 ? -(x) : (x))

/* itoa: convert n to characters in s - modified */
void itoa(int n, char s[])
{
    int i, sign;
    void reverse(char s[]);

    sign = n;       /* record sign */
    i = 0;
    do {                        /* generate digits in reverse order */
        s[i++] = abs(n % 10) + '0';  /* get next digit */
    } while ((n /= 10) != 0);    /* delete it */
    
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

void reverse(char* s)
{
    int len = strlen(s);

    int i;
    int temp;
    for (i = 0; i < len/2 ; i++) {
        temp = s[i];
        s[i] = s[len - i -1];
        s[len - i -1] = temp;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}


/*
$ gcc -ansi -pedantic 3-4.c -o 3-4

*/
