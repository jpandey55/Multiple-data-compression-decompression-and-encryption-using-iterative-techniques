#include"header.h"
#include"prototype.h"

int compress_2(int fd,char *ma,char * argv)
{
	char * temp_name;
	int cf,j=1,i,k,n=1,chek=0;
	char ch;
	unsigned char c,byt,temp1,temp2,ctemp[3],tempch,chtemp;
	temp_name=(char *)malloc(24);
	strcpy(temp_name,argv);
	strcat(temp_name,"_comp");
	cf=open(temp_name,O_WRONLY|O_CREAT,0666);
	lseek(fd,0,SEEK_SET);
	byt=byt^byt;
	while(read(fd,&ch,1))
	{	
		c=c^c;
		chek=0;
		if(!read(fd,&chtemp,1))
		{
			chek=1;
			sprintf(&tempch,"%d",3);
			tempch=tempch-48;
			lseek(fd,1,SEEK_CUR);
		}
		lseek(fd,-1,SEEK_CUR);
		for(i=0;*(ma+i)!=ch;i++);
		sprintf(&c,"%d",i);
		c=c-48;
		if(j%4==1)
		{
			temp1=c;
			temp1=temp1<<6;
			byt=byt|temp1;
			if(chek)
			{
				tempch=tempch<<6;
				tempch=tempch>>2;
				byt=byt|tempch;
				write(cf,&byt,1);
				break;
			}	
		}
		else if(j%4==2)
		{
			temp1=c;
			temp1=temp1<<6;
			temp1=temp1>>2;
			byt=byt|temp1;
			if(chek)
			{
				tempch=tempch<<6;
				tempch=tempch>>4;
				byt=byt|tempch;
				write(cf,&byt,1);
				break;
			}	
		}
		else if(j%4==3)
		{
			temp1=c;
			temp1=temp1<<6;
			temp1=temp1>>4;
			if(chek)
			{
				tempch=tempch<<6;
				tempch=tempch>>6;
				byt=byt|tempch;
				write(cf,&byt,1);
				break;
			}	
			byt=byt|temp1;
		}
		else
		{
			temp1=c;
			temp1=temp1<<6;
			temp1=temp1>>6;
			byt=byt|temp1;
			write(cf,&byt,1);
			byt=byt^byt;
		}
	j++;	
	}
	return 0;
}
