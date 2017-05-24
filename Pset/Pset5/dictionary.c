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

bool load(const char* dictionary)
{
	for(int i=0;i<HASHTABLE_SIZE;i++)
	{
		hash[i]=NULL;
	}
	FILE* fp=fopen(dictionary,"r");
	if(fp==NULL)
	{
		printf("Could not open dictionary.\n");
		return false;
	}
	while(true)
	{
		node* new_node=malloc(sizeof(node));
		if(new_node==NULL)
		{
			printf("Could not malloc a new node.\n");
			return false;
		}

		fscanf(fp,"%s",new_node->word);
		node* head=hash[h];

		if(head==NULL)
		{
			hash[h]=new_node;
		}
		else
		{
			new_node->next=hash[h];
			hash[h]=new_node;
		}
	}
	fclose(fp);
	var=true;
	return true;
}

unsigned int size(void)
{
	if(var)
		return count;
	else 
		return 0;
}

bool unload(void)
{
	for(int i=0;i<HASHTABLE_SIZE;i++)
	{
		node* cursor=hash[i];
		while(cursor!=NULL)
		{
			node* temp=cursor;
			cursor=cursor->next;
			free(temp);
		}
	}
	var=false;
	return true;
}




