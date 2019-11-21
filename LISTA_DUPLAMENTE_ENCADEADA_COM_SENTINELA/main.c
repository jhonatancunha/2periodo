#include<stdio.h>
#include"listaDuplamente_encadeadaSentinela.h"



int main(){
  Lista* list = lista_criar();
  lista_inserir(list, 1, 0);
  lista_inserir(list, 2, 1);  
  lista_inserir(list, 3, 2);  
  lista_inserir(list, 4, 3);  
  lista_inserir_fim(list, 5);
  lista_imprimir(list);

  int number = 5;
  int posicao = lista_posicao(list, number);
  printf("\nPosicao do elemento %d: %d é o seu indice!\n", number, posicao);

  if(lista_contem(list, number)) printf("A lista contém o numero %d!\n", number);
  if(!lista_contem(list, number)) printf("A lista não contém o numero %d!\n", number);

  Tipo endereco;
  int posicao2 = 0;
  lista_buscar(list, posicao2, &endereco);
  printf("POSICAO %d: contém o numero %d!\n",posicao2, endereco);
  
  printf("\nQTDE :%d\n", list->qtde);

  Tipo* removed = lista_remover1(list, 4);
  if(removed != NULL){
    printf("\nVALOR REMOVIDO: %d\n", *removed);
    lista_imprimir(list);
  }else{
    printf("\nERRO NA REMOÇÃO!\n");
  }


  int removed2;
  if(lista_remover2(list, 0, &removed2)){
    printf("\nVALOR REMOVIDO: %d\n", removed2);
    lista_imprimir(list);
  }else{
    printf("\nERRO NA REMOÇÃO!\n");
  }

  lista_remover_elemento(list, 4);
  printf("\n");
  lista_imprimir(list);

  lista_remover_elemento(list, 3);
  printf("\n");
  lista_imprimir(list);

  lista_remover_elemento(list, 2);
  printf("\n");
  lista_imprimir(list);


  list = lista_destruir(list);
  lista_imprimir(list);
  return 0;
}