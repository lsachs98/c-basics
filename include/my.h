/* Header for libmy (Part 1) assignment. */ 
#ifndef _MY_H_ 
#define _MY_H_

#ifndef NULL 
#define NULL ((void*)0) 
#endif

#include <unistd.h> 
#include <stdlib.h>

char* my_strfind(char*, char);//gucci
char* my_strrfind(char*, char);//gucci
int my_strcmp(char*, char*); //gucci
int my_strncmp(char*, char*, int); //gucci
char* my_strcpy(char*, char*); //gucci
char* my_strncpy(char*, char*, int);//gucci
char* my_strcat(char*, char*); //gucci
char* my_strdup(char*); //gucci
char* my_strconcat(char*, char*); //gucci
char* my_strnconcat(char*, char*, int); //gucci
int my_atoi(char*); //gucci
void my_char(char); 
void my_str(char*); 
void my_int(int); 
void my_num_base(int, char*); 
void my_alpha(); //woohoo
void my_digits();
int my_strlen(char*); //gucci
int my_revstr(char*); //gucci
int my_strindex(char*, char); 
int my_strrindex(char*, char);
char *my_vect2str(char **); //gucci
char **my_str2vect(char*); //gucci

#endif
