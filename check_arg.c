#include"header.h"
#include"prototype.h"

int check_arg(int argc)
{
	
	if(argc<3)
	{
		printf("Too few argument in command.....!!!!\n");
		exit(EXIT_FAILURE);
	}
	else if(argc>3)
	{
		printf("Too many argument to command.....!!!!\n");
		exit(EXIT_FAILURE);
	}
	return 1;
}
