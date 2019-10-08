#include "my.h"

char* my_strncpy(char* dst, char* src, int n)
{

  if(n < 0)
    n = 0;

  if(dst == NULL)
    return NULL;

  if(src == NULL)
    return NULL;

  if(n == 0)
    return NULL;

  int copylen = 0;
  int srclen = my_strlen(src);
  int destlen = my_strlen(dst);



  if(srclen >= n)
    copylen = n;

  else 
    copylen = destlen;

  int i;
  for(i = 0; i < copylen && i < n; i++)
    dst[i] = src[i];

  dst[i] = '\0';
 



  return dst;

}
