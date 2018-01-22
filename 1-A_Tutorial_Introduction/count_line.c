//date: 17.7.2

#include <stdio.h>

// count lines in input
int main(int argc, char const *argv[])
{
	int c, nl;

	nl = 0;
	while((c = getchar()) != EOF) {
		if (c == '\n') {
			++nl;
		}
	}
	printf("\n%d\n", nl);


	return 0;
}