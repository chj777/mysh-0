#include "utils.h"
#include "string.h"
#include "stdio.h"
#include "malloc.h"


void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  	char* cmd1; // for malloc
	char* cmd2; // for numbering
	char* token;

	int i = 0; //word index
	int len;

	argc = 0;//default num

	len = strlen(cmd);

	//number of words (=argc)
	strcpy(cmd2, command);
	
	token = strtok(cmd2, " ");

	while(token!=NULL)
	{
		argc++;
		token strtok(NULL, " ");
	}

	//malloc
	*argv = (char**)malloc(sizeof(char*)*argc);
	
	for(int k=0; k<argc; k++)
	{
		*argv[k] = (char*)malloc(sizeof(char)*len);
	}

	strcpy(cmd1, command);
	
	token = strtok(cmd1, " ");

	while(token != NULL)
	{
		strcpy(*((*argv) + i++),token);
		token = strtok(NULL, " ");
	}
	
	
	//print
	printf("argc == %d\n", argc);
	printf("argv == {");
	for(i=0; i<argc; i++)
	{
		printf(" \"%s\"", *argv[i]);
		if(i != argc-1)
		{
			printf(",");
		}
	}
	printf(" }");

	//free
	for(i=0; i<argc; i++)
	{
		if(0 == *argv[i])
		{
			free(*argv[i]);
			*argv[i] = 0;
		}
	}

	if( 0 == *argv)
	{
		free(*argv);
		*argv = 0;
	}

	return;
}
