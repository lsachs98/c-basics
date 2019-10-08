#include "my.h"

void my_int(int i)
{

  if(i < 0)
    my_char('-');
  
  else
    i*=-1;

  int divisor = -1;
  int countdigits = i;

  while(countdigits < -9){

    countdigits = countdigits / 10;
    divisor *= 10;

  }
  
  while(divisor < 0){

    int toprint = i / divisor;
    i = i % divisor;
    my_char(toprint + 48);
    divisor /= 10;

  }

}
