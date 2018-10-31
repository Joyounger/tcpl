#include <stdarg.h>
#include <stdio.h>

/* minscanf: minimal scanf with variable argument list */
void minscanf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			getchar();
			continue;
		}
		switch(*++p) {
			case 'd':
				ival = va_arg(ap, int);
				scanf("%d", &ival);
				break;
			case 'f':
				dval = va_arg(ap, double);
				scanf("%f", &dval);
				break;
			case 's':
				sval = va_arg(ap, char *);
				scanf("%s", sval);
				break;
			default:
				/* scanf(*p); */
				break;
		}
	}
	va_end(ap);
}

int main(int argc, char const *argv[])
{
	int a;
	float b;
	char c[100];
	minscanf("%d,%f,%s\n", &a, &b, c);


	printf("a=%d, b=%f, c=%s\n", a, b, c);

	return 0;
}


/*
$ gcc -ansi -pedantic 7-4.c -o 7-4

$ ./7-4.exe
1,2.0,test minscanf
a=0, b=0.000000, c=test
*/


