#include "my.h"

char* my_strcpy(char* dst, char* src)
{

  if(dst == NULL)
    return NULL;

  if(src == NULL)
    return NULL;

  int copylen = 0;
  int srclen = my_strlen(src);
  int destlen = my_strlen(src);

  if(destlen >= srclen)
      copylen = srclen;

  else 
    copylen = destlen;

  int i;
  for(i = 0; i < copylen; i++)
    dst[i] = src[i];

  dst[i] = '\0';
 



  return dst;

}
