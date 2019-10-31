#include <stdio.h>
#include <stdlib.h>
#define SIZE_BEGIN 5


typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

typedef struct{
    Tipo* vetor;
    int tam;
    int inicio;
    int fim;
}Fila;


Fila* fila_criar();
void fila_destruir(Fila* f);

Boolean fila_inserir(Fila* f, Tipo elemento);
Tipo* fila_remover1(Fila* f);
Boolean fila_remover2(Fila* f, Tipo* endereco);

Boolean fila_primeiro(Fila* f, Tipo* endereco);
int fila_tamanho(Fila* f);
Boolean fila_contem(Fila* f, Tipo elemento);
void fila_imprimir(Fila* f);


/*
*CRIA UMA NOVA FILA CIRCULAR
*@RETURN O ENDEREÇO DESSA FILA
*/
Fila* fila_criar(){
    Fila* circular = (Fila*) malloc(sizeof(Fila));
    circular->vetor = (Tipo*) calloc(SIZE_BEGIN, sizeof(Tipo));
    circular->tam = SIZE_BEGIN;
    circular->inicio = 0;
    circular->fim = 0;
}
/*
*DESTROI A FILA CIRCULAR INFORMADA
*/
void fila_destruir(Fila* f){
    if(f == NULL) return;
    free(f->vetor);
    free(f);
}

/*
*DOBRA O TAMANHO DA FILA INFORMADA
*/
void dobraFila(Fila* f){
    Tipo* novaFila = (Tipo*) calloc(f->tam *2, sizeof(Tipo));
    f->tam *= 2;

    int i;
    int j = f->inicio;
    for(i = 0; i < f->tam/2; i++){
        j = (j+1 >= f->tam) ? 0 : j;
        novaFila[i] = f->vetor[j++];
    }
    
    free(f->vetor);
    f->vetor = novaFila;
    f->inicio = 0;
    f->fim = i-1;
}

/*
*INSERE UM ELEMENTO NO FINAL DA FILA
*@PARAM: F = FILA QUE DESEJA INSERIR O ELEMENTO INFORMADO
*@PARAM: ELEMENTO = É O TIPO A SER INSERIDO NO FINAL DA FILA
*@RETURN TRUE CASO FOR INSERIO, FALSE CASO NÃO FOR INSERIDO
*/
Boolean fila_inserir(Fila* f, Tipo elemento){
    if(f == NULL) return false;
    if( ((f->fim + 1) % f->tam) == f->inicio ) dobraFila(f);
    f->vetor[f->fim++] = elemento;
    return true; 
}

/*
*IMPRIME FILA CIRCULAR INFORMADA
*/
void fila_imprimir(Fila* f){
    if(f == NULL) return;

    int j = f->inicio;
    while(j != f->fim){
        j = ( ((f->fim + 1) % f->tam) == f->inicio ) ? 0 : j;
        printf("%d, ",f->vetor[j++]);
    }

}

/*
*RETORNA O TAMANHO DA FILA CIRCULAR INFORMADA
*RETORNA -1 FILA = NULL
*/
int fila_tamanho(Fila* f){
    return (f == NULL) ? -1 : f->tam;
}

/*
*RETORNA O PRIMEIRO INTEIRO PRESENTE NESSA FILA
*@PARAM: F = FILA QUE DESEJA PROCURAR
*@PARAM: ENDEREÇO = ONDE SERA ARMAZENADO ESSE VALOR
*@RETURN TRUE CASO EXISTIR PRIMEIRO NUMERO
*/
Boolean fila_primeiro(Fila* f, Tipo* endereco){
    if(f == NULL || f->tam <= 0) return false;
    *endereco = f->vetor[f->inicio];
    return true;
    
}

Boolean searchforTipo(Fila* f,Tipo elemento){
    int j = f->inicio;
    for(int i = 0; i < f->tam; i++){
        j = (j+1 >= f->tam) ? 0 : j;
        if(f->vetor[j++] == elemento) return true;
    }
    return false;
}

/*
*VERIFICA SE A FILA CONTEM O ELEMENTO INFORMADO
*@param f endereço de fila
*@parm elemento é o tipo a ser procurado nessa fila
*@return true caso valor exista no vetor
*/
Boolean fila_contem(Fila* f, Tipo elemento){
    if(f == NULL || f->tam <= 0) return false;
    return searchforTipo(f, elemento);
}

/*
*REMOVE O INICIO DA FILA
*@param f Endereco da fila
*@return endereço do tipo excluido
*/
Tipo* fila_remover1(Fila* f){
    if(f == NULL || f->tam <= 0) return NULL;
    Tipo* aux = (Tipo*) malloc(sizeof(Tipo));
    *aux = f->vetor[f->inicio++];

    return aux;
}

/*
*REMOVE O INICIO DA FILA
*@param f Endereco da fila
*@param endereco e aonde vai ser armazenado o tipo removido
*@return true caso numero for removido
*/
Boolean fila_remover2(Fila* f, Tipo* endereco){
    if(f == NULL || f->tam <= 0) return false;
    *endereco = f->vetor[f->inicio++];
    return true;
}