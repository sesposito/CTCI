#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* reverse(char* str);
void check(char* str);

int main(){

  char string[] = "abc";
  char* rev_str;

  printf("%s\n", string);
  rev_str = reverse(string);
  printf("%s\n", rev_str);

  return 0;

}

char* reverse(char* str){

  int len = strlen(str);
  char* reversed_string;
  int i, index;
  reversed_string = (char*) malloc(sizeof(char) * len);
  for(i = 0; i < len; i++){
    index = len-i-1;
    reversed_string[i] = str[index];
  }
  reversed_string[len] = '\0';

  return reversed_string;

}
