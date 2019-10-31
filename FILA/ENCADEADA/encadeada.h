#include <stdio.h>
#include <stdlib.h>



typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

/**
 * Registro utilizado para acomodar cada elemento da pilha (NÃ³).
 */
typedef struct no{
    Tipo dado;
    struct no* prox;
}No;

/**
 * Estrutura usada para representar e armazenar a FILA com alocaÃ§Ã£o encadeada.
 */
typedef struct{
    No* inicio;
    No* fim;
    int qtde;
}Fila;

Fila* fila_cria();
Fila* fila_destruir(Fila* p);
Boolean fila_inserir(Fila* p, Tipo elemento);
Tipo* fila_remover1(Fila* p);
Boolean fila_remover2(Fila* p, Tipo* end);
Boolean fila_primeiro(Fila* f, Tipo* endereco);
int fila_tamanho(Fila* p);
Boolean fila_contem(Fila* f, Tipo elemento);
void fila_imprimir(Fila* p);


/**
 * Cria a fila e devolve seu endereÃ§o.
 * @return o endereÃ§o da fila criada e inicializada.
 */
 Fila* fila_cria(){
     Fila* newRow = (Fila*) malloc(sizeof(Fila));
     newRow->qtde = 0;
     newRow->inicio = NULL;
     newRow->fim = NULL;

     return newRow;
}

/**
 * Desaloca a fila <p>.
 */
void destruir(No* no){
    if(no == NULL) return;
    destruir(no->prox);
    free(no);
}

Fila* fila_destruir(Fila* p){
    if(p == NULL) return NULL;
    destruir(p->inicio);
    free(p);
    return NULL;
}

/**
 * Insere o elemento <elemento> no final da fila <p>.
 * @param p: EndereÃ§o da fila em que o elemento serÃ¡ inserido.
 * @param elemento: Elemento a ser inserido na fila.
 * @return true se a inserÃ§Ã£o foi realizada com sucesso e false caso contrÃ¡rio
 */
Boolean fila_inserir(Fila* p, Tipo elemento){
    if(p == NULL) return false;

    No* no = (No*) malloc(sizeof(No));
    no->dado = elemento;
    
    if(p->inicio == NULL){
        no->prox = p->fim;
        p->inicio = no;
    }else{
        no->prox = p->fim->prox;
        p->fim->prox = no;
    }
    
    p->fim = no;
    p->qtde++;
    return true;
}

/**
 * Imprime na saÃ­da padrÃ£o os elementos da fila
 * @param p: EndereÃ§o da fila.
 */

void printainicio(No* no){
    if(no == NULL) return;

    printf("%d", no->dado);
    if(no->prox != NULL) printf(", ");    
    printainicio(no->prox);
}

void fila_imprimir(Fila* p){
    if(p == NULL){
        printf("\nPilha inexistente!\n");    
    }else{
        printf("[ ");
        printainicio(p->inicio);
        printf(" ]");
    }
}
/**
 * Recebe a vilha que vai ser analisada, e retorna o primeiro elemento dessa fila via ponteiro
 * @param p: EndereÃ§o da Fila, e endereço de um inteiro.
 * @return true caso existir alguem na fila, false caso não existir ninguem na fila.
 */
Boolean fila_primeiro(Fila* f, Tipo* endereco){
    if(f == NULL || f->inicio == NULL) return false;
    *endereco = f->inicio->dado;
    return true;
} 

/**
 * Remove o inicio da Fila <p>, aloca um espaÃ§o dinamicamente para armazenar o * elemento removido e devolve o endereÃ§o do elemento.
 * @param p: EndereÃ§o da Fila.
 * @return EndereÃ§o do elemento removido ou NULL caso contrÃ¡rio.
 */
Tipo* fila_remover1(Fila* p){

    if(p == NULL) return NULL;

    int* aux = (int*) malloc(sizeof(int));
    *aux = p->inicio->dado;

    No* next = p->inicio->prox;
    free(p->inicio);
    p->inicio = next;
    
    return aux;
}

/**
 * Remove o inicio da Fila <p>, e armazena o elemento removido no endereÃ§o 
 * <end> recebido por parÃ¢metro.
 * @param p: EndereÃ§o da Fila.
 * @param end: EndereÃ§o de memÃ³ria onde serÃ¡ armazenado o elemento removido
 * @return true se a remoÃ§ao foi realizada com sucesso e false caso contrÃ¡rio
 */
Boolean fila_remover2(Fila* p, Tipo* end){
     if(p == NULL) return false;

    *end = p->inicio->dado;
    No* aux = p->inicio->prox;
    free(p->inicio);
    p->inicio = aux;
    return true;
}


Boolean searchInt(No* f, Tipo elemento){
    if(f == NULL) return false;
    return (f->dado == elemento) ? true : searchInt(f->prox, elemento);
}

/*
*Devolve true caso o elemento existir na fila
*@param f = Endereço da fila
*@param elemento = inteiro a ser procura na fila
*@return true caso existir esse inteiro e false caso contrario
*/
Boolean fila_contem(Fila* f, Tipo elemento){
    if(f == NULL) return false;
    return searchInt(f->inicio, elemento);
    return true;
}



/**
 * Devolve o tamanho da fila <p>
 * @param p: EndereÃ§o da Fila.
 * @return quantidade de elementos da fila <p>
 */

int pilha_tamanho(Fila* p){
    return p->qtde;
}