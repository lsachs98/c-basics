#include <limits.h>
#include <string.h>
#include <assert.h>
#include "my.h"

void mystrtest()
{
  my_char('\n');
  my_str(NULL);
  char* s = (char*) malloc(sizeof(char)*1);
  char* t = "";
  strcpy(s,t);
  my_char('\n');
  my_str(s);
  s = (char*) malloc(sizeof(char)*12);
  t = "hello world";
  strcpy(s,t);
  my_char('\n');
  my_str(s);
  s = (char*) malloc(sizeof(char)*120);
  t = "hello world!!!!menxbjhbfhcjhbakejthbxknjnc bethvy hvybty4nceknthjrmkuebmnk4hbnjhcnbejhrhjteb";
  strcpy(s,t);
  my_char('\n');
  my_str(s);

}

void myrevstrtest()
{
  my_char('\n');
  my_int(my_revstr(NULL));
  char* s = (char*) malloc(sizeof(char)*1);
  char* t = "";
  strcpy(s,t);
  my_char('\n');
  my_int(my_revstr(s));
  my_str(s);
  s = (char*) malloc(sizeof(char)*12);
  t = "hello world";
  strcpy(s,t);
  my_char('\n');
  my_int(my_revstr(s));
  my_str(s);
  s = (char*) malloc(sizeof(char)*93);
  t = "hello world!!!!menxbjhbfhcjhbakejthbxknjnc bethvy hvybty4nceknthjrmkuebmnk4hbnjhcnbejhrhjteb";
  strcpy(s,t);
  my_char('\n');
  my_int(my_revstr(s));
  my_str(s);

}

void mystrfindtest(){

  char* t;
  t = "hello world";
  assert(my_strfind(t, 'l')== &t[2]);
  assert(my_strfind(t, '\0')==&t[11]);
  assert(my_strfind(t, ' ')==&t[5]);
  assert(my_strfind(NULL, 'd')== NULL);

}

void mystrrfindtest(){

  char* t;
  t = "hello world";
  assert(my_strrfind(t, 'l')== &t[9]);
  assert(my_strrfind(t, '\0')==&t[11]);
  assert(my_strrfind(t, ' ')==&t[5]);
  assert(my_strrfind(NULL, 'd')== NULL);

}

void mystrcmptest(){

  char*t;
  t="hello world";
  assert(my_strcmp(t,"hello world") == 0);
  assert(my_strcmp(t, "iello world") < 0);
  assert(my_strcmp(t, "hallo world") > 0);
  assert(my_strcmp(NULL, NULL) == 0);
  assert(my_strcmp(t, NULL) > 0);

}
void mystrncmptest(){

  char*t;
  t="hello world";
  assert(my_strncmp(t,"hello world",11) == 0);
  assert(my_strncmp(t,"hello worelz",8) == 0);
  assert(my_strncmp(t, "iello world",11) < 0);
  assert(my_strncmp(t, "hallo world", 11) > 0);
  assert(my_strncmp(t, "hello worls",11) < 0);
  assert(my_strncmp(t, "hallo world", 1) == 0);
  assert(my_strncmp(t, "hallo world", 2) > 0);
  assert(my_strncmp(NULL, NULL, 5) == 0);
  assert(my_strncmp(t, NULL, 5) > 0);

}

void mystrcattest(){

  char t[17] = {"ay bb"};
  assert(my_strcmp(my_strcat(t, "hello world"), "ay bbhello world") == 0);
  assert(my_strcmp(my_strcat(t, ""), t) == 0);
  assert(my_strcmp(my_strcat(t, NULL), t) == 0);

}

void mystrcpytest(){

  char t[12] = {"hello worlds"};
  assert(my_strcmp(my_strcpy(t, "hello world"), "hello world") == 0);
  assert(my_strcmp(my_strcpy(t, "ick"), "ick") == 0);
  assert(my_strcmp(my_strcpy(t, ""), "") == 0);
  assert(my_strcmp(my_strcpy(t, NULL), NULL) == 0);

}

void mystrncpytest(){

  char t[6] = {"ay bb"};
  assert(my_strcmp(my_strncpy(t, "hello world",2), "he") == 0);
  assert(my_strcmp(my_strncpy(t, "",3), "") == 0);
  assert(my_strcmp(my_strncpy(t, NULL,2), NULL) == 0);

}

void mystrduptest(){

  assert(my_strcmp(my_strdup("hello"),"hello") == 0);
  assert(my_strcmp(my_strdup(""),"") == 0);
  assert(my_strcmp(my_strdup(NULL), NULL) == 0);

}

void mystrconcattest(){

  assert(my_strcmp(my_strconcat("hello","goodbye"), "hellogoodbye") == 0);
  assert(my_strcmp(my_strconcat("hello", ""), "hello") == 0);
  assert(my_strcmp(my_strconcat(NULL, "goodbye"), "goodbye") == 0);

}

void mystrnconcattest(){

  assert(my_strcmp(my_strnconcat("hello","goodbye", 4), "hellogood") == 0);
  assert(my_strcmp(my_strnconcat("hello", "", 11), "hello") == 0);
  assert(my_strcmp(my_strnconcat(NULL, "goodbye", 2), "go") == 0);

}

void myatoitest(){
  assert(my_atoi("5") == 5);
  assert(my_atoi("-5") == -5);
  assert(my_atoi("--5") == 5);
  assert(my_atoi("a-b54sc7-d") == -54);
  assert(my_atoi("abcd") == 0);
}

void mynumbasetest(){

  my_num_base(17549, "0123456789");
  my_str("\n");
  my_num_base(9, NULL);
  my_str("\n");
  my_num_base(9, "");
  my_str("\n");
  my_num_base(INT_MIN, "0123456789");
  my_str("\n");
  my_num_base(9, "R\tMo");
  my_str("\n");

}

int main(){

  mystrfindtest();
  mystrrfindtest();
  mystrcmptest();
  mystrncmptest();
  mystrcpytest();
  mystrncpytest();
  mystrcattest();
  mystrduptest();
  mystrconcattest();
  mystrnconcattest();
  myatoitest();
  mynumbasetest();
 
  return 0;
}
