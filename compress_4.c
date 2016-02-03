#include"header.h"

#include"prototype.h"

int compress_4(int fd,char *ma,char *argv)
{	
	char ch;
	char *temp_name;
	int i,cf,count=1,j=1,k;
	unsigned char c='a',byt='a',temp,ctemp[3],stemp;
	temp_name=(char *)malloc(25);
	strcpy(temp_name,argv);
	temp_name=strcat(temp_name,"_comp");
	cf=open(temp_name,O_WRONLY|O_CREAT,0666);
	if(cf<0)	
	{
		perror("open");
		goto OUT;
	}
	lseek(fd,0,SEEK_SET);
	while(read(fd,&ch,1))
	{
		for(k=0;k<3;k++)
		{
			ctemp[k]=ctemp[k]^ctemp[k];
		}
		k=0;
		if(j%2==1)
		{
			c^=c;
			byt^=byt;
			if(!count)
				break;	
			for(i=0;*(ma+i)!=ch;i++);
							
			do
			{
				sprintf(&ctemp[k],"%d",(int)i%10);
				ctemp[k]=ctemp[k]-48;
				k++;
				i=i/10;
			}while(i);
			c=ctemp[2]*100+ctemp[1]*10+ctemp[0];
			
			c=c<<4;
			byt=byt|c;
			if(!read(fd,&ch,1))
			{	
				for(k=0;k<3;k++)
				{
					ctemp[k]=ctemp[k]^ctemp[k];
				}
				k=0;
				i=15;
				do
				{
					sprintf(&ctemp[k],"%d",(int)i%10);
					ctemp[k]=ctemp[k]-48;
					k++;
					i=i/10;
				}while(i);
				c=ctemp[2]*100+ctemp[1]*10+ctemp[0];
				byt=byt|c;
				print_bit(byt);
				printf("\n");
				write(cf,&byt,1);
				lseek(fd,1,SEEK_CUR);
				break;
			}
			lseek(fd,-1,SEEK_CUR);
			temp=byt;
		}
		else
		{
			c^=c;
			if(!count)
				break;	
			for(i=0;*(ma+i)!=ch;i++);
			do
			{
				sprintf(&ctemp[k],"%d",(int)i%10);
				ctemp[k]=ctemp[k]-48;
				k++;
				i=i/10;
			}while(i);
			c=ctemp[2]*100+ctemp[1]*10+ctemp[0];
			c=c-48;
			c=c<<4;
			c=c>>4;
			byt=temp|c;
			
			write(cf,&byt,1);
		}
		j++;
		
	}
	close(cf);
	return 0;
OUT:
	return -1;
}
