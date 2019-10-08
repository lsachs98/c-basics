#include <stdio.h>
#include <signal.h>
#include <sys/select.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include "my.h"

void error(const char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]){

  socklen_t clilen;
  char input[256];
  fd_set readfds;
  int fdarray[1024];
  char unarray[1024][15];
  int curr;
  char temp[256];
  
  if (argc !=  2) {

    printf("please enter in the form: ./server [port]\n");
    exit(1);

  }

  int sockfda = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfda < 0) 
    error("ERROR opening socket");

  int opt = 1;

  if(setsockopt(sockfda, SOL_SOCKET, SO_REUSEADDR,(char*)&opt, sizeof(opt)) < 0)
    error("socket opt error\n");
  
  struct sockaddr_in serv_addr, client_addr;

  bzero((char *) &serv_addr, sizeof(serv_addr));
  int portno = atoi(argv[1]);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  if (bind(sockfda, (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
    error("bind error\n");

  my_str("binding...\n");

  if(listen(sockfda,5) < 0)
    error("cant't listen\n");

  int sockfdb;

  my_str("listening...\n");

  clilen = sizeof(client_addr);

  while(1){

    FD_ZERO(&readfds);
    FD_SET(sockfda, &readfds);
    int max = sockfda;

    for(int x = 0; x < 1024; x++){

      if(fdarray[x] != 0)
	FD_SET(fdarray[x], &readfds);
      
      if(fdarray[x] > max){
	max = fdarray[x];
      }
    }
    if(select(max+1, &readfds, 0, 0, 0) < 0){
      error("select error\n");
    }
    
    if(FD_ISSET(sockfda, &readfds)){
      sockfdb = accept(sockfda,(struct sockaddr *) &client_addr,&clilen);

      if(sockfdb < 0) 
	error("error accepting child");
      
      bzero(input, 256);
      if(read(sockfdb, input, 255) < 0) 
	error("child read");

      printf("new friend: %s\n", input);

      for(int ind = 0; ind < 1024; ind++){

	if(fdarray[ind] == 0){
	  fdarray[ind] = sockfdb;
	  strncpy(unarray[ind], input, 14);
	  bzero(input, 256);
	  break;
	}
      }
      
    }
    for(int xx = 0; xx < 1024; xx++){
      curr = fdarray[xx];
      if(FD_ISSET(curr, &readfds)){
	int r = read(curr, input, 255);
	if(r < 0) error("child reading error\n");
	if(r == 0){
	  fdarray[xx] = 0;
	  break;
	}
	printf("%s\n", input);	
	if(input[0] == '/'){
        
	  if(strncmp(input, "/exit", 5) == 0){
	  
	    close(curr);
	    fdarray[xx] = 0;
	  }else if(strncmp(input, "/nick ", 6) == 0){
	  
	    int len = 0;
	    for(int g = 0; g < strlen(&(input[6])); g++){
	      if(input[g+6] != '\n' && input[g+6] != ' ' && input[g+6] != '	'){
		len++;
	      }
	    }
	    if(len > 0){

	      bzero(unarray[xx], 15);
	      strncpy(unarray[xx], &(input[6]), 14);
	      strcat(unarray[xx], "\0");

	      if(write(curr, "namechange \n", 14) < 0) 
		error("fuuck\n");

	    }else{
	      if(write(curr, "nah son no new names\n", 20) < 0) 
		error("name change err\n");
	    }
	  }else if(strncmp(input, "/me ", 4) == 0){
	    //me
	    for(int i = 0; i < 1024; i++){
	      if(fdarray[i] != 0 && fdarray[i] != curr){
		bzero(temp, 256);
		strcpy(temp, strtok(unarray[xx], "\n"));
		strcat(temp, " ");
		strcat(temp, strtok(&(input[5]), "\n"));
		if(write(fdarray[i], temp, 255) < 0) 
		  error("fuuck\n");
	      }
	    }
	  }else
	    write(curr, "Invalid command.", 16);
	  
	}else{
	  for(int i = 0; i < 1024; i++){
	    if(fdarray[i] != 0){
	      bzero(temp, 256);
	      strcpy(temp, strtok(unarray[xx], "\n"));
	      strcat(temp, ": ");
	      strcat(temp, strtok(input, "\n"));
	      if(write(fdarray[i], temp, 255) < 0) error("well shit\n");
	    }
	  }
	}
	bzero(input, 256);
      }
    }
    
  }
  close(sockfdb);
  close(sockfda);
  return 0; 
}
