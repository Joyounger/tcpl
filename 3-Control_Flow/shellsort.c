// date:17.6.17
// author: linyang <942510346@qq.com>

// shellsort: sort v[0]...v[n-1] into increasing order


#include <stdio.h>

void shellsort(int v[], int n)
{
	int gap, i, j, temp;

	for (gap = n / 2; gap > 0; gap /= 2)
		for(i = gap; i < n; i++)
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
				temp = v[j];
				v[j] = v[j+gap];
				v[j + gap] = temp;
			}
}


int main(int argc, char const *argv[])
{
	int v[] = {1, 3, 5, 2, 4, 6, 7, 9, 8};
	shellsort(v, sizeof(v) / sizeof(int));

	int i;
	printf("after shellsort \n");
	for (i = 0; i < sizeof(v) / sizeof(int); i++) {
		printf("%d ", v[i]);
	}
	printf("\n");

	return 0;
}

/*
kolya@asus ~/src/tcpl/3-Control_Flow $ ./shellsort 
after shellsort 
1 2 3 4 5 6 7 8 9 
*/