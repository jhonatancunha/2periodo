#include <stdio.h>
#include <stdlib.h>

typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

typedef struct{
    Tipo* vetor;
    int tam;
    int qtde;
}Pilha;

Pilha* pilha_criar();
Boolean pilha_push(Pilha* p, Tipo elemento);
Tipo* pilha_pop1(Pilha* p);
Boolean pilha_pop2(Pilha* p, Tipo* end);
Pilha* pilha_destruir(Pilha* p);
void pilha_imprimir(Pilha* p);
int pilha_posicao(Pilha* p, Tipo elemento);
int pilha_tamanho(Pilha* p);

//FUNÇÕES ADICIONAIS
int pilha_pushAll(Pilha* p, Tipo* vetor, int tam);
void pilha_inverter(Pilha* p);
Pilha* pilha_clone(Pilha* p);

Pilha* pilha_criar(){
    Pilha* new = (Pilha*) malloc(sizeof(Pilha));
    new->vetor = (Tipo*) calloc(5, sizeof(Tipo));
    new->tam = 5;
    new->qtde = 0;

    return new;
}

Boolean pilha_push(Pilha* p, Tipo elemento){
    if(p->qtde >= p->tam || p == NULL) return false;

    p->vetor[p->qtde++] = elemento;
    return true;
}

Tipo* pilha_pop1(Pilha* p){
    if(p->qtde <= 0) return NULL;

    Tipo* aux = (Tipo*) malloc(sizeof(Tipo));
    aux = &p->vetor[p->qtde-1];
    free(&p->vetor[p->qtde-1]);
    p->qtde--;
    return aux;
}

Boolean pilha_pop2(Pilha* p, Tipo* end){ 
    if(p->qtde <= 0 || p == NULL) return false;

    *end = p->vetor[p->qtde-1];
    p->qtde--;
    return true;
}

Pilha* pilha_destruir(Pilha* p){
    if(p == NULL) return NULL;

    free(p->vetor);
    free(p);
    return NULL;
}

void pilha_imprimir(Pilha* p){
    if(p == NULL) return;

    for(int i = 0; i < p->qtde; i++){
        printf("%d, ", p->vetor[i]);
    }
    printf("\n");
}

int pilha_posicao(Pilha* p, Tipo elemento){
    if(p == NULL || p->qtde <= 0) return -1;

    for(int i = 0; i < p->qtde; i++){
        if(elemento == p->vetor[i]) return i;
    }

    return -1;
}

int pilha_tamanho(Pilha* p){
    if(p != NULL) return p->tam;
}

int pilha_pushAll(Pilha* p, Tipo* vetor, int tam){
    if(p == NULL) return -1;

    int i = 0;
    while(tam != 0){
        pilha_push(p, vetor[i++]);
        tam--;
    }

    return i;
}

void pilha_inverter(Pilha* p){
    if(p == NULL) return;
    
    Pilha* newPilha = pilha_criar();

    int i = p->qtde-1;
    int x= 0;
    while(i != -1){
        newPilha->vetor[x++] = p->vetor[i--];
    }
    free(p->vetor);
    p->vetor = newPilha->vetor;

}

Pilha* pilha_clone(Pilha* p){
    if(p == NULL) return NULL;
    
    Pilha* clone = pilha_criar();
    pilha_pushAll(clone, p->vetor, p->qtde);
    return clone;
}