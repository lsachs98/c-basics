#include "list.h"

void traverse_char(Node head){

  if(head != NULL){

    int numNodes = count_s_nodes(head);

    for(int i = 0; i < numNodes; i++)
      print_char(node_at(head, i)->elem);

  }
}
