#include "my.h"

char* my_strcat(char* dst, char* src)
{

  if(dst == NULL)
    return dst;

  int catlen = my_strlen(src);
  int catstart = my_strlen(dst);
  int i = 0;

  for(; i < catlen; i++)
    dst[i + catstart] = src[i];

  dst[i + catstart] = '\0';

  return dst;

}
