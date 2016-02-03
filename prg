#include"header.h"
#include"prototype.h"

int main()
{
	unsigned char ch;
	int fd;
	fd=open("inputfile_comp",O_RDONLY);
	while(read(fd,&ch,1))
	{
		print_bit(ch);
	}
	return 0;
}
