#include "my.h"

char* my_strrfind(char* str, char c)
{

  if(str == NULL)
    return NULL;

  int strlen = my_strlen(str);

  if(c == '\0')
    return &str[strlen];

  char* toReturn = NULL;

  for(int charindex = 0; charindex < strlen; charindex ++)
    {
      if(str[charindex] == c)
	toReturn = &str[charindex];
    }

  return toReturn;

}
