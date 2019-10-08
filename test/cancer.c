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

int myrevstrtest()
{
  assert(-1 == my_revstr(NULL));
  char* s = (char*) malloc(sizeof(char)*1);
  char* t = (char*) malloc(sizeof(char)*1);
  s = "";
  t = "";
  assert(0 == my_revstr(s));
  s = (char*) malloc(sizeof(char)*12);
  t = (char*) malloc(sizeof(char)*12);
  s = "hello world";
  strcpy(t, s);
  assert(11 == my_revstr(s));
  for(int i = 0; i < 11; i++)
    assert(t[i] == s[10 - i]);
  
  s = (char*) malloc(sizeof(char)*93);
  t = (char*) malloc(sizeof(char)*93);
  s = "hello world!!!!menxbjhbfhcjhbakejthbxknjnc bethvy hvybty4nceknthjrmkuebmnk4hbnjhcnbejhrhjteb";
  strcpy(t, s);
  my_revstr(s);
  for(int i = 0; i < 92; i++)
    assert(t[i] == s[91 - i]);

}

int main()
{
  //i hate myself and c
  return 0;

}

