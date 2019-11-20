#include<stdio.h>
#include"Lista_encadeada.h"



int main(){
    Lista* list = lista_criar();

   // lista_inserir(list, 2, 0);
    // printf("Primeira Inserção!\n");
    // printf("PRIMEIRO = %d\n", list->primeiro->dado);
    // printf("ULTIMO = %d\n\n", list->ultimo->dado);

   // lista_inserir(list, 3, 0);
     //printf("Segunda Inserção!\n");
    // printf("PRIMEIRO = %d\n", list->primeiro->dado);
    // printf("ULTIMO = %d\n\n", list->ultimo->dado);

     //lista_inserir(list, 4, list->qtde);
    // // printf("Terceira Inserção!\n");
    // // printf("PRIMEIRO = %d\n", list->primeiro->dado);
    // // printf("ULTIMO = %d\n\n", list->ultimo->dado);

    lista_inserir(list, 1, 0);
    lista_inserir(list, 2, 1);  
    lista_inserir(list, 3, 2);
    lista_inserir(list, 4, 3);
    lista_inserir(list, 5, 4);
    lista_inserir(list, 6, 3);
    lista_inserir(list, 99999, 0);
    lista_inserir_fim(list, 10);

   lista_imprimir(list);
   printf("\n\n");


    int procurado = 10;
    printf("POSICAO DO VALOR %d = %d\n", procurado, lista_posicao(list, procurado));

    if(lista_contem(list, procurado) == true) printf("VALOR %d ENCONTRADO\n", procurado);
    if(lista_contem(list, procurado) != true) printf("VALOR %d NÃO ENCONTRADO\n", procurado);

    int valor;
    int pos = 7;
    lista_buscar(list, pos, &valor);
    printf("VALOR BUSCADO NA POSICAO %d: %d\n",pos, valor);


    printf("TAMANHO DA LISTA: %d\n", lista_tamanho(list));
   
    Tipo* removed = lista_remover1(list, 0);
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

    lista_remover_elemento(list, 2);
    printf("\n");
    lista_imprimir(list);

    lista_remover_elemento(list, 10);
    printf("\n");
    lista_imprimir(list);

    lista_remover_elemento(list, 6);
    printf("\n");
    lista_imprimir(list);


    list = lista_destruir(list);
    printf("\n");
    lista_imprimir(list);

    return 0;
}