#include"header.h"
#include"prototype.h"

int compress_5(int fd,char *ma,char * argv)
{
	char * temp_name;
	int cf,j=1,i,k,n=1,chek=0,f;
	char ch;
	unsigned char c,byt,temp1,temp2,ctemp[3],temp3;
	temp_name=(char *)malloc(30);
	strcpy(temp_name,argv);
	strcat(temp_name,"_comp");
	cf=open(temp_name,O_WRONLY|O_CREAT,0666);
	lseek(fd,0,SEEK_SET);
	byt=byt^byt;
	while(read(fd,&ch,1))
	{	
		chek=0;
		for(k=0;k<3;k++)
			ctemp[k]=ctemp[k]^ctemp[k];
		k=0;
		c=c^c;
		for(i=0;*(ma+i)!=ch;i++);
		do
		{
			sprintf(&ctemp[k],"%d",(int)i%10);
			ctemp[k]=ctemp[k]-48;
			k++;

			i=i/10;			
		}while(i);
		c=ctemp[2]*100+ctemp[1]*10+ctemp[0];
		if(!read(fd,&ch,1))	
		{
			chek=1;	
			lseek(fd,1,SEEK_CUR);
		}
		lseek(fd,-1,SEEK_CUR);
		if(n%5==1)
		{
			if(j%2==1)
			{
				temp1=c;
				temp1=temp1<<3;
				byt=byt|temp1;
				if(chek)
				{
					k=0;	
					i=31;
					do
					{
						sprintf(&ctemp[k],"%d",(int)i%10);
						ctemp[k]=ctemp[k]-48;
						k++;
		
						i=i/10;			
					}while(i);
					c=ctemp[2]*100+ctemp[1]*10+ctemp[0];
					temp1=c;
					temp1=temp1<<3;
					temp1=temp2>>5;
					byt=byt|temp1;
					write(cf,&byt,1);
					temp1=c;
					temp1=temp1<<6;	
					write(cf,&temp1,1);	
					break;
				}
			}		
			else
			{
				temp2=c;
				temp1=c;
				temp1=temp1<<3;
				temp1=temp1>>5;
				byt=byt|temp1;
				write(cf,&byt,1);
				if(chek)
				{
					k=0;
					byt=byt^byt;
					temp1=c;
					temp1=temp1<<6;	
					byt=byt|temp1;
					i=31;
					do
					{
						sprintf(&ctemp[k],"%d",(int)i%10);
						ctemp[k]=ctemp[k]-48;
						k++;
		
						i=i/10;			
					}while(i);
					c=ctemp[2]*100+ctemp[1]*10+ctemp[0];
					temp1=c;
					temp1=temp1<<3;
					temp1=temp1>>2;
					byt=byt|temp1;
					write(cf,&byt,1);	
					break;
				}
				byt=byt^byt;
				n++;
			}

		j++;
		}
		else if(n%5==2)
		{
			if(j%2==1)
			{
				temp2=temp2<<6;
				byt=temp2|byt;
				temp1=c;
				temp1=temp1<<3;
				temp1=temp1>>2;
				byt=byt|temp1;
				if(chek)
				{	
					k=0;	
					i=31;
					do
					{
						sprintf(&ctemp[k],"%d",(int)i%10);
						ctemp[k]=ctemp[k]-48;
						k++;
		
						i=i/10;			
					}while(i);
					c=ctemp[2]*100+ctemp[1]*10+ctemp[0];
					temp1=c;
					temp1=temp1<<3;
					temp1=temp1>>7;
					byt=byt|temp1;
					write(cf,&byt,1);
					temp1=c;
					temp1=temp1<<4;	
					write(cf,&temp1,1);	
					break;
				}
			}
			else
			{
				temp1=c;
				temp2=c;
				temp1=temp1<<3;
				temp1=temp1>>7;
				byt=byt|temp1;
				write(cf,&byt,1);
				if(chek)
				{
					k=0;
					temp2=temp2<<4;	
					i=31;
					do
					{
						sprintf(&ctemp[k],"%d",(int)i%10);
						ctemp[k]=ctemp[k]-48;
						k++;
		
						i=i/10;			
					}while(i);
					c=ctemp[2]*100+ctemp[1]*10+ctemp[0];
					temp1=c;
					temp1=temp1<<3;
					temp1=temp1>>4;
					temp1=temp1|temp2;
					write(cf,&temp1,1);
					temp1=c;
					temp1=temp1<<7;
					write(cf,&temp1,1);	
					break;
				}
				byt=byt^byt;
				n++;
			}
		j++;
		}
		else if(n%5==3)
		{
			if(j%2==1)
			{
				temp1=temp2;
				temp1=temp1<<4;
				byt=byt|temp1;
				temp1=c;
				temp2=c;
				temp1=temp1<<3;
				temp1=temp1>>4;
				byt=byt|temp1;
				write(cf,&byt,1);
				if(chek)
				{
					k=0;
					temp2=temp2<<7;	
					i=31;
					do
					{
						sprintf(&ctemp[k],"%d",(int)i%10);
						ctemp[k]=ctemp[k]-48;
						k++;
		
						i=i/10;			
					}while(i);
					c=ctemp[2]*100+ctemp[1]*10+ctemp[0];
					temp1=c;
					temp1=temp1<<3;
					temp1=temp1>>1;
					temp1=temp1|temp2;
					write(cf,&temp1,1);	
					break;
				}
				n++;
				byt=byt^byt;
				j++;
			}
		j++;
		}
		else if(n%5==4)
		{
			if(j%2==1)
			{
				temp1=temp2;
				temp1=temp1<<7;
				byt=byt|temp1;
				temp1=c;
				temp1=temp1<<3;
				temp1=temp1>>1;
				byt=byt|temp1;
				if(chek)
				{	
					k=0;
					i=31;
					do
					{
						sprintf(&ctemp[k],"%d",(int)i%10);
						ctemp[k]=ctemp[k]-48;
						k++;
		
						i=i/10;			
					}while(i);
					c=ctemp[2]*100+ctemp[1]*10+ctemp[0];
					temp1=c;
					temp1=temp1<<3;
					temp1=temp1>>6;
					byt=byt|temp1;	
					write(cf,&byt,1);
					temp1=c;
					temp1=temp1<<5;
					write(cf,&byt,1);
					break;
				}
			}
			else
			{
				temp1=c;
				temp2=c;
				temp1=temp1<<3;
				temp1=temp1>>6;
				byt=byt|temp1;
				if(chek)
				{
					k=0;
					temp2=temp2<<5;		
					i=31;
					do
					{
						sprintf(&ctemp[k],"%d",(int)i%10);
						ctemp[k]=ctemp[k]-48;
						k++;
		
						i=i/10;			
					}while(i);
					c=ctemp[2]*100+ctemp[1]*10+ctemp[0];
					temp1=c;
					temp1=temp1<<3;
					temp1=temp1>>3;
					temp1=temp1|temp2;	
					write(cf,&temp1,1);	
					break;
				}
				write(cf,&byt,1);
				byt=byt^byt;
				n++;
			}
		j++;
		}
		else
		{
			if(j%2==1)
			{
				temp1=temp2;
				temp1=temp1<<5;
				byt=byt|temp1;
				temp1=c;
				temp1=temp1<<3;
				temp1=temp1>>3;
				byt=byt|temp1;
				write(cf,&byt,1);
				byt=byt^byt;
				n++;
				j++;
			}	
		j++;
		}
	}
	return 0;
}
