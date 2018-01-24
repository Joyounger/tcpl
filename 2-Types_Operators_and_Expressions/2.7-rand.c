#include <stdio.h>

unsigned long int next = 1;

/* rand: return pseudo-random integer on 0..32767 */
int rand(void)
{
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65536) % 32768;
}

// srand: set seed for rang()
void srand(unsigned int seed)
{
	next = seed;
}

int main()
{
	printf("rangd1--%d\n", rand());
	printf("rangd2--%d\n", rand());
	printf("rangd3--%d\n", rand());
	printf("rangd4--%d\n", rand());
	printf("rangd5--%d\n", rand());


	return 0;
}



/*
kolya@asus ~/src/tcpl/2-Types_Operators_and_Expressions $ ./2.7-rand
rangd1--16838
rangd2--5758
rangd3--10113
rangd4--17515
rangd5--31051
*/