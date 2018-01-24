//date: 17.7.2

/* squeeze: delete all c from s */
void squeeze(char s[], int c)
{
	int i, j;
	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];

	s[j] = '\0';
}


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}