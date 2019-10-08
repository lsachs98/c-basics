#include "my.h"

int my_strindex(char* str, char c)
{

  if(str == NULL || c == '\0')
    return -1;
  int i = 0;
  while(str[i] != '\0')
    {
      if(str[i] == c)
	{
	  return i;
	}
      i++;
    }
  return -1;
}
