#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* string_clone(char* string){
  char* str = (char*) calloc(strlen(string)+1, sizeof(char));

  for(int i = 0; i < strlen(string); i++){
    strcpy(str,string);
  }

  return str;
}

void main(){
    char str[20] = "ABC";
    char* copia = string_clone(str);
    printf("%s\n", copia); //"ABC"
}
