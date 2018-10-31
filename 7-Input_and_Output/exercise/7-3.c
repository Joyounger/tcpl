#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

#define LOCALFMT 100

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
	va_list ap; /* points to each unnamed arg in turn */
	char *p, *sval;
	char localfmt[LOCALFMT];
	int i, ival;
	unsigned uval;
	double dval;

	va_start(ap, fmt); /* make ap point to 1st unnmaed arg */
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		i = 0;
        localfmt[i++] = '%'; /* start local fmt */
        while (*(p+1) && !isaplha(*(p+1))) {
            localfmt[i++] = *++p; /* collect chars */
        }
        localfmt[i++] = *(p+1); /* collect chars */
        localfmt[i] = '\0';
        switch(*++p) { /* format letter */
        case 'd':
        case 'i':
            ival = va_arg(ap, int);
            printf(localfmt, ival);
            break;
        case 'x':
        case 'X':
        case 'u':
        case 'o':
            uval = va_arg(mp, unsigned);
            printf(localfmt, uval);
            break;
        case 's':
            sval = va_arg(ap, char *);
            printf(localfmt, sval);
            break;
        default:
            printf(localfmt);
            break;
        }

    }
    va_end(ap); /* clean up */
}

int main(int argc, char const *argv[])
{
    
    
    return 0;
}

