#include<stdio.h>
#include<stdlib.h>

int vetor_dobraTamanho(int** vetor, int size){
  int* v2 = (int*) calloc(size*2, sizeof(int));

  for(int i = 0; i < 3; i++){
    v2[i] = **vetor+i;
//----->   v2[i] = *(vetor)[i];  <----- Porque desta maneira não funciona?     
  }

   free(*vetor);
   *vetor = v2;

  return size*2;
}

void main(){
    int* v = (int*) calloc(3, sizeof(int));
    v[0] = 2;
    v[1] = 4;
    v[2] = 6;



    int novoTamanho = vetor_dobraTamanho(&v,3);

    //Resultado esperado
    // [2,4,6,0,0,0]

    for(int i = 0; i < novoTamanho; i++){
      printf("%d, ", v[i]);
    }
}
