#include "list.h"

void add_node_at(Node toAdd, Node* head, int n){

  if(toAdd != NULL && toAdd->elem != NULL){

    if(head == NULL)
      head = &toAdd;
    
    else{

      if(*head == NULL)
	*head = toAdd;
      
      else{

	Node iter = *head;
	int i = 0;

	while(iter->next != NULL && i < n){

	  iter = iter->next;
	  i++;

	}

	toAdd->prev = iter;
	toAdd->next = iter->next;
	iter->next = toAdd->prev;

      }

    }

  }

} 
