// date:17.6.17
// author: linyang <942510346@qq.com>

/*
Exercise 4-2. Extend atof to handle scientific notation of the form
123.45e-6
where a floating-point number may be followed by e or E and an optionally signed exponent.
*/


#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[])
{
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++) //skip white space
		;

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
	}
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	if (s[i] == 'E' || s[i] == 'e')
		i++;
	int Enegsign = 0;
	if (s[i] == '-') {
		i++;
		Enegsign = 1;
	}
	int expower = 0;
	for (; isdigit(s[i]); i++) {
		expower = expower * 10 + (s[i] - '0');
	}

	if (Enegsign == 1) {
		return sign * val / power / pow(10, expower);
	} else {
		return sign * val / power * pow(10, expower);
	}
}


int main(int argc, char const *argv[])
{
	char *strings[] = {
		"1.0e43",
		"999.999",
		"123.456e-9",
		"-1.2e-3",
		"1.2e-3",
		"-1.2E3",
		"-1.2e03",
		"cat",
		"",
		0
	};

	int i = 0;
	for (; *strings[i]; i++)
		printf("atof(%s) = %g\n", strings[i], atof(strings[i]));

	return 0;
}


/*
kolya@asus ~/src/tcpl/4-Functions_and_Program_Structure/exercise $ gcc 4-2.c -o 4-2 -lm
kolya@asus ~/src/tcpl/4-Functions_and_Program_Structure/exercise $ ./4-2
atof(1.0e43) = 1e+43
atof(999.999) = 999.999
atof(123.456e-9) = 1.23456e-07
atof(-1.2e-3) = -0.0012
atof(1.2e-3) = 0.0012
atof(-1.2E3) = -1200
atof(-1.2e03) = -1200
atof(cat) = 0
*/
