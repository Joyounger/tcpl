//date: 17.7.2


/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}