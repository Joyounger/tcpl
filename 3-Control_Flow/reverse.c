//date: 17.7.2

#include <string.h>

//reverse: reverse string s in place
void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++,j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}