#include "list.h"

void* remove_last(Node* head){

  if(head != NULL){

    if(*head != NULL){

      Node iter = *head;

      while(iter->next != NULL)
	iter = iter->next;

      Node* remPtr = (Node*) malloc(sizeof(struct s_node*));
      remPtr = &iter;

      return remove_node(remPtr);

    } 

  }

  return NULL;

}
