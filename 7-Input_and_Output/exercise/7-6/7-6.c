#include <stdio.h>

#define MAXLENGTH 1000


void cmp_file(FILE *fp1, FILE *fp2)
{
	char line1[MAXLENGTH + 1];
	char line2[MAXLENGTH + 1];

	while ((fgets(line1, MAXLENGTH, fp1) != NULL) && (fgets(line2, MAXLENGTH, fp2) != NULL)) {
		if (strcmp(line1, line2) != 0)
		{
			printf("line1--%s\n", line1);
			printf("line2--%s\n", line2);
			break;
		}
	}		
}


int main(int argc, char const *argv[])
{
	FILE* fp1 = fopen(argv[1], "r");
    FILE* fp2 = fopen(argv[2], "r");
    cmp_file(fp1, fp2);


	return 0;
}


/*
$ gcc -ansi -pedantic 7-6.c -o 7-6


$ ./7-6.exe chdir.txt chdir2.txt
line1--.\" manual under the conditions for verbatim copying, provided that the

line2--.\" mod-manual under the conditions for verbatim copying, provided that the

$ ./7-6.exe jenkins.txt jenkins-mod.txt
line1--Running from: C:\Users\kolya\jenkins.war

line2--mod-Running from: C:\Users\kolya\jenkins.war

*/