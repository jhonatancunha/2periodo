#include "encadeada.h"

void teste1(){
    Pilha* p = pilha_criar();
    pilha_push(p, 10);
    pilha_push(p, 20);
    pilha_push(p, 30);
    pilha_imprimir(p); // [30,20,10] (topo -> base)

    //p = pilha_destruir(p);

    //int* aux = pilha_pop1(p);
    //printf("\nAUX: %d\n", *aux);
    //pilha_imprimir(p);
    //pilha_pop2(p, aux);
    //printf("\nAUX: %d\n", *aux);
 //   pilha_imprimir(p);

   int pos = pilha_posicao(p, 20);
   printf("\nPOSICAO: %d\n", pos);

   int tamPilha = pilha_tamanho(p);
   printf("TAM/ PILHA %d\n", tamPilha);

   int v1[] = {1,2,3,4};
   int qtdInseridos = pilha_pushAll(p, v1, 4);
   printf("NUMEROS INSERIDOS: %d\n", qtdInseridos);
   pilha_imprimir(p);
   printf("\nTAM/ PILHA %d\n", pilha_tamanho(p));
   


    Pilha* p2 = pilha_clone(p);

//    pilha_imprimir(p2);


     pilha_inverter(p);
     pilha_imprimir(p);
}


int main(){
    teste1();

    
}