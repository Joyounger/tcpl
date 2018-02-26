// date:17.6.24
// author: linyang <942510346@qq.com>



/*
Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t. (Block structure
will help.)
*/

#include <stdio.h>

#define swap(t, x, y)	\
	do {				\ 
		t tmp; 			\
	 	tmp = (x); 		\
	 	(x) = (y);		\
	  	(y) = tmp;		\
	} while(0)			\



int main(int argc, char const *argv[])
{
	int ix, iy;
	double dx, dy;
	char *px, *py;
	ix = 42;
	iy = 69;
	printf("integers before swap: %d and %d\n", ix, iy);
	swap(int, ix, iy);
	printf("integers after swap: %d and %d\n", ix, iy);
	dx = 123.0;
	dy = 321.0;
	printf("doubles before swap: %g and %g\n", dx, dy);
	swap(double, dx, dy);
	printf("integers after swap: %g and %g\n", dx, dy);
	px = "hello";	
	py = "world";
	printf("pointers before swap: %s and %s\n", px, py);
	swap(char *, px, py);
	printf("integers after swap: %s and %s\n", px, py);


	return 0;
}


/*
t safe ## x ## y; \
safe ## x ## y = x; \
x = y; \
y = safe ## x ## y; \
*/