#include <stdio.h>
#include <stdlib.h>



typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

/**
 * Registro utilizado para acomodar cada elemento da pilha (Nó).
 */
typedef struct no{
    Tipo dado;
    struct no* prox;
}No;

/**
 * Estrutura usada para representar e armazenar a PILHA com alocação encadeada.
 */
typedef struct{
    No* topo;
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


/**
 * Cria a pilha e devolve seu endereço.
 * @return o endereço da pilha criada e inicializada.
 */
Pilha* pilha_criar(){
    Pilha* newPilha = (Pilha*) malloc(sizeof(Pilha));
    newPilha->qtde = 0;
    newPilha->topo = NULL;
    
    return newPilha;
}

/**
 * Insere o elemento <elemento> no topo da pilha <p>.
 * @param p: Endereço da Pilha em que o elemento será inserido.
 * @param elemento: Elemento a ser inserido na pilha.
 * @return true se a inserção foi realizada com sucesso e false caso contrário
 */
Boolean pilha_push(Pilha* p, Tipo elemento){


    No* thisNumber = (No*) malloc(sizeof(No));
    thisNumber->dado = elemento;
    thisNumber->prox = p->topo;

   
    p->topo = thisNumber;
    p->qtde++;
    return true;
}

/**
 * Desaloca a pilha <p>.
 */
void destruir(No* no){
    if(no == NULL) return;
    destruir(no->prox);
    free(no);
}

Pilha* pilha_destruir(Pilha* p){
    destruir(p->topo);
    free(p);
    return NULL;
}




/**
 * Remove o topo da Pilha <p>, aloca um espaço dinamicamente para armazenar o * elemento removido e devolve o endereço do elemento.
 * @param p: Endereço da Pilha.
 * @return Endereço do elemento removido ou NULL caso contrário.
 */
Tipo* pilha_pop1(Pilha* p){

    if(p == NULL) return NULL;

    int* aux = (int*) malloc(sizeof(int));
    *aux = p->topo->dado;
    No* next = p->topo->prox;
    free(p->topo);
    p->topo = next;
    
    return aux;
}

/**
 * Remove o topo da Pilha <p>, e armazena o elemento removido no endereço 
 * <end> recebido por parâmetro.
 * @param p: Endereço da Pilha.
 * @param end: Endereço de memória onde será armazenado o elemento removido
 * @return true se a remoçao foi realizada com sucesso e false caso contrário
 */
Boolean pilha_pop2(Pilha* p, Tipo* end){
     if(p == NULL) return false;

    *end = p->topo->dado;
    No* next = p->topo->prox;
    free(p->topo);
    p->topo = next;
    
    return true;
}


/**
 * Imprime na saída padrão os elementos da pilha
 * @param p: Endereço da Pilha.
 */
void pilha_imprimir(Pilha* p){

    if(p == NULL) return;

    No* topo = p->topo;
    while(topo != NULL){
        printf("%d, ", topo->dado);
        topo = topo->prox;
    }
}

/**
 * Devolve a posição do elemento <elemento> na pilha <p>
 * @param p: Endereço da Pilha.
 * @param elemento: Elemento a ser encontrado
 * @return posição do <elemento> em <p> ou -1 caso contrário
 */

int verifica(No* stNum, Tipo elemento, Tipo i){
    if(stNum == NULL) return -1;
    if(stNum->dado == elemento){return i;}
    i += 1;
    printf("\n%d, ", i);
    verifica(stNum->prox, elemento, i);
}

int pilha_posicao(Pilha* p, Tipo elemento){
    return verifica(p->topo, elemento, 0);;
}

/**
 * Devolve o tamanho da pilha <p>
 * @param p: Endereço da Pilha.
 * @return quantidade de elementos da pilha <p>
 */

int contTamPilha(No* numbers, int cont){
    if(numbers == NULL) return cont;
    cont++;
    contTamPilha(numbers->prox, cont);
}

int pilha_tamanho(Pilha* p){
    return contTamPilha(p->topo, 0);
}

//FUNÇÕES ADICIONAIS

/**
 * Insere todos os elementos do vetor <vetor> na pilha <p>
 * @param p: Endereço da Pilha.
 * @param vetor: Endereço do vetor
 * @param tam: tamanho do <vetor>
 * @return quantidade de elementos inseridos na pilha <p>
 */
int pilha_pushAll(Pilha* p, Tipo* vetor, int tam){
    int i = 0;
    while(tam != 0){
        pilha_push(p, vetor[i++]);
        tam--;
    }

    return i;
}

/**
 * Inverte a pilha <p>
 * @param p: Endereço da Pilha.
 */

void insertNumber(No* topo, Pilha* inverted){
    if(topo == NULL) return;

    pilha_push(inverted, topo->dado);
    topo = topo->prox;
    insertNumber(topo, inverted);
}


void pilha_inverter(Pilha* p){
    Pilha* inversion = pilha_criar();
    insertNumber(p->topo, inversion);

    destruir(p->topo);
    p->topo = inversion->topo;
    free(inversion);
}

/**
 * Cria um clone da pilha <p>
 * @param p: Endereço da Pilha.
 * @return Endereço da pilha clonada.
 */

void insertNos(No* no, Pilha* clone){
    if(no == NULL) return;

    No* inicio = (No*) malloc(sizeof(No));
    insertNos(no->prox, clone);
    inicio->dado = no->dado;
    inicio->prox = no->prox;
    clone->topo = inicio;
    
    
}

Pilha* pilha_clone(Pilha* p){
    Pilha* clone  = pilha_criar();
    insertNos(p->topo, clone);
    clone->qtde = p->qtde;
    return clone;
}