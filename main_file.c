#include"header.h"
#include"prototype.h"

int main(int argc,char * argv[])
{
	int fd;
	fd=open(argv[2],O_RDONLY,0666);
	if(fd<0)
	{
		perror("open");
		goto OUT;
	}	
	if(check_arg(argc))
	{
		operation(argv[1],argv[2],fd);
	}
	return 0;
OUT:
	return -1;
}
