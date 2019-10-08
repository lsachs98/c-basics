#include "my.h"

int my_strncmp(char* a, char* b, int n)
{
  if(a == NULL && b == NULL)
    return 0;
  if(a == NULL)
    return -1;
  if(b == NULL)
    return 1;

  if(n < 0)
    n = 0;

  int astrlen = my_strlen(a);
  int bstrlen = my_strlen(b);

  int minLen = astrlen;

  if(bstrlen < astrlen)
    minLen = bstrlen;


  for(int charindex = 0; charindex < minLen && charindex < n; charindex ++)
    {
      int charcomp = (int)a[charindex] - (int)b[charindex];
      if(charcomp != 0)
	return charcomp;
    }

  if((bstrlen - astrlen) != 0)
    return bstrlen - astrlen;

  return 0;

}
