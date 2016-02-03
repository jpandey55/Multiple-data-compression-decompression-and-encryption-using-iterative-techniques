#include"header.h"
#include"prototype.h"

int decompress_4(int fd,int fdd,int fdtemp)
{
	unsigned char ch,chtemp,temp,tempch;
	int i,j,count=1,pos;
	char *ma;
	pos=lseek(fdtemp,0,SEEK_END);
	printf("POSITION : %d\n",pos);
	ma=(char *)malloc(pos+1);
	lseek(fdtemp,0,SEEK_SET);
	read(fdtemp,ma,pos);
	while(read(fd,&ch,1))
	{
		count++;
		temp=ch;
		ch>>=4;
		j=ch;
		chtemp=*(ma+j);
		write(fdd,&chtemp,1);
		temp<<=4;
		temp>>=4;
		if((int)temp==15)
		{
			break;
		}
		j=temp;
		chtemp=*(ma+j);		
		write(fdd,&chtemp,1);
	}	
	
	return 0;
}
