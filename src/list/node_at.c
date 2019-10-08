#include "list.h"

Node node_at(Node head, int n){

  if(head != NULL){

    Node iter = head;
    int i = 0;

    while(iter->next != NULL && i < n){

      iter = iter->next;
      i++;

    }

    return iter;

  }

  return NULL;

}
