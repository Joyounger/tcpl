//date: 17.7.2


/* strcat: concatenate t to end of s; s must be big enough */
void strcat(char s[], char t[])
{
	int i, j;
	i = j = 0;

	while (s[i] != '\0') /* find end of s */
		i++;
	while ((s[i++] = t[j++]) != '\0') /* copy t */
		;
}


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}