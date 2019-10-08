#include "list.h"

void print_int(Node n){

  if(n == NULL)
    my_str("NULL");

  int* ptr = (int*)(n->elem);
  my_int(*ptr);

}
