#include<stdio.h>
#include<stdint.h>

typedef uint8_t BYTE;

int main(int argc,char *argv[])
{
	char *infile=argv[1];

	if(argc!=2)
	{
		fprintf(stderr,"Usage:./recover infile\n");
		return 1;
	}

	FILE *inptr=fopen(infile,"r");

	if(inptr==NULL)
	{
		fclose(inptr);
		fprintf(stderr,"Could not open %s.\n",infile);
		return 2;
	}


}

