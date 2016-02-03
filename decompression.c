#include"header.h"
#include"prototype.h"

int decompression(char *argv,int fd)
{
	int ma,i=0,fdtemp,fdd,pos,cl;
	char *temp;
	temp=(char *)malloc(25);
	strcpy(temp,argv);
	for(i=strlen(temp);*(temp+i)!='_';i--);
	*(temp+i)='\0';
	temp=strcat(temp,"_temp");
	fdtemp=open(temp,O_RDONLY,0666);
	if(fdtemp<0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	for(i=strlen(temp);*(temp+i)!='_';i--);
		*(temp+i)='\0';
	fdd=open(temp,O_WRONLY|O_CREAT,0666);
	if(fdd<0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	pos=lseek(fdtemp,0,SEEK_END);
	cl=code_length(pos);
	for(i=0;pos>=pow(2,i)-1;i++)
	{
		if(pos==pow(2,i)-1)
		{
			cl++;
			break;
		}
	}
	switch(cl)
	{
		case 1:
//			decompress_1();
			break;		
		case 2:
			decompress_2(fd,fdd,fdtemp);
			break;		
		case 3:
			printf("In decompress 3\n");
			decompress_3(fd,fdd,fdtemp);
			break;		
		case 4:
			printf("In decompress 4\n");
			decompress_4(fd,fdd,fdtemp);
			break;		
		case 5:
			decompress_5(fd,fdd,fdtemp);
			break;		
		case 6:
			decompress_6(fd,fdd,fdtemp);
			break;		
		case 7:
			decompress_7(fd,fdd,fdtemp);
			break;		
	}
	return 0;
}
