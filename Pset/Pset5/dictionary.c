#include<stdbool.h>
#include<strings.h>
#include<string.h>
#include<cs50.h>
#include<ctype.h>
#include<stdio.h>

#include "dictionary.h"

#define HASHTABLE_SIZE 65536

typedef struct node
{
	char word[LENGTH+1];
	struct node *next;
}node;

node* hash[HASHTABLE_SIZE];
int count=0;
bool var=false;

int hash_func(char *gen_hash)
{
	unsigned int index=0;
	for(int i=0,n=strlen(gen_hash);i<n;i++)
	{
		index=(index<<2)^gen_hash[i];
	}
	return index%HASHTABLE_SIZE;
}

bool check(const char* word)
{
	int len=strlen(word);
	char word_copy[len+1];
	for(int i=0;i<len;i++)
	{
		word_copy[i]=tolower(word[i]);
	}

	word_copy[len]='\0';

	int h=hash_func(word_copy);

	node* cursor=hash[h];

	while(cursor!=NULL)
	{
		if(strcmp(cursor->word,word_copy)==0)
		{
			return true;
		}
		else
		{
			cursor=cursor->next;
		}
	}
	return false;
}




