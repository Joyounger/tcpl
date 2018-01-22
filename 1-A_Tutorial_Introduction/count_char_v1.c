//date: 17.7.2

#include <stdio.h>

// count characters in input; 1st version
int main(int argc, char const *argv[])
{
	long nc;

	nc = 0;
	while(getchar() != EOF) {
		nc++;
	}

	printf("%ld\n", nc);
	return 0;
}