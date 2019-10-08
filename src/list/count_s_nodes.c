#include "list.h"

int count_s_nodes(Node head){

  if(head == NULL)
    return 0;

  Node iter = head;
  int i;

  for(i = 0; iter->next != NULL; i++)
    iter = iter->next;

  return i;

}
