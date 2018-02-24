//date: 17.7.2




// binsearch: find x in v[0] <= v[1] <= ... <= v[n-1]
int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while(low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid]) {
			high = mid - 1;
		} else if (x > v[mid]) {
			low = mid + 1;
		} else {			// found match
			return mid;
		}
	}

	return -1; // no match
}


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}