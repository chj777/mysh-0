#include "utils.h"
#include "string.h"
#include "stdio.h"
#include "malloc.h"
void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  	char* c_copy; // command copy because it's const
  	int c_len; // command lenght(=col)
  	int c_num; // number of the command's words(=row)
  	char ***word; //each word alloc
	int i;
  	char* token = 0;
	char* nextTok = 0;

  	//1. copy the command and get the basic info.
  	strcpy(c_copy, command);
  	c_len = strlen(c_copy)-1;


  	c_num=1;
  	for(i=0; i<col; i++)
  	{
		if(c_copy[i] == ' ')
		{
			c_num++;
		}	
  	}	

  	word = (char**)malloc(sizeof(char*)*c_num);

  	for(i=0; i<c_num; i++)
  	{
  		word[i] = (char*)malloc(sizeof(char)*c_num);
  	}

  	word[0] = strtok(c_copy, " ", &nextTok);
  	for(i=1; i<row; i++)
  	{
  		if( 0 != *nextTok)
		{
			word[i] = strtok_s(NULL, " ", &nextTok);
		}
  	}
	
	printf("argc == %d\n", *c_num);
	printf("argv == {");
	for(i=0; i<c_num; i++)
	{
		printf(" \"%s\"", word[i]);
		if(i != c_num-1)
		{
			printf(",");
		}
	}
	printf(" }");

	//free
	for(i=0; i<c_num; i++)
	{
		if(0 == word[i])
		{
			free(word[i]);
			word[i] = 0
		}
	}

	if( 0 == word)
	{
		free(word);
		word = 0;
	}

	return;
}
