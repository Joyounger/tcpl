// date:17.4.9
// author: linyang <942510346@qq.com>

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define PERMS 0666
#define BUFSIZE 1024

int main(int argc, char *argv[])
{
	int fd1;
	int n;
	char buf[BUFSIZE];
	
	if (argc != 2)
	{
		printf("usage: cat file\n");	
	}
	
	
	fd1 = open(argv[1], O_RDONLY, 0);
	n = read(fd1, buf, BUFSIZE);
	write(1, buf, n);
	

	close(fd1);
	
	return 0;
}



