#include <stdarg.h>
#include <stdio.h>

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
	va_list ap; /* points to each unnamed arg in turn */
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt); /* make ap point to 1st unnmaed arg */
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch(*++p) {
			case 'd':
				ival = va_arg(ap, int);
				printf("%d", ival);
				break;
			case 'f':
				dval = va_arg(ap, double);
				printf("%f", dval);
				break;
			case 's':
			    for (sval = va_arg(ap, char *); *sval; sval++) {
			    	putchar(*sval);
			    }
			    break;
			default:
                putchar(*p);
                break;
		}
		
	}
    va_end(ap); /* clean up when done */
}


int main(int argc, char const *argv[])
{
	int a = 1;
	float b = 2.0;
	char *c = "test minprintf";
	minprintf("a=%d, b=%f, c=%s\n", a, b, c);

	return 0;
}

/*
$ gcc -ansi -pedantic minprintf.c -o minprintf

$ ./minprintf.exe
a=1, b=2.000000, c=test minprintf

*/