
while (getline(line, sizeof(line)) > 0) {
	if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3) {
		printf("valid: %s\n", line); /* 25 dec 1988 form */
	} else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3) {
		printf("valid: %s\n", line); /* mm/dd/yy form */
	} else {
		printf("invalid: %s\n", line); /* invalid form */
	}
}


/* fgets: get at most n - 1 chars, plus a null from iop */
char *fgets(char *s, int n, FILE *iop)
{
	register int c;
	register char *cs;

	cs = s;
	while(--n > 0 && (c =getc(iop)) != EOF) {
		if ((*cs++ = c) == '\n') {
			break;
		}
	}
	*cs = '\0';

	return (c == EOF && cs == s) ? NULL : s;
}

/* fputs: put string s on file iop */
int fputs(char *s, FILE *iop)
{
	int c;

	while(c = *s++) {
		putc(c, iop);
	}

	return ferror(iop) ? EOF : non-negative;
}

/* getline: read a line, return length */
int getline(char *line, int max)
{
	if (fgets(line, max, stdin) == NULL) {
		return 0;
	} else {
		return strlen(line);
	}
}



