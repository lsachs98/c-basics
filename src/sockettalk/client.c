#define _POSIX_SOURCE
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#define h_addr h_addr_list[0] 

void error(const char *msg){

    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]){

  pid_t pid;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[256];
  char input[256];

  if (argc !=  3) {
    printf("Usage: ./client [host] [port]\n");
    exit(1);
  }

  int namelen = 0;

  while(namelen <= 0 || namelen >= 12){

    bzero(buffer, 256);
    printf("Please choose a username of under 12 characters: ");
    fgets(buffer,255,stdin);

    for(int i = 0; i < strlen(buffer); i++){

      if(buffer[i] != '\n' && buffer[i] != ' ' && buffer[i] != '	')
	namelen++;
    }

    if(namelen < 0 || namelen >= 12)
      bzero(buffer, 256);

  } 

  int portno = atoi(argv[2]);
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0) 
    error("ERROR opening socket");

  server = gethostbyname(argv[1]);

  if (server == NULL) {

    fprintf(stderr,"who is she\n");
    exit(0);
  }
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);

  serv_addr.sin_port = htons(portno);

  if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
    error("connect error");

  if(write(sockfd, buffer, 255) < 0) 
    error("username error\n");
        

  if((pid = fork()) < 0){
	        
    error("forking err\n");

  } else if(pid == 0){
	        
    while(1){

      bzero(input, 256);

      if(read(sockfd,input,255) < 0) 
	error("read error\n");

      printf("%s\n", input);

    }
  }else{

    while(1){
      fgets(buffer, 255, stdin);
      
      if(strncmp(buffer, "/exit", 5) == 0){
	close(sockfd);
	printf("bye bitchess\n");
	kill(0, SIGKILL);
	kill(1, SIGKILL);
      }
      if(write(sockfd, buffer, strlen(buffer)) < 0){
	kill(0, SIGKILL);
	error("write error");
      }
      bzero(buffer, 256);
    }
  }
  close(sockfd);
  return 0;
}
