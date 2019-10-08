#include "list.h"

void debug_string(Node head){

 if(head != NULL){

    int numNodes = count_s_nodes(head);

     for(int i = 0; i < numNodes; i++){

      Node currNode = node_at(head, i);

      print_string(currNode->prev);
	
      char* toPrint = (char*)malloc(sizeof(char)*4);
      toPrint = "<- ";
      my_str(toPrint);

      print_string(currNode);

      toPrint = " ->";
      my_str(toPrint); 
      free(toPrint);     

      print_string(currNode->next);

    }

  }

}
