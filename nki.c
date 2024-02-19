#include"nki.h"

char** read_nki_file()
{
  FILE* fp = fopen(".nki","r");

  //not a leak, we handle it later
  if(fp == NULL)
    {
      return NULL;
    }

  char** strings = malloc(sizeof(char*)*453);
  if(strings == NULL) return NULL;
  
  char* line   = NULL;
  size_t len   = 0;
  size_t read = 0;
  int i = 0;
  while ((read = getline(&line, &len, fp)) != -1)
    {
      strings[i] = malloc((sizeof(char)*len)+1);
      if(strings[i] == NULL) return NULL;
      strcpy(strings[i],line);
      ++i;
    }

  return strings;
}
