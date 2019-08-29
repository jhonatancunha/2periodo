#include<stdio.h>

void vetor_dobra(int* vetor, int size){
    for(int i = 0; i < size; i++){
      vetor[i] = vetor[i]*2;
    }
}

void main(){
    int v1[5] = {10,20,30,40,50};
    vetor_dobra(v1, 5); // [20,40,60,80,100]

    for(int i = 0; i < 5; i++){
      printf("%d\n", v1[i]);
    }

}
