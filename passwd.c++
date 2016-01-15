#define MIN_PASSWD_LEN 6
#define MAX_PASSWD_LEN 20
#define NO_OF_NUMBERS 1
#define NO_OF_UALPHABETS 1
#define NO_OF_LALPHABETS 1
#define NO_OF_SYMBOLS 1
#include<iostream>
#include"passwd.h"
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

passwd::passwd()
{
  pwd=(char **)malloc(sizeof(char*));
  pwd[0]=(char *)malloc(9);
  strcpy(pwd[0],"password");
}

passwd::passwd(const passwd &pswd)
{
  pwd=(char **)malloc(sizeof(char*));
  pwd[0]=(char *)malloc(strlen(*pswd.pwd)+1);
  strcpy(pwd[0],*pswd.pwd);
}

passwd::~passwd()
{
   free(pwd[0]);
   free(pwd);
}

void passwd::operator=(const passwd &pswd)
{
  pwd[0]=(char *)realloc(pwd[0],strlen(*pswd.pwd)+1);
  strcpy(pwd[0],*pswd.pwd);
}

bool passwd::check_validity()
{
  if(strlen(pwd[0])<=MAX_PASSWD_LEN&&strlen(pwd[0])>=MIN_PASSWD_LEN);
  else
    return false;
  int number_count=0,ualphabet_count=0,lalphabet_count=0,symbol_count=0;
    for(int i=0;i<strlen(pwd[0]);i++)
      { 
	if(pwd[0][i]<='9'&&pwd[0][i]>='0')
	  {
	    number_count++;
	  }
	else if(pwd[0][i]>='a'&&pwd[0][i]<='z')
	  {
	    lalphabet_count++;

	  }
	else if(pwd[0][i]>='A'&&pwd[0][i]<='Z')
	  {
	    ualphabet_count++;
	  }
	else if(pwd[0][i]>32&&pwd[0][i]!=127)
	  {
	    symbol_count++;
	  }
      }
    if(number_count>=NO_OF_NUMBERS&&ualphabet_count>=NO_OF_UALPHABETS&&lalphabet_count>=NO_OF_LALPHABETS&&symbol_count>=NO_OF_SYMBOLS)
      return true;
    else
      return false;
}

void passwd::tochar(char **pswd)
{
  *pswd=(char*)malloc(strlen(pwd[0])+1);
  strcpy(*pswd,pwd[0]);
}

void passwd::get()
{
  char *pswd;
  pswd=getpass("");
  pwd[0]=(char *)realloc(pwd[0],strlen(pswd)+1);
  strcpy(pwd[0],pswd);
}
