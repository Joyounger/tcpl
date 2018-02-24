// date:17.6.14
// author: linyang <942510346@qq.com>


/*
Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at the price of more
tests outside.) Write a version with only one test inside the loop and measure the difference in run-time.
*/

#include <stdio.h>

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    //mid = (high + low)  2;

    while (high > low && x != v[(high + low) / 2]) {
        mid = (high + low) / 2;
        (x > v[mid]) ? (low = mid + 1): (high = mid - 1);
    }
    
    if (x != v[(high + low) / 2]) {
        return -1;
    } else {
        return (high + low) / 2;
    }
    
}

int main(int argc, char const *argv[])
{
    int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int x1 = 7; int x2 = 17;
    printf("binsearch %d in v[10] return %d\n", x1, binsearch(x1, v, 10));
    printf("binsearch %d in v[10] return %d\n", x2, binsearch(x2, v, 10));
    
    
    return 0;
}


/*
binsearch 7 in v[10] return 6
binsearch 17 in v[10] return -1
*/
