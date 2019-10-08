#include "my.h"

int my_atoi(char* str){

  if(str == NULL)
    return -1;

  int num = 0;
  int sign = 1;
  int i = 0;
  int numfound = 0;

  while(str[i] != '\0'){
 
      int ascii = (int)str[i];
      my_int(ascii);
      if(ascii == 45 && numfound == 0)
	sign *= -1;
      if(ascii <= 55)
	my_int(ascii);
      
      if(ascii >= 0 && ascii < 10){
	num = num * 10 + ascii;
	numfound = 1;
      }
      else if(numfound == 1)
	return sign * num;

      i++;
    }

  if(numfound == 1)
    return num;

  return 0;

}
