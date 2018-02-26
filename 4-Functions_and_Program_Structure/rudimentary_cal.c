//date: 17.7.2


/* End of file character. Some things throughout the library rely on this being -1.  */
#ifndef EOF
# define EOF (-1)
#endif

#define MAXLINE 100

#include <ctype.h>
// atof: convert string s to double
double atof(char s[])
{
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); ++i) // skip white space
	{
		;
	}

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') {
		i++;
	}
	for (val = 0.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
	}
	if (s[i] == '.') {
		i++;
	}
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	return sign * val / power;
}

//getline: read a line into s, return length;
int getline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;

}

//rudimentary calculator
int main(int argc, char const *argv[])
{
	double sum, atof(char[]);
	char line[MAXLINE];
	int getline(char line[], int max);

	sum = 0;
	while (getline(line, MAXLINE) > 0) {
		printf("\t%g\n", sum += atof(line));
	}


	return 0;
}