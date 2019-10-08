#include "my.h"

char* my_vect2str(char** v){
 
  if(v == NULL)
    return NULL;

  if(*v == NULL)
    return my_strdup("");

  char* newStr = (char*) malloc(100*sizeof(char));
  my_strcpy(newStr, "");
 
  for(int i = 0; v[i] != NULL; i++){
  
    my_strcat(newStr, v[i]);
    if(v[i+1] != NULL)
      my_strcat(newStr, " ");
      
  }

  newStr[my_strlen(newStr)] = '\0';
 
  return newStr;

}
