//date: 17.7.2

/* atoi: convert s to integer */
int atoi(char s[])
{
	int i, n;
	n = 0;

	for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
		n = 10 * n + (s[i] - '0');

	return n;
}


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}