// date:17.4.6
// author: linyang <942510346@qq.com>

#include <stdio.h>


int main(int argc, char const *argv[])
{
	double celsius = -17.8;
	double step = 11.1;

	int i;
	printf("%s\t%s\n", "fahr", "celsius");
	for (i = 0; i < 16; i++) {
		double fahrenheit = celsius * 9 / 5 + 32;
		printf("%.1f\t%.2f\n", celsius, fahrenheit);
		celsius += step;
	}

	return 0;
}


/*
kolya@asus ~/src/tcpl/1-A_Tutorial_Introduction $ ./1-4
fahr	celsius
-17.8	-0.04
-6.7	19.94
4.4	39.92
15.5	59.90
26.6	79.88
37.7	99.86
48.8	119.84
59.9	139.82
71.0	159.80
82.1	179.78
93.2	199.76
104.3	219.74
115.4	239.72
126.5	259.70
137.6	279.68
148.7	299.66
*/