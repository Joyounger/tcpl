// date:17.6.14
// author: linyang <942510346@qq.com>


/*
Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. Explain
why. Use this observation to write a faster version of bitcount.
*/


#include <stdio.h>

int bitcount(unsigned x)
{
    int count = 0;
    
    while (x > 0) {
        x &= (x - 1);
        count++;
    }

    return count;
}

int main(int argc, char const *argv[])
{
    int i;
    for (i = 0; i < 64; i++) {
        printf("%d has %d 1-bits\n", i, bitcount(i));
    }
    
}

/*
0 has 0 1-bits
1 has 1 1-bits
2 has 1 1-bits
3 has 2 1-bits
4 has 1 1-bits
5 has 2 1-bits
6 has 2 1-bits
7 has 3 1-bits
8 has 1 1-bits
9 has 2 1-bits
10 has 2 1-bits
11 has 3 1-bits
12 has 2 1-bits
13 has 3 1-bits
14 has 3 1-bits
15 has 4 1-bits
16 has 1 1-bits
17 has 2 1-bits
18 has 2 1-bits
19 has 3 1-bits
20 has 2 1-bits
21 has 3 1-bits
22 has 3 1-bits
23 has 4 1-bits
24 has 2 1-bits
25 has 3 1-bits
26 has 3 1-bits
27 has 4 1-bits
28 has 3 1-bits
29 has 4 1-bits
30 has 4 1-bits
31 has 5 1-bits
32 has 1 1-bits
33 has 2 1-bits
34 has 2 1-bits
35 has 3 1-bits
36 has 2 1-bits
37 has 3 1-bits
38 has 3 1-bits
39 has 4 1-bits
40 has 2 1-bits
41 has 3 1-bits
42 has 3 1-bits
43 has 4 1-bits
44 has 3 1-bits
45 has 4 1-bits
46 has 4 1-bits
47 has 5 1-bits
48 has 2 1-bits
49 has 3 1-bits
50 has 3 1-bits
51 has 4 1-bits
52 has 3 1-bits
53 has 4 1-bits
54 has 4 1-bits
55 has 5 1-bits
56 has 3 1-bits
57 has 4 1-bits
58 has 4 1-bits
59 has 5 1-bits
60 has 4 1-bits
61 has 5 1-bits
62 has 5 1-bits
63 has 6 1-bits
*/
