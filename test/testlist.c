#include "list.h"
#include "my.h"

#ifndef NULL
#define NULL ((void*)0)
#endif

int *makeint(int x){

  int *temp = malloc(sizeof(int));
  *temp = x;
  return temp;
}

void appendtesta(Node* header, Node head){
  
  add_elem("appendnode", header);
  debug_string(head);
  //my_str("Current head node: "); print_string(*header);
  my_char('\n');
  
}

void addnodetest(Node* header){
  add_node(new_node("add2", NULL, NULL), header);
  debug_string(*header);
  my_str("Current head node: "); print_string(*header);
  my_char('\n');
  
}

void addelemtest(Node* header){
  add_elem(NULL, header);
  add_elem("addelem", NULL);
  add_elem("addelem", header);
  debug_string(*header);
  my_str("Current head node: "); print_string(*header);
  my_char('\n');
  
}

void appendtestb(Node* header){
  
  append(new_node("appendnode", NULL, NULL), header);
  debug_string(*header);
  my_str("Current head node: "); print_string(*header);
  my_char('\n');
  
}

void addnodeattest(Node* header){
  
  struct s_node* n2 = new_node("testingremove", NULL, NULL);
  add_node_at(NULL, header, 3);
  add_node_at(new_node("addatnullhead", NULL, NULL), NULL, 2);
  add_node_at(n2, header, 3);
  add_node_at(new_node("addAt-1",NULL, NULL), header, -1);
  debug_string(*header);
  my_char('\n');

}

void removenodetest(Node* header, Node n2){
  
  my_str(remove_node(&n2));my_char('\n');
  debug_string(*header);
  my_str("Current head node: "); print_string(*header);
  my_char('\n');
  
}

void removelasttest(Node* header){
  
  remove_last(header);
  debug_string(*header);
  my_str("Current head node: "); print_string(*header);
  my_char('\n');
  
}

void countsnodetest(Node* header){
  my_int(count_s_nodes(*header));my_char('\n');
  my_char('\n');
  
}

void removenodeattest(Node* header){
  
  my_str(remove_node_at(header, -11));my_char('\n');
  debug_string(*header);
  my_char('\n');
}

void elemattest(Node* header){
  
  my_str(elem_at(*header, 0));my_str(" -0\n");
  my_str(elem_at(*header, 1));my_str(" -1 \n");
  my_str(elem_at(*header, 33));my_str(" -33\n");
  my_str(elem_at(*header, -1));my_str(" negone\n");
  my_str(elem_at(new_node(NULL,NULL,NULL),0));
  my_str(" null elem\n");
  my_char('\n');
}

void nodeattest(Node* header){
  
  print_string(node_at(*header, 0));
  print_string(node_at(*header, -1));
  print_string(node_at(NULL, 0));
  print_string(node_at(*header, 30));
  print_string(node_at(new_node(NULL,NULL,NULL), 30));
  my_char('\n');
}

void debugtest(Node* header){
  
  debug_string(*header);
  debug_char(*header);
  debug_int(*header);
  my_char('\n');
}
void traversetest(Node* header){
  
  traverse_char(*header);
  traverse_int(*header);
  traverse_string(*header);
  my_char('\n');
  
}

void printinttest(){
  print_int(new_node(makeint(7), NULL, NULL));
  print_int(NULL);
  print_int(new_node(NULL, NULL, NULL));
  my_char('\n');
}


void printchartest(){
  print_char(new_node(makeint('1'),NULL,NULL));
  my_char('\n');
}
	
void printstringtest(){
	print_string(new_node("jjjjjjjjjjjj",NULL,NULL));
	my_char('\n');

}

void emptytest(Node* header){

	empty_list(header);
	debug_string(*header);
	my_char('\n');

}

int main(int argc, char const *argv[]){
	
  struct s_node* n2 = new_node("testingremove", NULL, NULL);
    
	struct s_node* head = NULL;
	new_node("ickt", NULL, NULL);
	struct s_node** header = &head;

	appendtesta(header,head);
	addnodetest(header);
	addelemtest(header);
	appendtestb(header);
	removenodetest(header, n2);
	addnodeattest(header);
	removenodetest(header, n2);
	removelasttest(header);
	countsnodetest(header);
	removenodeattest(header);
	elemattest(header);
	nodeattest(header);
	debugtest(header);
	traversetest(header);
	printinttest();
	printchartest();
	printstringtest();
	emptytest(header);

}
