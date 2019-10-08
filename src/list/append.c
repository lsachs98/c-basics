#include "list.h"

void append(Node n, Node* head){

  if(n != NULL && n->elem != NULL){

    if(head == NULL)
      head = &n;

    else{

      if(*head == NULL)
	*head = n;
      
      else{

	Node iter = *head;

	while(iter->next != NULL){

	  iter = iter->next;

	}

	n->prev = iter;
	iter->next = n->prev;

      }

    }

  }

}
