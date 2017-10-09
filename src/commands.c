#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "commands.h"

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
    return -1;
  

  int a;
  a= chdir(argv[1]);
  if(a == -1) return -1;


  return 0;
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;


  char *str;
  str = getcwd(NULL, 100);
  printf("%s", str);
  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  if(argc ==2 && strcmp(argv[0],"cd") == 0)
  	return 1;
  return 0;
}

int validate_pwd_argv(int argc, char** argv) {
  if(argc==1 && strcmp(argv[0],"pwd") == 0)
  	return 1;
  return 0;
}
