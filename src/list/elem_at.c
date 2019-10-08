#include "list.h"

void* elem_at(Node head, int n){

  if(head != NULL){

    Node nodeAt = node_at(head, n);
    return nodeAt->elem;

  }

  return NULL;

}
