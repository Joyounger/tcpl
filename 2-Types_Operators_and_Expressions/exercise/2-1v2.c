// date:17.4.8
// author: linyang <942510346@qq.com>



/*
Exercise 2-1. Write a program to determine the ranges of char, short, int, and long variables, both
signed and unsigned, by printing appropriate values from standard headers and by direct computation.
Harder if you compute them: determine the ranges of the various floating-point types.
*/


#include <stdio.h>

int main(int argc, char const *argv[])
{
	{
		char a = 0, b;
		while(1) {
			b = a + 1;
			if (b > a) {
				a++;
				continue;
			} else {
				printf("maximum vlaue of char:%d\n", a);
				break;
			}
		}	
	}

	{
		signed char a = 0, b;
		while(1) {
			b = a + 1;
			if (b > a) {
				a++;
				continue;
			} else {
				printf("maximum vlaue of signed char:%d\n", a);
				break;
			}
		}		
	}

	{
		int a = 0, b;
		while(1) {
			b = a + 1;
			if (b > a) {
				a++;
				continue;
			} else {
				printf("maximum vlaue of int:%d\n", a);
				break;
			}
		}		
	}

	// 9223372036854775807
	{
		long a = 9223372036800000000, b; // 缩短耗时
		while(1) {
			b = a + 1;
			if (b > a) {
				a++;
				continue;
			} else {
				printf("maximum vlaue of long:%ld\n", a);
				break;
			}
		}		
	}

	{
		short a = 0, b;
		while(1) {
			b = a + 1;
			if (b > a) {
				a++;
				continue;
			} else {
				printf("maximum vlaue of short:%d\n", a);
				break;
			}
		}
	}

	{
		unsigned char a = 0, b;
		while(1) {
			b = a + 1;
			if (b > a) {
				a++;
				continue;
			} else {
				printf("maximum vlaue of unsigned char:%u\n", a);
				break;
			}
		}
	}

	{
		unsigned int a = 0, b;
		while(1) {
			b = a + 1;
			if (b > a) {
				a++;
				continue;
			} else {
				printf("maximum vlaue of unsigned int:%u\n", a);
				break;
			}
		}		
	}

	// 18446744073709551615
	{	
		unsigned long a = 18446744073700000000, b;
		while(1) {
			b = a + 1;
			if (b > a) {
				a++;
				continue;
			} else {
				printf("maximum vlaue of unsigned long:%lu\n", a);
				break;
			}
		}		
	}

	{
		unsigned short a = 0, b;
		while(1) {
			b = a + 1;
			if (b > a) {
				a++;
				continue;
			} else {
				printf("maximum vlaue of unsigned short:%u\n", a);
				break;
			}
		}		
	}

	{
		char a = 0, b;
		while(1) {
			b = a - 1;
			if (b < a) {
				a--;
				continue;
			} else {
				printf("minimum vlaue of char:%d\n", a);
				break;
			}
		}	
	}

	{
		signed char a = 0, b;
		while(1) {
			b = a - 1;
			if (b < a) {
				a--;
				continue;
			} else {
				printf("minimum vlaue of signed char:%d\n", a);
				break;
			}
		}	
	}

	{
		int a = 0, b;
		while(1) {
			b = a - 1;
			if (b < a) {
				a--;
				continue;
			} else {
				printf("minimum vlaue of int:%d\n", a);
				break;
			}
		}	
	}

	{
		long a = -9223372036800000000, b;
		while(1) {
			b = a - 1;
			if (b < a) {
				a--;
				continue;
			} else {
				printf("minimum vlaue of long:%ld\n", a);
				break;
			}
		}	
	}

	{
		short a = 0, b;
		while(1) {
			b = a - 1;
			if (b < a) {
				a--;
				continue;
			} else {
				printf("minimum vlaue of short:%d\n", a);
				break;
			}
		}	
	}

	return 0;
}


/*
64位系统下运行结果
kolya@asus ~/src/tcpl/2-Types_Operators_and_Expressions/exercise $ ./2-1v2
maximum vlaue of char:127
maximum vlaue of signed char:127
maximum vlaue of int:2147483647
maximum vlaue of long:9223372036854775807
maximum vlaue of short:32767
maximum vlaue of unsigned char:255
maximum vlaue of unsigned int:4294967295
maximum vlaue of unsigned long:18446744073709551615
maximum vlaue of unsigned short:65535
minimum vlaue of char:-128
minimum vlaue of signed char:-128
minimum vlaue of int:-2147483648
minimum vlaue of long:-9223372036854775808
minimum vlaue of short:-32768
*/