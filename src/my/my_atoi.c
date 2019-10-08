#include "my.h"

int my_atoi(char* str){

  int i;
  int found = 0;
  int num = 0;
  int sign = 1;
  int strlen = my_strlen(str);

  for(i = 0; i < strlen; i++){

    if(str[i] == '-' && found == 0)
      sign *= -1;
    
    if((str[i] < '0' || str[i] > '9') && found == 1)
      return sign * num/10;

    if(str[i] >= '0' && str[i] <= '9'){

      found = 1;
      num += (str[i] - '0');
      num *= 10;

    }

  }

  return sign * num/10;
}
