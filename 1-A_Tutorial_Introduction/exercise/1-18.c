/*
Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines.
*/
#ifndef EOF
#define EOF (-1)
#endif

              
#define MAXLINE 1000 /* max input line size */
int getline(char line[], int maxline);

void reverse(char s[], int len)
{
	int i;

	for(i = 0; i < len / 2; i++) {
		char tmp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = tmp;
	}
}
         

int main(int argc, char const *argv[])
{
	int len, i, j, loc = -1;
	char line[MAXLINE];
	char line_strip[MAXLINE];

	while((len = getline(line, MAXLINE)) > 0) {
		reverse(line, len);
		for (i = 0; i < len; ++i) {
			if (line[i] != ' ' && line[i] != '\t') {
				loc = i;
				break;
			}
		}
		if (loc == -1) {
			continue;
		} else {
			for (i = loc, j = 0; i < len; ++i, ++j) {
				line_strip[j] = line[i];
			}
			line_strip[j] = '\0';
			reverse(line_strip, j);
			printf("%s", line_strip);
		}

	}


	return 0;
}




/* getline: read a line into s, return length; */
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