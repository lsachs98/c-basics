#include "my.h"

int my_strcmp(char* a, char* b)
{
  if(a == NULL && b == NULL)
    return 0;
  if(a == NULL)
    return -1;
  if(b == NULL)
    return 1;

  int astrlen = my_strlen(a);
  int bstrlen = my_strlen(b);

  if((astrlen - bstrlen) != 0)
    return astrlen - bstrlen;

  for(int charindex = 0; charindex < astrlen; charindex ++)
    {
      int charcomp = (int)a[charindex] - (int)b[charindex];
      if(charcomp != 0)
	return charcomp;
    }
  return 0;

}
