#include "list.h"

void debug_char(Node head){

 if(head != NULL){

    int numNodes = count_s_nodes(head);

     for(int i = 0; i < numNodes; i++){

      Node currNode = node_at(head, i);

      print_char(currNode->prev);
	
      char* toPrint = (char*)malloc(sizeof(char)*4);
      toPrint = "<- ";
      my_str(toPrint);

      print_char(currNode);

      toPrint = " ->";
      my_str(toPrint); 
      free(toPrint);     

      print_char(currNode->next);

    }

  }

}
