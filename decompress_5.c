#include"header.h"
#include"prototype.h"

int decompress_5(int fd,int fdd,int fdtemp)
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
		if(j%5==1)
		{
			temp1=ch;
			temp1=temp1>>3;
			if(temp1==31)
				break;
			chtemp=*(ma+(int)temp1);
			write(fdd,&chtemp,1);
			temp2=ch;
			temp2=temp2<<5;
			temp2=temp2>>3;
		}
		else if(j%5==2)
		{
			temp1=ch;
			temp1=temp1>>6;
			temp1=temp1|temp2;
			if(temp1==31)
				break;
			chtemp=*(ma+(int)temp1);
			write(fdd,&chtemp,1);
			temp1=ch;
			temp1=temp1<<2;
			temp1=temp1>>3;
			if(temp1==31)
				break;
			chtemp=*(ma+(int)temp1);
			write(fdd,&chtemp,1);
			temp2=ch;
		}
		else if(j%5==3)
		{
			temp1=temp2;
			temp1=temp1<<7;
			temp1=temp1>>3;
			temp2=ch;
			temp2=temp2>>4;
			temp1=temp1|temp2;
			if(temp1==31)
				break;
			chtemp=*(ma+(int)temp1);
			write(fdd,&chtemp,1);
			temp2=ch;
		}
		else if(j%5==4)
		{
			temp1=temp2;
			temp1=temp1<<4;
			temp1=temp1>>3;
			temp2=ch;
			temp2=temp2>>7;
			temp2=temp2|temp1;
			if(temp1==31)
				break;
			chtemp=*(ma+(int)temp2);
			write(fdd,&chtemp,1);
			temp1=ch;
			temp1=temp1<<1;
			temp1=temp1>>3;
			if(temp1==31)
				break;
			chtemp=*(ma+(int)temp1);
			write(fdd,&chtemp,1);
			temp1=ch;
		}
		else
		{
			temp1=temp1<<6;
			temp1=temp1>>4;
			temp2=ch;
			temp2=temp2>>5;
			temp1=temp1|temp2;
			if(temp1==31)
				break;
			chtemp=*(ma+(int)temp1);
			write(fdd,&chtemp,1);
			temp1=ch;
			temp1=temp1<<3;
			temp1=temp1>>3;
			if(temp1==31)
				break;
			chtemp=*(ma+(int)temp1);
			write(fdd,&chtemp,1);
		}
	j++;
	}	
	
	return 0;
}
