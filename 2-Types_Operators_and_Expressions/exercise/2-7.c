/*
Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at
position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
*/


unsigned invert(unsigned x, int p, int n)
{
	return x ^ (~(~0 << n) << (p + 1 - n));
}


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}