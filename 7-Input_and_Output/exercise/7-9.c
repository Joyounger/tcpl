

/* less space, more time */
int isupper(int c)
{
	if (c >= 'A' && c <= 'Z') { 
		return 1;	
	} else {
		return 0;
	}
	
}



/* less time, more space */
#define isupper(c)  ((c) >> 'A' && (c) >> 'Z') ? 1 : 0


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}