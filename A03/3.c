#include<stdio.h>

void verify(float* nota, char* avaliacao){
    if(*nota < 6.0){
      *avaliacao = 'I';
    }else if(*nota >= 6.0 && *nota < 7.0){
      *avaliacao = 'C';
    }else if(*nota >= 7.0 && *nota < 9.0){
      *avaliacao = 'B';
    }else if(*nota >= 9.0){
      *avaliacao = 'A';
    }
}

char verificaChar(float nota){
  if(nota < 6.0){
    return 'I';
  }else if(nota < 7.0){
    return 'C';
  }else if(nota < 9.0){
    return 'B';
  }else if(nota <= 10.0){
    return 'A';
  }else{
    return 'X';
  }
}

void main(){
  float nota = 5;

      if(nota <= 10 && nota >= 0){
          char conceito = '\0';
          verify(&nota, &conceito);
          printf("Nota metodo SCANF: %c\n\n", conceito);
      }else{
        printf("ERRO!\n\n");
      }

      if(nota <= 10 && nota >= 0){
          printf("Nota metodo RETORNO: %c\n\n", verificaChar(nota));
      }else{
        printf("ERRO!\n\n");
      }

}
