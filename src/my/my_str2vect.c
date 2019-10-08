#include "my.h"

char** my_str2vect(char* str){

  if(str == NULL)
    return NULL;

  int strTrav = 0;
  int numWords = 0;

  while(str[strTrav] != '\0'){

    int next = strTrav;
    next++;

    if((str[strTrav] != ' ') && (str[strTrav] != '\n')){
      
      if((str[next] == ' ') || (str[next] == '\n')){

	numWords++;
	strTrav++;
      }

      else if(str[next] == '\0')
	numWords++;

    }

    strTrav++;

  }

  char** vect = (char**)malloc((numWords + 1)*sizeof(char*));
  vect[numWords] = NULL;

  strTrav = 0;
  int vectTrav = 0;
  int strLen = 0;
  
  while(str[strTrav] != '\0'){

    int next = strTrav;
    next++;

    if((str[strTrav] != ' ') && (str[strTrav] != '\n')){

      if((str[next] == ' ') || (str[next] == '\n') || (str[next] == '\0')){

	strLen++;
	vect[vectTrav] = (char*)malloc((strLen+1)*sizeof(char));

	for(int i = 0; i < strLen; i++)
	  vect[vectTrav][i] = str[strTrav - strLen + i + 1];

	vect[vectTrav][strLen] = '\0';

	strLen = 0;
	vectTrav++;

	if(str[next] != '\0')
	  strTrav++;

      }

      else
	strLen++;

    }
   
    strTrav++;

  }


  return vect;

}
