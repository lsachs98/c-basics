#include "list.h"

void print_char(Node n){

  if(n == NULL){

    char* toPrint = (char*)malloc(sizeof(char)*5);
    toPrint = "NULL";
    my_str(toPrint);

  }

  char* ptr = (char*)(n->elem);
  my_char(*ptr);

}
