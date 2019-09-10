#include<stdio.h>
#include "TAD-matriz1.h"
void main(){

    Matriz* m1 = cria_matriz(6,2);//Cria uma matriz de ordem mxn
    Matriz* m2 = cria_matriz(2,4);//Cria uma matriz de ordem mxn


    addValor_matriz(m1,1);//Adiciona um valor na matriz

    addValor_matriz(m2,2);//Adiciona um valor na matriz
    printf("Printando matriz A:\n");
    print_Matriz(m1);//Printa a matriz informada
    printf("\n\n");
    printf("Printando matriz B:\n");
    print_Matriz(m2);//Printa a matriz informada

    //Atribui um valor para a matriz
    //retorna -1 caso falhe
    printf("\n\nAtribuindo valor a matriz B: ");
    int flag = matriz_atribui(m2, 0 , 0, 3);
    flag = matriz_atribui(m2, 1 , 2, 3);
    if(flag == -1){
      printf("Falha.\n");
    }{
      printf("Atribuido com Sucesso\n");
      printf("\nPrintando matriz oposta com valor atribuido: ");
      printf("\n\n");
      print_Matriz(m2);//Printando matriz
    }

    printf("\n\nAxB : ");
    Matriz *m3 = matriz_multiplica(m1,m2);//Multiplica uma matriz pela outra
    printf("\n\n");
    print_Matriz(m3);


    //Verifica se matriz e diagonal
    printf("\n\nVerificando se é A é diagonal: \n");
    int i1 = matriz_ehDiagonal(m1);//Retorna 1 se for diagonal
      if(i1 == 1){
        printf("M1 É DIAGONAL\n");
      }{
        printf("M1 NÃO É DIAGONAL\n");
      }

    //Verifica se matriz e diagonal
    printf("\n\nVerificando se é B é diagonal: \n");
    int i2 = matriz_ehDiagonal(m2);//Retorna 1 se for diagonal
    if(i2 == 1){
      printf("M2 É DIAGONAL\n");
    }{
      printf("M2 NÃO É DIAGONAL\n");
    }


    //Verifica se a matriz e identidade
    //Retornando 1 caso for verdadeiro
    printf("\n\nVerificando se AxB é identidade: ");
    int x = matriz_ehIdentidade(m3);
    if(x == 1){
      printf("É IDENTIDADE\n");
    }{
      printf("NÃO É IDENTIDADE\n");
    }

    //Criando matriz oposta
    printf("\n\nOposta de AxB: ");
    Matriz *mo = matriz_oposta(m3);
    printf("\n\n");
    print_Matriz(mo);//Printando matriz


    //Criando matriz transposta
    printf("\n\nTransposta de AxB: ");
    Matriz* mt = matriz_transposta(mo);
    printf("\n\n");
    print_Matriz(mt);//Printando matriz




    delete_Matriz(m1);
    delete_Matriz(m2);
    delete_Matriz(m3);
}
