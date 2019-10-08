#include "my.h"

char* my_strconcat(char* a, char* b)
{

  if(a == NULL && b == NULL)
    return NULL;

  int astrlen = 0;
  if(a != NULL)
    astrlen = my_strlen(a);

  int bstrlen = 0;
  if(b != NULL)
    bstrlen = my_strlen(b);

  int newstrlen = astrlen + bstrlen;

  char* newstr = (char*) malloc((newstrlen + 1) * sizeof(char));

  int i;

  for(i = 0; i < astrlen; i++)
    newstr[i] = a[i];

  for(; i < newstrlen; i++)
    newstr[i] = b[i - astrlen];

  return newstr;
}
