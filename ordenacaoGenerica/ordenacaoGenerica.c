#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct{
    int cod;
    char nome[30];
    double preco;
}Produto;

/**************************************
 * BUBBLE SORT
 * ************************************/

void troca(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int* v, int n){
    int i, fim;
    for (fim = n-1; fim>0; fim--) {
        int houve_troca = 0;
        for (i=0; i<fim; i++){
            if (v[i]>v[i+1]) {
                troca(&v[i], &v[i+1]);
                houve_troca = 1;
            }
        }
        if (houve_troca == 0) return;
    }
}


/**************************************
 * FUNÇÕES GENÉRICAS DE COMPARACAO
 * ************************************/

int comparaChar(void* a, void* b){
    char* x = (char*)a; //100
    char* y = (char*)b; //104
    if(*x > *y) return 1;
    else if(*x < *y) return -1;
    else return 0;
}

int comparaProdutoPreco(void* a, void* b){
    Produto* x = (Produto*)a; //100
    Produto* y = (Produto*)b; //104
    if(x->preco > y->preco) return 1;
    else if(x->preco < y->preco) return -1;
    else return 0;
}

int comparaProdutoCodigo(void* a, void* b){
    Produto* x = (Produto*)a; //100
    Produto* y = (Produto*)b; //104
    if(x->cod > y->cod) return 1;
    else if(x->cod < y->cod) return -1;
    else return 0;
}

int comparaProdutoNome(void* a, void* b){
    Produto* x = (Produto*)a; //100
    Produto* y = (Produto*)b; //104
    if(x->nome > y->nome) return 1;
    else if(x->nome < y->nome) return -1;
    else return 0;
}

/**************************************
 * BUBBLE SORT GENÉRICO
 * ************************************/


int comparaInt(void* a, void* b){
    int* x = (int*)a; //100
    int* y = (int*)b; //104
    if(*x > *y) return 1;
    else if(*x < *y) return -1;
    else return 0;
}

void trocaGenerico(void* a, void* b, int tamElemento){
    void* temp = malloc(tamElemento); // int temp;

    memcpy(temp,a,tamElemento);
    memcpy(a,b,tamElemento);
    memcpy(b,temp,tamElemento);
    free(temp);
}


void bubble_generico(void* v, int n, int tamElemento, int (*funcao)(void* a, void* b)){
    //implementar

    for(int i = n-1; i >= 0; i--){
        int houve_troca = 0;
        for(int x = 0; x < i; x++){
            if(funcao(v+x*tamElemento,v+x*tamElemento+tamElemento ) == 1){
               //Implementar
              trocaGenerico(v+x*tamElemento,v+x*tamElemento+tamElemento, tamElemento);
              houve_troca = 1;
           }
        }
        if(houve_troca == 0) return;
    }    
}


void print(void* cont, int tamanhoVetor, int tamanhoDados, void (*imprime)(void* a)){
    printf("[");
    for(int i = 0; i < tamanhoVetor; i++){
        imprime(cont+i*tamanhoDados);
        if(i < tamanhoVetor-1) printf(",");
    }
    printf("]\n");
}

void printInt(void* numero){
    int* nConvertido = (int*) numero;
    printf("%d", *nConvertido);
}

void printChar(void* letra){
    char* letraConvertida = (char*) letra;
    printf("%c", *letraConvertida);
}

void printProduto(void* elemento){
    Produto* p = (Produto*) elemento;
    printf("{ %d, %s, %.2f }", p->cod, p->nome, p->preco);
}

/**************************************
 * MAIN
 * ************************************/

int main(){
    int v1[8] = {25,48,37,12,57,86,33,92}; //100
    
    Produto vp[5] = { // 300
        {5,"aa",5.5},
        {1,"bb",1.1},
        {4,"cc",4.4},
        {3,"dd",3.3},
        {2,"ee",2.2}
    };



    char vet_char[5] = {'x','d', 'e', 'a', 'r'}; //1000

    bubble_generico(v1, 8, sizeof(int), &comparaInt);
    bubble_generico(vp, 5, sizeof(Produto), &comparaProdutoCodigo);
    bubble_generico(vet_char, 5, sizeof(char), &comparaChar);


     print(v1, 8, sizeof(int), &printInt);
     print(vp, 5, sizeof(Produto), &printProduto);
     print(vet_char, 5, sizeof(char), &printChar);

}