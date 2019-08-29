#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int* vetor_aleatorio(int size){
  int* vHeap = (int*) calloc(size, sizeof(int));

  srand(time(NULL)); // Criar semente nova para alimentar o rand()

  for(int i = 0; i < size; i++){
    vHeap[i] = rand() % 10000; // Gerar valores aleatorios entre 0 e 10000
  }

  return vHeap;
}

void main(){
    int *v1 = vetor_aleatorio(10);
    int *v2 = vetor_aleatorio(100);

    for(int i = 0; i < 10; i++){
      printf("%d\n", v1[i]);
    }

}
