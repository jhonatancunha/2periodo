#include "contigua.h"



void teste1(){
    Pilha* p = pilha_criar();
    pilha_push(p, 10);
    pilha_push(p, 20);
    pilha_push(p, 30);
    pilha_imprimir(p); // [10,20,30] (base -> topo)
   // p = pilha_destruir(p);
    if(p != NULL){
        printf("Posicao: %d\n",pilha_posicao(p, 30));
        printf("Tamanho da pilha: %d\n", pilha_tamanho(p));

        pilha_inverter(p);
        pilha_imprimir(p);

        Pilha* clone = pilha_clone(p);

        int end;
        pilha_pop2(clone, &end);
        printf("RETIRADO: %d\n", end);

        pilha_imprimir(clone);
    }

}

int main(){
    teste1();
}