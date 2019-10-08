#include "list.h"

void add_elem(void* elem, Node* head){

  if(elem != NULL)
    add_node(new_node(elem, NULL, NULL), head);

}
