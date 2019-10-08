#include "list.h"

void print_string(Node n){

  if(n == NULL)
    my_str("NULL");

  char* ptr = (char*)(n->elem);
  my_str(ptr);

}
