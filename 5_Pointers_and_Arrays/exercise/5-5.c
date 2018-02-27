// date:17.6.26
// author: linyang <942510346@qq.com>


/*
Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp, which operate on
at most the first n characters of their argument strings. For example, strncpy(s,t,n) copies at most n
characters of t to s. Full descriptions are in Appendix B.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BUF 16

void ly_strncpy(char* src, const char* dst, int n);
void ly_strncat(char* src, const char* dst, int n) ;
int ly_strncmp(const char* src, const char* dst, int n);

void test_ncpy(const char *str) {
	char std_buf[MAX_BUF];
	char liw_buf[MAX_BUF];
	memset(std_buf, 0x42, sizeof(std_buf));
	strncpy(std_buf, str, sizeof(std_buf));
	memset(liw_buf, 0x42, sizeof(liw_buf));
	ly_strncpy(liw_buf, str, sizeof(liw_buf));
	if (memcmp(std_buf, liw_buf, sizeof(std_buf)) != 0) {
		fprintf(stderr, "liw_strncpy failed for <%s>\n", str);
		exit(EXIT_FAILURE);
	}
}

void test_ncat(const char *first, const char *second) {
	char std_buf[MAX_BUF];
	char liw_buf[MAX_BUF];
	memset(std_buf, 0x69, sizeof(std_buf));
	strcpy(std_buf, first);
	strncat(std_buf, second, sizeof(std_buf) - strlen(std_buf) - 1);
	memset(liw_buf, 0x69, sizeof(liw_buf));
	strcpy(liw_buf, first);
	ly_strncat(liw_buf, second, sizeof(liw_buf) - strlen(liw_buf) - 1);
	if (memcmp(std_buf, liw_buf, sizeof(std_buf)) != 0) {
		fprintf(stderr, "liw_strncat failed, <%s> and <%s>\n",
		first, second);
		exit(EXIT_FAILURE);
	}
}


void test_ncmp(const char *first, const char *second) {
	size_t len;
	int std_ret, liw_ret;
	if (strlen(first) < strlen(second))
		len = strlen(second);
	else
		len = strlen(first);
	std_ret = strncmp(first, second, len);
	liw_ret = ly_strncmp(first, second, len);
	if ((std_ret < 0 && liw_ret >= 0) || (std_ret > 0 && liw_ret <= 0) || (std_ret = 0 && liw_ret != 0)) {
		fprintf(stderr, "liw_strncmp failed, <%s> and <%s>\n",
		first, second);
		exit(EXIT_FAILURE);
	}
}


int main(int argc, char const *argv[])
{
	//test_ncpy("");
	//test_ncpy("a");
	test_ncpy("ab");
	test_ncpy("abcdefghijklmnopqrstuvwxyz"); /* longer than MAX_BUF */
	test_ncat("", "a");
	test_ncat("a", "bc");
	test_ncat("ab", "cde");
	test_ncat("ab", "cdefghijklmnopqrstuvwxyz"); /* longer than MAX_BUF */

	test_ncmp("", "");
	test_ncmp("", "a");
	test_ncmp("a", "a");
	test_ncmp("a", "ab");
	test_ncmp("abc", "ab");
	printf("All tests pass.\n");


	return 0;
}


void ly_strncpy(char* src, const char* dst, int n)
{

	while ((n-- > 0) && (*src++ = *dst++)) {
		
	}


	if ((n == 0) && (*dst != '\0'))  {
		*src = '\0';
	}

}

void ly_strncat(char* src, const char* dst, int n) 
{
	while (*src != '\0') {
		src++;
	}

	while(*dst != '\0' && (n-- > 0)) {
		*src = *dst;
		src++;
		dst++;
	}

	if ((n == 0) && (*dst != '\0'))  {
		*src = '\0';
	}	
}

int ly_strncmp(const char* src, const char* dst, int n)
{
	for (; (*src == *dst) && (n-- > 0); src++, dst++) {
		if (*src == '\0' || n == 0) {
			return 0;
		}
	}

	return *src - *dst;
}
