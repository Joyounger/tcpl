
#include <stdio.h>

/* rudimentary calculator */
int main(int argc, char const *argv[])
{
	double sum, v;
	sum = 0;

	while (scanf("%lf", &v) == 1) {
		printf("\t%.2f\n", sum += v);
	}

	return 0;
}


/*
$ gcc rudimentary_calculator.c -ansi -pedantic -o rudimentary_calculator

$ ./rudimentary_calculator.exe
1.2
        1.20
2.4
        3.60
3.6
        7.20
44445..778
        44452.20
        44452.98
*/