#include "utils.h"

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  // TODO: Fill this!
	char *token = NULL;
	char *token2 = NULL;
	argv = (char***)malloc(sizeof(char**));
	
	*argc = 0;
	
	token = strtok(command, " ");

	while(token != NULL){
		argc++;  		
		
	}

	printf("argc == %d\n", argc);

	return;

}
