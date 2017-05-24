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

	int counter=0;
	BYTE buffer[512];
	char lname[10];
	FILE* temp=NULL;

	while(!feof(inptr))
	{
		if(buffer[0]==0xff&&buffer[1]==0xd8&&buffer[2]==0xff&&(buffer[3]==0xe0||buffer[3]==0xe1))
		{
			if(temp!=NULL)
			{
				fclose(temp);
			}
			sprintf(lname,"%03d.jpg",counter);
			temp=fopen(lname,"w");
			counter++;
			fwrite(buffer,sizeof(buffer),1,temp);
		}
	}

}

