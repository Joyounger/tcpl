// date:17.4.7
// author: linyang <942510346@qq.com>

#include <stdio.h>

float temptrans(float fahr)
{
	float celisus = (5.0/9.0) * (fahr - 32.0);

	return celisus;
}


int main(int argc, char const *argv[])
{
	float fahr, celisus;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while(fahr < upper) {
		celisus = temptrans(fahr);
		printf("%3.0f %6.1f\n", fahr, celisus);
		fahr += step;
	}

	return 0;
}

