#include"header.h"
#include"prototype.h"

char *master_array(int fd)
{
	char ch;
	char *ma=NULL;
	int count=1,cnt=1,k=0,l,flag=0,ek;
	lseek(fd,0,SEEK_SET);
	while(count)
	{	
		flag=0;
		count=read(fd,&ch,1);
		printf("cnt=%d\n",cnt);
		for(l=0;l<k;l++)
		{
			if(ch==*(ma+l))
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{	ma=(char *)realloc(ma,(k+1));
			*(ma+k)=ch;
			k++;
		}
		cnt++;
	}
	*(ma+k)='\0';
	printf("Ma=");
	puts(ma);
	return ma;
}
