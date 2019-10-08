#include "../../include/my.h"

int my_strrindex(char* str, char c)
{
 if(str == NULL || c == '\0')
    return -1;
  int found = -1;
  int i = 0;
  while(str[i] != '\0')
    {
      if(str[i] == c)
	{
	  found = i;
	}
      i++;
    }

  return found;
}
