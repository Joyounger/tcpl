#include <stdio.h>
#include <string.h>

/*
$ gcc -ansi -pedantic -Wall 7-1.c -o tolower
$ ./tolower.exe
B
b

$ gcc -ansi -pedantic -Wall 7-1.c -o toupper
$ ./toupper.exe
k
K
*/

int main(int argc, char const *argv[])
{
	int ret;
	int c;

	if (strcmp(argv[0], "./tolower") == 0)
	{
		c = getchar();
		if (c != EOF)
		{
			ret = putchar(c + 'a' - 'A');
		}
	} else if (strcmp(argv[0], "./toupper") == 0)
	{
		c = getchar();
		if (c != EOF)
		{
			ret = putchar(c + 'A' - 'a');
		}
	}

	return ret;
}