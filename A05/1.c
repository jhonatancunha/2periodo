#include<stdio.h>
#include<stdlib.h>

void vetor_cloneB(int* vetor, int tamanho, int** vetorFinal){
  int* dinamico = (int*) calloc(tamanho, sizeof(int));

  for(int i = 0; i < tamanho; i++){
    dinamico[i] = vetor[i];
  }

  *(vetorFinal) = dinamico;
}

int* vetor_cloneA(int* vetor, int tamanho){
  int* vMemoria = (int*) calloc(tamanho, sizeof(int));

  for(int i = 0; i < tamanho; i++){
    vMemoria[i] = vetor[i];
  }

  return vMemoria;
}

void main(){
    int v[5] = {2,4,6,8,10};
    int *copia1, *copia2;
    copia1 = vetor_cloneA(v, 5);

    printf("Vetor Original\n");
    for(int i = 0; i < 5; i++){
      printf("%d, ", v[i]);
    }

    printf("\n\n\n");

    printf("Vetor Clone\n");
    for(int i = 0; i < 5; i++){
      printf("%d, ", copia1[i]);
    }

    printf("\n\n\n");
    printf("Metodo SCANF\n\n");

    vetor_cloneB(v, 5, &copia2);
    for(int i = 0; i < 5; i++){
      printf("%d, ", copia2[i]);
    }
    printf("\n\nClone\n\n");
    for(int i = 0; i < 5; i++){
      printf("%d, ", v[i]);
    }
}
