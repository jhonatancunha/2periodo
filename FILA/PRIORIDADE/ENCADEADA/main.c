#include"filaEncadeadaPrioridade.h"

void teste1(){
    Fila* f1 = fila_cria();

    fila_inserir(f1, 5);
    fila_inserir(f1, 2);
    fila_inserir(f1, 10);
    fila_inserir(f1, 3);
    fila_inserir(f1, 1);
    fila_inserir(f1, 6);


     int primeiro;

    fila_imprimir(f1);
    
    int* removed = fila_remover1(f1);
    printf("\nRemovido: %d\n", *removed);
    removed = fila_remover1(f1);
    printf("\nRemovido: %d\n", *removed);
    removed = fila_remover1(f1);
    printf("\nRemovido: %d\n", *removed);
    removed = fila_remover1(f1);
    printf("\nRemovido: %d\n", *removed);
    fila_imprimir(f1);    

    fila_inserir(f1, 3);
    fila_inserir(f1, 1);
    fila_inserir(f1, 11);


    fila_imprimir(f1);  
    // fila_primeiro(f1, &primeiro);
    // printf("\nPrimeiro elemento da fila: %d\n", primeiro);

    // int removed2;
    // fila_remover2(f1, &removed2);
    // printf("\nRemovido: %d\n", removed2);
    // fila_imprimir(f1);

    // fila_primeiro(f1, &primeiro);
    // printf("\nPrimeiro elemento da fila: %d\n", primeiro);


    
    // f1 = fila_destruir(f1);
    // fila_imprimir(f1);
    
}

void main(){
    teste1();
}
