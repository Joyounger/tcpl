/*
Exercise 1-19. Write a function reverse(s) that reverses the character string s . Use it to
write a program that reverses its input a line at a time
*/

#ifndef EOF
#define EOF (-1)
#endif

              
#define MAXLINE 1000 /* max input line size */
int getline(char line[], int maxline);

void reverse(char s[])
{
    int i;
    int len = strlen(s);

    for(i = 0; i < len / 2; i++) {
        char tmp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = tmp;
    }
}
         
         
int main(int argc, char const *argv[])
{
    int len;
    char line[MAXLINE];

    while((len = getline(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s", line);
    }
    
    return 0;
}




/* getline: read a line into s, return length; */
int getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;

}


/*
$ gcc -ansi -pedantic 1-19.c -o 1-19

$ ./1-19.exe < 1-19.c
*/