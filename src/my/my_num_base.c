#include "my.h"
void my_num_base(int num, char* str){


  if(str == NULL || my_strlen(str) == 0){

    my_str("you're screwed, don't try and use a garbage base");
    return;

  }

  int base = my_strlen(str);

  if(base == 1){

      if(num < 0){

	  my_char('-');

	  for(int i = 0; i > num; i--)
	    my_char(str[0]);
	}
 
    for(int i = 0; i < num; i++)
      my_char(str[0]);
      
    return;

  }

  if(num == '\0')
    return;

  if(num < 0)
    my_char('-');

  else 
    num *= -1;

  int divisor = -1;
  int countdigits = num;

  while(countdigits < 1-base){

    countdigits = countdigits / base;
    divisor *= 10;

  }
  
  while(divisor < 0){

    int toprint = num / divisor;
    num = num % divisor;
    my_char(str[toprint]);
    divisor /= base;

  }

}




