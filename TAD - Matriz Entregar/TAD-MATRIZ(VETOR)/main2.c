#include<stdio.h>
#include "TAD-matriz2.h"
void main(){

    Matriz* m1 = cria_matriz(6,2);//Cria uma matriz de ordem mxn
    Matriz* m2 = cria_matriz(2,2);//Cria uma matriz de ordem mxn


    addValor_matriz(m1,1);//Adiciona um valor na matriz

    addValor_matriz(m2,2);//Adiciona um valor na matriz
    printf("Printando matriz A:\n");
    print_Matriz(m1);//Printa a matriz informada
    // printf("\n\n");
    // printf("Printando matriz B:\n");
    // print_Matriz(m2);//Printa a matriz informada



    printf("\n\nPrintando matriz B com valor atribuido: \n");
    int x = matriz_atribui(m2, 0, 0, 3);
    int xxx = matriz_atribui(m2, 0, 1, 3);
    print_Matriz(m2);

    printf("\n\nAxB : ");
    Matriz *m5 = matriz_multiplica(m1,m2);//Multiplica uma matriz pela outra
    printf("\n\n");
    print_Matriz(m5);

    //Verifica se matriz e diagonal
    printf("\n\nVerificando se é A é diagonal: \n");
    int i1 = matriz_ehDiagonal(m1);//Retorna 1 se for diagonal
      if(i1 == 1){
        printf("A É DIAGONAL\n");
      }else{
        printf("A NÃO É DIAGONAL\n");
      }

    //Verifica se matriz e diagonal
    printf("\n\nVerificando se é B é diagonal: \n");
    int i2 = matriz_ehDiagonal(m2);//Retorna 1 se for diagonal
    if(i2 == 1){
      printf("B É DIAGONAL\n");
    }else{
      printf("B NÃO É DIAGONAL\n");
    }

    //Verifica se a matriz e identidade
    //Retornando 1 caso for verdadeiro
    printf("\n\nVerificando se B é identidade: ");
    int xx = matriz_ehIdentidade(m2);
    if(xx == 1){
      printf("É IDENTIDADE\n");
    }else{
      printf("NÃO É IDENTIDADE\n");
    }

    //Criando matriz transposta
    printf("\n\nTransposta de B: ");
    Matriz* mt = matriz_transposta(m2);
    printf("\n\n");
    print_Matriz(mt);//Printando matriz

    //Criando matriz oposta
    printf("\n\nOposta de transposta de B: ");
    Matriz *mo = matriz_oposta(mt);
    printf("\n\n");
    print_Matriz(mo);//Printando matriz

    printf("Acessando matriz \n\n");
    int opp;
    matriz_acessa2(m1, 2, 0, &opp);
    printf("%d\n\n",opp);


    //Atribui um valor para a matriz
    //retorna -1 caso falhe
    printf("\n\nAtribuindo valor a matriz: ");
    int flag = matriz_atribui(mo, 0 , 0, 5);
    if(flag == -1){
      printf("falha.\n");
    }else{
      printf("atribuido com sucesso\n");
      printf("\nPrintando matriz oposta com valor atribuido: ");
      printf("\n\n");
      print_Matriz(mo);//Printando matriz
    }

    printf("\n\nCopiando Linha");
    int tam = 0;
    int* p =  matriz_cloneLinha(mo, 1,&tam);
    printf("\n");
    for(int i = 0; i<tam;i++){
      printf("%d, ",p[i]);
    }


    printf("\n\nCopiando Coluna");
    int tama = 0;
    int* lop = matriz_cloneColuna(mo, 0,&tama);
    printf("\n");
    for(int i = 0; i<tam;i++){
      printf("%d\n",lop[i]);
    }


    delete_Matriz(m1);
    delete_Matriz(m2);
}
