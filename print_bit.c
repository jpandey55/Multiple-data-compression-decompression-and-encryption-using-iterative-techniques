#include"header.h"
#include"prototype.h"

int print_bit(unsigned char ch)
{
	int i=0;
	while(i<8)
	{
		if((ch&1)!=0)
		{
			printf("1 ");
		}
		else
		{
			printf("0 ");
		}
		ch=ch>>1;
		i++;
	}
	printf("\n");

}
