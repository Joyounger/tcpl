// date:17.4.7
// author: linyang <942510346@qq.com>
// v1 by printing appopriate values from limits.h

/*
Exercise 2-1. Write a program to determine the ranges of char, short, int, and long variables, both
signed and unsigned, by printing appropriate values from standard headers and by direct computation.
Harder if you compute them: determine the ranges of the various floating-point types.
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(int argc, char const *argv[])
{
	printf("maximum vlaue of char:%d\n", CHAR_MAX);
	printf("maximum vlaue of signed char:%d\n", SCHAR_MAX);
	printf("maximum vlaue of int:%d\n", INT_MAX);
	printf("maximum vlaue of long:%ld\n", LONG_MAX);
	printf("maximum vlaue of short:%d\n", SHRT_MAX);
	printf("maximum vlaue of unsigned char:%u\n", UCHAR_MAX);
	printf("maximum vlaue of unsigned int:%u\n", UINT_MAX);
	printf("maximum vlaue of unsigned long:%lu\n", ULONG_MAX);
	printf("maximum vlaue of unsigned short:%u\n", USHRT_MAX);

	printf("minimum vlaue of char:%d\n", CHAR_MIN);
	printf("minimum vlaue of signed char:%d\n", SCHAR_MIN);
	printf("minimum vlaue of int:%d\n", INT_MIN);
	printf("minimum vlaue of long:%ld\n", LONG_MIN);
	printf("minimum vlaue of short:%d\n", SHRT_MIN);

	return 0;
}

/*
64位系统下运行结果
kolya@asus ~/src/tcpl/2-Types_Operators_and_Expressions $ ./2-1
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