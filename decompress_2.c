#include"header.h"
#include"prototype.h"

int decompress_2(int fd,int fdd,int fdtemp)
{
	unsigned char ch,chtemp,temp,tempch,temp1,temp2;
	int i,j=1,count=1,pos,n=1;
	char *ma;
	pos=lseek(fdtemp,0,SEEK_END);
	printf("POSITION : %d\n",pos);
	ma=(char *)malloc(pos+1);
	lseek(fdtemp,0,SEEK_SET);
	read(fdtemp,ma,pos);
	while(read(fd,&ch,1))
	{
		temp1=ch;
		temp1=temp1>>6;
		chtemp=*(ma+(int)temp1);
		temp2=temp1;
		temp2=temp2<<2;
		temp2=temp2>>6;
		write(fdd,&chtemp,1);
		if(temp2==3)
			break;
		temp1=ch;
		temp1=temp1<<2;
		temp1=temp1>>6;
		chtemp=*(ma+(int)temp1);
		temp2=ch;
		temp2=temp2<<4;
		temp2=temp2>>6;
		write(fdd,&chtemp,1);
		if(temp2==3)
			break;
		temp1=ch;
		temp1=temp1<<4;
		temp1=temp1>>6;
		temp2=ch;
		temp2=temp2<<6;
		temp2=temp2>>6;
		chtemp=*(ma+(int)temp1);
		write(fdd,&chtemp,1);
		if(temp2==3)
			break;
		temp1=ch;
		temp=temp1<<6;
		temp1=temp1>>6;
		chtemp=*(ma+(int)temp1);
		write(fdd,&chtemp,1);
		
	}	
	
	return 0;
}
