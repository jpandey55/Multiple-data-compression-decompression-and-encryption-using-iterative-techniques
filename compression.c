#include"header.h"
#include"prototype.h"

int compression(char * argv2,int fd)
{
	char *ma;
	char *temp;
	int ndc,cl,cfd,i;
	ma=master_array(fd);
	cl=code_length(strlen(ma));
	temp=(char *)malloc(25*(sizeof(char)));
	strcpy(temp,argv2);
	printf("mastar array FOUNT : %d\n",strlen(ma));
	printf("CODE LENGTH FOUND : %d\n ",cl);
	temp=strcat(temp,"_temp");	
	cfd=open(temp,O_WRONLY|O_CREAT,0666);
	if(cfd<0)
	{
		perror("open");
		return -1;
	}
	write(cfd,ma,strlen(ma));
	for(i=0;strlen(ma)>=pow(2,i)-1;i++)
	{
		if((strlen(ma)==pow(2,i)-1))
		{	cl++;
			break;
		}
	}
	switch(cl)
	{
		case 2:
			printf("In compress 2\n");
			compress_2(fd,ma,argv2);
			break;
		case 3:
			printf("In compress 3\n");
			compress_3(fd,ma,argv2);
			break;
		case 4:
			printf("In compress 4\n");
			compress_4(fd,ma,argv2);
			break;
		case 5:
			printf("In compress 5\n");
			compress_5(fd,ma,argv2);
			break;
		case 6:
			compress_6(fd,ma,argv2);
			break;
		case 7:
			compress_7(fd,ma,argv2);
			break;
		default:
			printf("No need to compress...!!");
			exit(EXIT_SUCCESS);
	}
}
