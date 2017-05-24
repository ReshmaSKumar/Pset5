#include<stdio.h>
#include<stdlibh>
#include "bmp.h"

int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		fprintf(stderr,"Usage:./whodunit infile outfile.\n");
		return 1;
	}

	char *infile=argv[1];
	char *outfile=argv[2];

	FILE *inptr=fopen(infile,"r");
	if(inptr==NULL)
	{

		fprintf(stderr,"Could not open %s.\n",infile);
		return 2;
	}

	FILE *outptr=fopen(outfile,"w");
	if(ouptr==NULL)
	{
		fclose(inptr);
		fprintf(stderr,"Could not create %s.\n",outfile);
		return 3;
	}

	BITMAPFILEHEADER bf;
	fread(&bf,sizeof(BITMAPFILEHEADER),1,infile);
	BITMAPINFOHEADER bi;
	fread(&bi,sizeof(BITMAPINFOHEADER),1,infile);

}
