// date:17.6.14
// author: linyang <942510346@qq.com>

/*
Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case, with a
conditional expression instead of if-else.
*/

#include <stdio.h>

int lower(int c)
{
    return (c >='A' && c <= 'Z') ? (c - 'A' + 'a') : c;
    
}

int main(int argc, char const *argv[])
{
    int c = 'K';
    printf("%c 's lower case is %c\n", c, lower(c));


    return 0;
}


/*
K 's lower case is k
*/
