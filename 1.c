#include<stdio.h>

int potencia(int num, int vezes){
  int r = 1;
  for(int i = 0; i < vezes; i++){
    r *= num;
  }
  return r;
}

void main(){

  int numero = 10;
  int vezes = 2;
  int resp = potencia(numero,vezes);

  printf("%d\n",resp);
}
