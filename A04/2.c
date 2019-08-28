#include<stdio.h>
#include<stdlib.h>

int* vetor_novoA(int tam, int valor){
  int* vetor = (int*) calloc(tam, sizeof(int));

  for(int i = 0; i < tam; i++){
    *(vetor + i) = valor;
  }

  return vetor;
}

void vetor_novoB(int tam, int valor, int** v){
    *v = (int*) calloc(tam, sizeof(int));

    for(int i = 0; i < tam; i++){
      (*v)[i] = valor;
    }
}

void main(){
int *v1;
int *v2;

v1 = vetor_novoA(10, -1);
for(int i = 0; i < 10; i++){
  printf("%d, ", v1[i]);
}
free(v1);
printf("\n\n\n\n");

v1 = vetor_novoA(2, 0);
for(int i = 0; i < 2; i++){
  printf("%d, ", v1[i]);
}
free(v1);
printf("\n\n\n\n");

v1 = vetor_novoA(3, 41);
for(int i = 0; i < 3; i++){
  printf("%d, ", v1[i]);
}
free(v1);


printf("\n\n\n\n");

  vetor_novoB(5, 0, &v2);
  for(int i = 0; i < 5;i++){
    printf("%u, ", v2[i]);
  }
  free(v2);
printf("\n\n\n\n");
    vetor_novoB(2, 4, &v2);
    for(int i = 0; i < 2;i++){
      printf("%u, ", v2[i]);
    }
    free(v2);
printf("\n\n\n\n");
      vetor_novoB(5, 7, &v2);
      for(int i = 0; i < 5;i++){
        printf("%u, ", v2[i]);
      }
      free(v2);
      printf("\n\n\n\n");
}
