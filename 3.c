#include<stdio.h>

void verify(float nota, char* avaliacao){
    if(nota < 6.0){
      *avaliacao = 'I';
    }else if(nota >= 6.0 && nota < 7.0){
      *avaliacao = 'C';
    }else if(nota >= 7.0 && nota < 9.0){
      *avaliacao = 'B';
    }else if(nota >= 9.0){
      *avaliacao = 'A';
    }
}

void main(){
  float nota = 9;

      if(nota <= 10 && nota >= 0){
          char conceito = '\0';
          verify(nota, &conceito);
          printf("%c", conceito);
      }else{
        printf("ERRO!");
      }
}
