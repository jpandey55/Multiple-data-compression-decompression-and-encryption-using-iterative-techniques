#include"header.h"
int code_length(int ndc)
{
	int l,i;
	for(i=2;i<8;i++)
	{
		if(ndc<pow(2,i))
			return i;
	}

}
