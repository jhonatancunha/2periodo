#include"matrizesparsa.h"

int main(){
    Matriz* esparsa = matriz_criar(4,4);
    matriz_atribuir(esparsa, 0,2,3);
   // matriz_atribuir(esparsa, 1,0,662);
    matriz_atribuir(esparsa, 0,1,20);
    matriz_atribuir(esparsa, 1,3,23);
    matriz_atribuir(esparsa, 1,2,2);
    matriz_atribuir(esparsa, 1,1,2);
    matriz_atribuir(esparsa, 0,3,63);
    matriz_atribuir(esparsa, 3,2,3);
    matriz_atribuir(esparsa, 3,3,13);
    matriz_imprimir(esparsa);

    //TESTANDO VALORES ANTES DE DESALOCAR
    int before = matriz_acessar(esparsa, 3,2);
    printf("POSICAO (3,2): %d\n", before);

    //DESALOCANDO
    matriz_desalocar(&esparsa);
    matriz_imprimir(esparsa);

    //TESTANDO VALORES DEPOIS DE DESALOCAR
    int after = matriz_acessar(esparsa, 3,2);
    printf("POSICAO (3,2): %d\n", after);

    return 0;
}