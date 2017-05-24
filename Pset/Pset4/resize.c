#include<stdio.h>
#include<stdlib.h>
#include "bmp.H"

int main(int argc,char *argv[])

{

	if(argc!=4)
	{
		fprintf(stderr,"Usage:./resize n infile outfile.\n");
		return 1;
	}

	char *n=argv[1];
	char *infile=argv[2];
	char *outfile=argv[3];

	int num=atoi(n);

	FILE *inptr=fopen(infile,"r");
	if(inptr==NULL)
	{
		fprintf(stderr,"Could not open %s.\n",infile);
		return 2;
	}

	FILE *outptr=fopen(outfile,"w");
	if(outptr==NULL)
	{
		fprintf(stderr,"Could not create %s.\n",outfile);
		return 3;
	}
}


