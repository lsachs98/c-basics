#include "list.h"

void empty_list(Node* head){

  while(count_s_nodes(*head) > 0)
    remove_node(head);

}
