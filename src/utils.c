#include "utils.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	//statement
	int num = 0;
	
	char* cpy = NULL;
	char* tok = NULL;

	//allocation
	cpy = (char*)malloc(100*sizeof(char));
	tok = (char*)malloc(100*sizeof(char));

	//copy
	strcpy(cpy, command);

	//allocation2
	*argv =(char**)malloc(100*sizeof(char*));
	**argv = (char*)malloc(100*sizeof(char));

	//tokenizing
	tok = strtok(cpy, "' ', \n, \t");

	if(tok == NULL)
	{
		*argc = 1;
		strcpy((*argv)[0],"");
	 	return;	
	}

	while(tok != NULL)
	{
		strcpy((*argv)[num], tok);
		*((*argv)+(++num)) = (char*)malloc(100*sizeof(char));
		tok = strtok(NULL, "' ',\n,\t");
	}
	
	//numbering
	*argc = num;

	//free
	free(tok);
	free(cpy);
	
	return ;
}
