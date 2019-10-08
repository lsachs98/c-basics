#include "list.h"
// I pledge my honor that I have abided by the Stevens Honor System
// Lauren Sachs

void add_node(Node n, Node* head){

  if(head != NULL && n != NULL){

    if(*head != NULL){

      n -> next = *head;
      *head = n;
	  
    }

    else{

      head = &n;
      *head = n;
      n->next = NULL;

    }

  }

  else if(n!=NULL){

    head = &n;
    n->next = NULL;

  }

}
