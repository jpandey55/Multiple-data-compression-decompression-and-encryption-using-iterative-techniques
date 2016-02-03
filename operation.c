#include"header.h"
#include"prototype.h"

int operation(char * argv,char *argv2,int fd)
{
	if(!strcmp(argv,"--compress"))
	{
		compression(argv2,fd);
	}
	else if(!strcmp(argv,"--decompress"))
	{
		decompression(argv2,fd);
	}
	else
	{
		printf("%s : not a valid argument....!!!",argv);
	}
	return 0;
}
