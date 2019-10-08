#include "list.h"

void* remove_node_at(Node* head, int n){

    
  if(head != NULL){
      
    if(*head != NULL){

      Node iter = *head;
      int i = 0;
	
      while(iter->next != NULL && i < n){

	iter = iter->next;
	i++;

      }

      return remove_node(&iter);

    }

  }

  return NULL;

} 
