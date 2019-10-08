
#include "my.h"

 char* my_strnconcat(char* a, char* b, int n)
{

  if(n < 0)
    n = 0;

  if(a == NULL && b == NULL)
    return NULL;

  int astrlen = 0;
  if(a != NULL)
    astrlen = my_strlen(a);

  int bstrlen = 0;
  if(b != NULL)
    bstrlen = my_strlen(b);

  int newstrlen = astrlen + bstrlen;

  if(n < bstrlen)
    newstrlen = astrlen + n;

  char* newstr = (char*) malloc((newstrlen + 1) * sizeof(char));

  int i;

  for(i = 0; i < astrlen; i++)
    newstr[i] = a[i];

  for(; i < newstrlen; i++)
    newstr[i] = b[i - astrlen];

  return newstr;

}



