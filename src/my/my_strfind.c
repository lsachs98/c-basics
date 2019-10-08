#include "my.h"

char* my_strfind(char* str, char c)
{

  if(str == NULL)
    return NULL;

  int strlen = my_strlen(str);

  if(c == '\0')
    return &str[strlen];

  for(int charindex = 0; charindex < strlen; charindex ++)
    {
      if(str[charindex] == c)
	return &str[charindex];
    }

  return NULL;

}
