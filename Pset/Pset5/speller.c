#include<ctype.h>
#include<stdio.h>
#include<sys/resource.h>
#include<sys/time.h>

#include "dictionary.h"

#undef calculate
#undef getrusage

#define DICTIONARY "dictionaries/large"

double calculate(const struct rusage* b,const struct rusage* a);

int main(int argc,char* argv[])
{
	if(argc!=2 && argc!=3)
	{
		printf("Usage:speller [dictinary] text\n");
		return 1;
	}

	struct rusage before,after;

	double time_load=0.0,time_check=0.0,time_size=0.0,time_unload=0.0;

	char* dictionary=(argc==3)?argv[1]:DICTIONARY;

	getrusage(RUSAGE_SELF,&before);
	bool loaded=load(dictionary);
	getrusage(RUSAGE_SELF,&after);

	if(!loaded)
	{
		printf("Could not load%s.\n",dictionary);
		return 1;
	}

	 time_load=calculate(&before,&after);
	 char* text=(argc==3)?argv[2]:argv[1];

	FILE* fp=fopen(text,"r");
	if(fp==NULL)
	{
		printf("Could not open%s.\n",text);
		unload();
		return 1;
	}


	printf("\nMISSPELLED WORDS\n\n");

	int index=0,misspellings=0,words=0;
	char word[LENGTH+1];

	for(int c=fgetc(fp);c!=EOF;c=fgetc(fp))
	{
		if(isalpha(c)||(c=='\''&&index>0))
		{
			word[index]=c;
			index++;

			if(index>LENGTH)
			{
				while((c=fgetc(fp))!=EOF&&isapha(c));
				index=0;
			}
		}
		else
			if(isdigit(c))
			{
				while((c=fgetc(fp))!=EOF&&isalnum(c));
				index=0;
			}
			else if(index>0)
			{
				word[index]='\0';
				words++;
				getrusage(RUSAGE_SELF,&before);
				bool misspelled=!check(word);
				getrusage(RUSAGE_SELF,&after);
				time_check+=calculate(&before,&after);

				if(misspelled)
				{
					printf("%s\n",word);
					misspellings++;
				}
				index=0;
			}
	
	}


	


}




