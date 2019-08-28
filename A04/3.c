#include<stdio.h>
#include<stdlib.h>

int devolveIndice(int* vetor, int tam){

  int maior = vetor[0];
  int indice;
    for(int i = 0; i < tam; i++){
        if(vetor[i] > maior){
            maior = vetor[i];
            indice = i;
      }
  }

return indice;

}

void main(){
  int v1[] = {4,2,100,8,4,2,10,1,85};
  int maior = devolveIndice(v1,9);
  printf("%d\n", maior);

  int v2[] = {4,1,4,8,4,55,10,1,85};
  maior = devolveIndice(v2,9);
  printf("\n\n\n%d\n", maior);

  int v3[] = {4,2,0,8,4,2,10,1,5};
  maior = devolveIndice(v3,9);
  printf("\n\n\n%d\n", maior);
}
