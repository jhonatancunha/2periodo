#include<stdio.h>

void imprimeVetor(int* vetor, int tamanho){
  printf("[");
    for(int i = 0; i < tamanho; i++){
      *(vetor + i) = i+1;

        if(i < tamanho - 1){
          printf("%d, ", vetor[i]);
        }else{
          printf("%d", vetor[i]);
        }

    }
  printf("]\n");
}

void main(){
  int v[5];

  imprimeVetor(v, 5);
}
