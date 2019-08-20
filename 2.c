#include<stdio.h>

int contCaracter(int number){
  int cont = 0;
  do{
    number = number / 10;
    cont++;
  }while(number != 0);
  return cont;
}

int reverseNumber(int* number){
    int resp = *number % 10;
    *number = *number / 10;

    return resp;
}

void main(){
  int number = 123;
  int qtdCaracter = contCaracter(number);

  for(int i = 0; i < qtdCaracter; i++){
      int test = reverseNumber(&number);
      printf("%d", test);
  }
}
