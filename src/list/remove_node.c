#include "list.h"

void* remove_node(Node* toRemPtr){

  if(toRemPtr != NULL){

    Node toRem = *toRemPtr;

    if(toRem != NULL){

      if(toRem->prev != NULL)
	toRem->prev->next = toRem->next;

      toRemPtr = &(toRem->next); //in case of head being removed
      *toRemPtr = toRem->next;

      void* elem = toRem->elem;
      toRem->next = NULL;
      toRem->prev = NULL;
      toRem->elem = NULL;
      free(toRem);
      return elem;

    }

  }

 return NULL;

}

