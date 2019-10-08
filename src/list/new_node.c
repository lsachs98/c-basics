#include "list.h"

Node new_node(void* elem, Node next, Node prev){

  if(elem != NULL){

      Node toAdd = (Node) malloc(sizeof(struct s_node));
      toAdd->elem = elem;
      toAdd->next = next;
      toAdd->prev = prev;
      return toAdd;

    }

  else return NULL;

}
