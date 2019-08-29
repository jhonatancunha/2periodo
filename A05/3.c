#include<stdio.h>

void vetor_incrementa(int* vetor, int size){
  for(int i = 0; i < size; i++){
    vetor[i] = vetor[i]+1;
  }
}

void main(){
  int v1[5] = {10,20,30,40,50};
  vetor_incrementa(v1, 5); // [11,21,31,41,51]

  for(int i = 0; i < 5; i++){
    printf("%d, ", v1[i]);
  }
}
