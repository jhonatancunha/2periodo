#include<stdio.h>
#include<stdlib.h>

int* intercala_a(int* v1, int tam1, int* v2, int tam2){

  int tTot = tam1 + tam2;

  int* v5 = (int *) calloc(tTot, sizeof(int));

  int c = 0;

  for(int i = 0; i < tTot; i += 2){
    *(v5 + i) = *(v2 + c);
    *(v5 + i+1) = *(v1 + c);
    c++;
  }

  return v5;
}

void intercala_b(int* v1, int tam1, int* v2, int tam2, int* v3){

    int tot = tam1 + tam2;
    int c = 0;

    for(int i = 0; i < tot; i += 2){
      *(v3 + i) = *(v2 + c);
      *(v3 + i+1) = *(v1 + c);
      c++;
    }
}

int main(){
    int v1[3] = {2,4,6};
    int v2[4] = {3,5,7,9};
    int v3[7];
    int *v4;

    v4 = intercala_a(v1, 3, v2, 4);

    for(int i = 0; i < 7; i++){
      printf("%d, ", v4[i]);
    }

    printf("\n\n");

    intercala_b(v1, 3, v2, 4, v3);

    for(int i = 0; i < 7; i++){
      printf("%d, ", v3[i]);
    }

}
