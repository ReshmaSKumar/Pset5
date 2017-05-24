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

	if(bf.bfType!=0x4d42||bf.bfOffBits!=54||bi.biSize!=40||bi.biBitCount!=24||bi.biCompression!=0)
	{
		fclose(outptr);
		fclose(inptr);
		fprintf(stderr,"Unsupported file format.\n");
		return 4;
	}

	fwrite(&bf,sizeof(BITMAPFILEHEADER),1,outptr);
	fwrite(&bi,sizeof(BITMAPINFOHEADER),1,outptr);

	int padding=(4-(bi.biWidth*sizeof(RGBTRIPLE))%4)%4;
	
	for(int i=0,biHeight=abs(bi.biHeight);i<biHeight;i++)
	{
		for(int j=0;j<biWidth;j++)
		{

			RGBTRIPLE triple;
			fread(&triple,sizeof(RGBTRIPLE),1,inptr);
		}
	}





}
