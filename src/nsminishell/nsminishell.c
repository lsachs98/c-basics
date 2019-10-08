#include "my.h"
#include "list.h"
#include <sys/wait.h>
#include <unistd.h>
#include <ncurses.h>
#include <curses.h>
#include <stdio.h>

static pid_t cPid = 0;

void sigHandler(int sigNum){

  if(cPid > 0 && waitpid(cPid, NULL, WNOHANG)==0)
    kill(cPid, SIGINT);

}

int main(){

  char* filePath;
  filePath = getcwd(NULL, 0);
  signal(SIGINT, sigHandler);
  initscr();
  if(has_colors() == FALSE){	
    endwin();
    printf("Your terminal does not support color\n");
    exit(1);
  }
  start_color();	        
  init_pair(1, COLOR_CYAN, COLOR_BLACK);
  raw();
  keypad(stdscr, TRUE);
  Node head = NULL;
  Node clipboard = NULL;

  FILE *f = fopen(".nsmshistory", "w");
  if (f == NULL){
    printf("Error opening file!\n");
    exit(1);
  }

  if( fgets (str, 255, f)!=NULL ) {

      puts(str);
   }

  while(1){

    my_str("\nBAD BITCH MINISHELL: ");
    my_str(filePath);
    my_str(" $: ");
    char buff[256];
    char c;
    int cmdIndex = 0;

    for(int i = 0; i < 255; i++){
     
      if(c=getch() == 1){
	
	if(c=='\0' || c=='\n'){

	  buff[i] = '\0';
	  break;

	}
	else if(c == 0x03)
	  break;

	else if(c == KEY_UP){

	  cmdIndex ++;
	  if(void* toPrint = elem_at(&head,cmdIndex) != NULL){

	    puts((char*)toPrint);
	  }
	}
	else if(c == KEY_DOWN){
	  cmdIndex --;
	  if(cmdIndex >=0){

	    if(void* toPrint = elem_at(&head,cmdIndex) != NULL){
	      puts((char*)toPrint);
	    }
	  }

	}
	//backspace
	else if (c == '\b'){

	  printf(" \b");
	  fflush(stdout);

	}
	//ctrl L
	else if(c == 0x0C){

	  clear();
	  my_str("\nBAD BITCH MINISHELL: ");
	  my_str(filePath);
	  my_str(" $: ");
	  my_str(elem_at(&head,0));

	}

	//ctrl A
	else if(c == 0x01){

	}
	//ctrl E
	else if(c == 0x05){

	}
	//ctrl W
	else if(c == 0x17){


	}
	//ctrl U
	else if(c == 0x15){

	  add_elem((void*)buff,&clipboard);

	}
	//ctrl Y
	else if(c == 0x19){

	  puts((char*)elem_at(&clipboard,0));

	}

	else
	  buff[i] = c;
      }

      else
	break;

    }

    buff[255] = '\0';
    
    char** input = my_str2vect(buff);
    int err = 0;
    char* cmd = input[0];
    add_node((void*)cmd, &head);


    if (cmd == NULL) continue;
    else if(my_strcmp(cmd, "cd")==0){

      free(filePath);
      err = chdir(input[1]);
      filePath = getcwd(NULL, 0);

      if(err != 0){
	
	my_str("\n");
	my_str(input[1]);
	my_str(" is not a valid path. Try again pretty please.\n");

      }

    }

    else if(my_strcmp(cmd, "exit")==0){

      my_str("byeeeee bitches");
      exit(0);

    }

    else if(my_strcmp(cmd, "help") == 0){

      my_str("lmao you expect me to help you? \njk fine I will, you can exit using exit, change direcory with cd filepath and really anything else as long as it's normally valid idk I'm usually confuswed. Also you can ask for help.\n");

    }

    else{

      cPid = fork();

      if(cPid < 0){

	my_str("FORK ERROR\n");
	exit(1);

      }

      if(cPid > 0)
	wait(NULL);

      else{
	
	if(execvp(input[0], input) != 0){

	  my_str("???? bish wut");

	} 

      }

    }


  }

  Node* toRem = remove_node(&head);

  while(toRem != NULL){

    fputs((char*)toRem->elem);
    toRem = remove_node(&head);

  }

  fclose(f);

}
