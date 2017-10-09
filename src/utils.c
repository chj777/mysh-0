#include "utils.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  	char* cmd1; // for malloc
	char* cmd2; // for numbering
	char* token;

	int i = 0; //word index
	int len;
	int num = 0;//default num

	len = strlen(command);

	//number of words (=argc)
	strcpy(cmd2, command);
	
	token = strtok(cmd2, " ");

	while(token!=NULL)
	{
		num++;
		token = strtok(NULL, " ");
	}
	*argc = num;

	//malloc
	*argv = (char**)malloc(sizeof(char*)*num);
	
	for(int k=0; k<num; k++)
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
	
	
	return;
}
