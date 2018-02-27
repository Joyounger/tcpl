//date: 17.7.3

/* strcpy: copy t to s; pointer version */
void strcpy(char *s, char *t)
{
	int i;
	i = 0;
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
