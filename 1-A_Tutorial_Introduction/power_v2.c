//date: 17.7.2

#include <stdio.h>

int power(int m, int n);

// test power function
int main(int argc, char const *argv[])
{
	int i;

	for (i = 0; i < 10; ++i) {
		printf("%d %d %d\n", i, power(2, i), power(-3, i));
	}


	return 0;
}


//power: raise base to n-th power; n >= 0; version2
int power(int base, int n)
{
	int p;

	for (p = 1; n > 0; --n) {
		p = p * base;
	}

	return p;
}



/*
kolya@asus ~/src/tcpl/1-A_Tutorial_Introduction $ ./power_v2 
0 1 1
1 2 -3
2 4 9
3 8 -27
4 16 81
5 32 -243
6 64 729
7 128 -2187
8 256 6561
9 512 -19683
*/