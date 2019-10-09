#include<stdio.h>
#include "TAD-Vetor.h"

void soma(DataType* n){
  *n *= 2;
}


Boolean ehPar(DataType* ptr){return (*ptr % 2 == 0 ? true : false);}

int ordenaInt(int* n1, int*  n2){
  if(*n1 > *n2) return 1;
  else if(*n1 < *n2) return -1;
  else return 0;
  
}

int main(){

Vetor* v1 = vetor_new();

    vetor_insert(v1, 1, 0);
    vetor_insert(v1, 2, 1);
    vetor_insert(v1, 3, 2);
    vetor_insert(v1, 4, 3);
    vetor_add(v1, 10);
    vetor_add(v1, 11);
    vetor_add(v1, 12);
    vetor_add(v1, 13);
    vetor_add(v1, 14);
    vetor_add(v1, 10);
    vetor_insert(v1, 55, 0);

    vetor_print(v1);
    int dois;
    vetor_remove2(v1, 0, &dois);
    printf("Valor da posicao excluido: %d\n", dois);
    vetor_print(v1);
    int del1 = vetor_shift1(v1);
    printf("Valor da primeira posicao excluido: %d\n", del1);
    vetor_print(v1);
    int del2;
    vetor_get2(v1,1, &del2);
    printf("Valor da posicao: %d\n", del2);
    int* del3 = vetor_get3(v1, 2);
    printf("Valor da posicao: %d\n", *del3);
    vetor_print(v1);

    if(!vetor_set(v1, 55555, 5)){
      printf("Posição Invalida\n");
    }else{
      vetor_print(v1);
    }


  Vetor* sub = vetor_sub1(v1, -3);
  printf("\nSub vetor de V1\n");
  if(sub != NULL){
    vetor_print(sub);
  }else{
    printf("\nPosição invalido!\n");
  }

  Vetor* sub2 = vetor_sub2(v1, 3, 7);
   printf("\nSub vetor de V2\n");
  if(sub2 != NULL){
    vetor_print(sub2);
  }else{
    printf("\nPosição invalido!\n");
  }

  printf("\nSub-Vetor SUB1\n");

    Vetor* sub1s = vetor_sub1(sub2,-0);
    vetor_print(sub1s);
 

    printf("\nValor : %d\n", vetor_get1(sub1s, 2));
    int valor;
    vetor_get2(sub1s, 2, &valor);
    printf("Valor 2 : %d\n", valor);

    int* valor2 = vetor_get3(sub1s, 2);
    printf("Valor 3 : %d\n", *valor2);


    printf("Vetor V1 - Original\n");
    vetor_print(v1);

    printf("Vetor Filtado - Par\n");
    Vetor* filtroPar = vetor_filter(v1, ehPar);
    vetor_print(filtroPar);
    vetor_sort(filtroPar);
    vetor_print(filtroPar);


        printf("\nV1:\n");
    vetor_print(v1);
    printf("Ordenação Normal\n");
    vetor_sort(v1);
    vetor_print(v1);
    printf("Ordenação Generica - v1\n");
    vetor_genericSort(v1, &ordenaInt);
    vetor_print(v1);


  Vetor* v112 = vetor_new();

    int v = vetor_import(v112, "importado.txt");
    vetor_print(v112);
    printf("Foi adicionado o total de %d numeros.\n", v);

   printf("Tamanho vetor: %d\n", sizeof(v112));

    int qtdBytes = vetor_save(v112, "salvo.bin");
    if(qtdBytes != -1){
     printf("Quantidade de bytes salvas: %d.\n", qtdBytes);
   }else{printf("Erro na gravação!");}

  vetor_free(v112);

  Vetor* vLoad = vetor_load("salvo.bin");
  vetor_print(vLoad);

  return 0;
}
