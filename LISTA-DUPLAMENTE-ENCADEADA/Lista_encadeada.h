#include<stdlib.h>

typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;


typedef struct no{
    Tipo dado;
    struct no* prox;
    struct no* ant;
}No;

typedef struct{
    No* primeiro;
    No* ultimo;
    int qtde;
}Lista;


Lista* lista_criar(); // OK
void lista_destruir(Lista* l);//OK

Boolean lista_inserir(Lista* l, Tipo elemento, int posicao); // OK
Boolean lista_inserir_fim(Lista* l, Tipo elemento);// OK

Tipo* lista_remover1(Lista* l, int posicao);//OK
Boolean lista_remover2(Lista* l, int posicao, Tipo* endereco);//OK
Boolean lista_remover_elemento(Lista* l, Tipo elemento);//OK


Boolean lista_buscar(Lista* l, int posicao, Tipo* endereco);// OK
Boolean lista_contem(Lista* l, Tipo elemento); // OK
int lista_posicao(Lista* l, Tipo elemento); // OK

int lista_tamanho(Lista* l); // OK
void lista_imprimir(Lista* l);// OK


/*FUNCOES AUXILIARES*/
No* findPositionfromBeginning(Lista* l, int pos);//OK
No* findPositionfromEnd(Lista* l, int pos);//OK
int findElement(Lista* l , int elemento, No** endereco);//OK
No* auxFindPosition(Lista* l, int posicao);//OK
void destroy(No* no, int* qtde);//OK

/*FUNCAO QUE CRIA UMA LISTA NOVA
*@RETURN: RETORNA O ENDEREÇO DA LISTA CRIADA
*/
Lista* lista_criar(){
    Lista* list = (Lista*) malloc(sizeof(Lista));
    list->primeiro = list->ultimo = NULL;
    list->qtde = 0;
    
    return list;
}

/*FUNCAO AUXILIAR QUE RETORNA VALOR OU POSICAO DO ELEMENTO
/*TAL FUNÇÃO COMEÇA SUA PROCURA PELA POSICAO INFORMADA
//CASO USUARIO INFORME O ENDEREÇO: A VARIAVEL ELEMENTO SERA INTERPRETADA COMO INDICE
//E TAL INDICE SERA PROCURADO NA LISTA
*
*
//CASO USUARIO INFORME ENDEREÇO NULL = ELEMENTO SERA O VALOR PROCURADO
*@param: l = lista onde sera procurada posicao
*@param: elemento = valor a ser procurado
*@return indice do elemento
*/
int findElement(Lista* l , int elemento, No** endereco){ 
    No* pos = l->primeiro;

    for(int i = 0; i < lista_tamanho(l); i++){
          if(endereco != NULL){
              if(i == elemento){
                *endereco = pos;
                return i;
              }

          }else{
            if(pos->dado == elemento)  return i;  
          } 
        pos = pos->prox;
    }

    *endereco = NULL;
    return -1;
}


/*FUNCAO QUE BUSCA POSICAO NA LISTA E RETORNA SEU ENDEREÇO
*@param: l = lista onde sera procurada posicao
*@param: posicao = posicao a ser encontrada
*@param: endereco = lugar onde sera armazenado a posicao encontrada
*@return true caso contém e false caso contrario
*/
Boolean lista_buscar(Lista* l, int posicao, Tipo* endereco){
    if(l == NULL) return false;
    No* aux = l->primeiro;

    if(findElement(l , posicao, &aux) != -1) {
        *endereco = aux->dado;
        return true;
    }   
    return false;
}

/*FUNCAO QUE VERIFICA SE ELEMENTO ESTÁ NA LISTA
/*TAL FUNÇÃO COMEÇA SUA PROCURA PELO INICIO DA LISTA
*@param: l = lista onde sera procurada posicao
*@param: elemento = valor a ser procurado
*@return true caso contém e false caso contrario
*/
Boolean lista_contem(Lista* l, Tipo elemento){
    if(l == NULL) return false;
    if( findElement(l ,elemento , NULL) == -1) return false;
    return true;
}

/*FUNCAO QUE RETORNA O INDICE DO ELEMENTO INFORMADO
/*TAL FUNÇÃO COMEÇA SUA PROCURA PELO INICIO DA LISTA
*@param: l = lista onde sera procurada posicao
*@param: elemento = valor a ser procurado
*@return indice do elemento
*/
int lista_posicao(Lista* l, Tipo elemento){
    if(l == NULL) return -1;

    return findElement(l, elemento, NULL);
}


/*FUNCAO QUE PROCURA POSICAO DESEJADA
*@param: l = lista onde sera procurada posicao
*@param: posicao = posicao procurada
*@return o endereço da posicao
*/
No* auxFindPosition(Lista* l, int posicao){
    No* pos;

    int middlePosition = l->qtde / 2;
    if( middlePosition == posicao || middlePosition >= posicao ) pos = findPositionfromBeginning(l, posicao);
    if( middlePosition <= posicao ) pos = findPositionfromEnd(l, posicao);

    return pos;
}


/*FUNCAO QUE REMOVE E RETORNA ENDEREÇO REMOVIDO
*@param: l = lista onde sera procurada posicao
*@param posicao = posicao a ser procurada
*@return endereço dessa posição
*/
Tipo* lista_remover1(Lista* l, int posicao){
    if(l == NULL) return NULL;
    if(l->qtde == 0) return NULL;
    if(posicao < 0 || posicao >= l->qtde) return NULL;

    No* pos = auxFindPosition(l, posicao);
    
    if(posicao != 0 && posicao < l->qtde-1) pos->ant->prox = pos->prox;
    if(posicao != l->qtde-1) pos->prox->ant = pos->ant;
    if(posicao == l->qtde-1) pos->ant->prox = NULL;
    if(posicao == 0) l->primeiro = pos->prox;

    l->qtde--;
    return &pos->dado;
    
}

/*FUNCAO QUE REMOVE ELEMENTO NA POSICAO INFORMADA
*@param: l = lista onde sera procurada posicao
*@param: posicao = posicao a ser procurada
*@param: endereco = onde sera armazenado valor removido
*@return true caso remova e false caso contrario
*/
Boolean lista_remover2(Lista* l, int posicao, Tipo* endereco){
    if(l == NULL) return false;
    if(l->qtde == 0) return false;
    if(posicao < 0 || posicao >= l->qtde) return false;

    No* pos = auxFindPosition(l, posicao);
    
    if(posicao != 0 && posicao < l->qtde-1) pos->ant->prox = pos->prox;
    if(posicao != l->qtde-1) pos->prox->ant = pos->ant;
    if(posicao == l->qtde-1) pos->ant->prox = NULL;
    if(posicao == 0) l->primeiro = pos->prox;

    l->qtde--;
    *endereco = pos->dado;
    return true;
}


/*FUNCAO QUE REMOVE ELEMENTO INFORMADO
*@param: l = lista onde sera procurada posicao
*@param: elemento = elemento a ser removido
*@return true caso remova e false caso contrario
*/
Boolean lista_remover_elemento(Lista* l, Tipo elemento){
    if(l == NULL) return false;
    if(l->qtde == 0) return false;


    //INFORMEI NULL POIS QUERO O INDICE DO ELEMENTO INFORMADO
    int indice = findElement(l, elemento, NULL);

    //INFORMEI ENDEREÇO POIS QUERO PROCURAR O INDICE OBTIDO ACIMA
    No* pos = l->primeiro;
    int verify = findElement(l, indice, &pos);
    if(verify == -1) return false;

    if(indice != 0 && indice < l->qtde-1) pos->ant->prox = pos->prox;
    if(indice != l->qtde-1) pos->prox->ant = pos->ant;
    if(indice == l->qtde-1) pos->ant->prox = NULL;
    if(indice == 0) l->primeiro = pos->prox;

    l->qtde--;
    return true;

}

/*FUNCAO QUE RETORNA ENDEREÇO ONDE SERA INSERIDO VALOR
/*TAL FUNÇÃO COMEÇA SUA PROCURA PELO INICIO DA LISTA
*@param: l = lista onde sera procurada posicao
*@return endereço dessa posição
*/
No* findPositionfromBeginning(Lista* l, int pos){
    No* aux = l->primeiro;
    for(int i = 0; i < pos; i++) {
        aux = aux->prox;
    }
    return aux;
}

/*FUNCAO QUE RETORNA ENDEREÇO ONDE SERA INSERIDO VALOR
/*TAL FUNÇÃO COMEÇA SUA PROCURA PELO FIM DA LISTA
*@param: l = lista onde sera procurada posicao
*@return endereço dessa posição
*/
No* findPositionfromEnd(Lista* l, int pos){
    No* aux = l->ultimo;
    for(int i = l->qtde-1; i > pos; i--) {
        aux = aux->ant;
    }
    return aux;
}

/*FUNCAO QUE INSERI ELEMENTO NO FIM DA LISTA
*@param: l = lista onde o elemento irá ser inserido
*/
Boolean lista_inserir_fim(Lista* l, Tipo elemento){
    if( l == NULL) return false;

    No* value = (No*) malloc(sizeof(No));
    value->dado = elemento;

    if(l->qtde != 0){
         l->ultimo->prox = value;
        value->ant = l->ultimo;
    }else{
        l->primeiro = value;
    }
   
    l->ultimo = value;
    value->prox = NULL;
    l->qtde++;
    return true;
}


/*FUNCAO QUE INSERI ELEMENTO NA POSICAO INFORMADA
*@param: l = lista onde o elemento irá ser inserido
*@param: elemento = valor que será atribuido a lista
*@param: posicao = posicao onde será armazenado esse valor
*/
Boolean lista_inserir(Lista* l, Tipo elemento, int posicao){
    if(l == NULL) return false;
    if(l->qtde < posicao) return false;

    No* value = (No*) malloc(sizeof(No));

    if(l->qtde == 0){
        l->primeiro = value;
        l->ultimo = value;
    }else if(l->qtde == posicao){

        l->ultimo->prox = value;
        value->ant = l->ultimo;
        l->ultimo = value;
        value->prox = NULL;

    }else{
        No* pos =  auxFindPosition(l, posicao);

        value->ant = pos->ant;
        value->prox = pos;
        if(posicao != 0) pos->ant->prox = value;
        pos->ant = value;
        if(posicao == 0) l->primeiro = value;
    }

    value->dado = elemento;
    l->qtde += 1;
    return true;
}

/*FUNCAO QUE RETORNA O TAMANHO DA LISTA
*@PARAM : L = LISTA A SER IMPRESSA
*@return tamanho da lista
*/
int lista_tamanho(Lista* l){
    if(l == NULL) return -1;
    return l->qtde;
}


/*FUNCAO PARA IMPRIMIR LISTA
*@PARAM : L = LISTA A SER IMPRESSA
*/
void lista_imprimir(Lista* l){
    No* aux = l->primeiro;

    for(int i = 0; i < l->qtde; i++){
        if(lista_tamanho(l) != i+1) printf("%d, ", aux->dado);
        if(lista_tamanho(l) == i+1) printf("%d", aux->dado);
        aux = aux->prox;
    }

}

void destroy(No* no, int* qtde){
    if(*qtde == 0) return;
    *qtde -= 1;
    destroy(no->prox, qtde);
    free(no);
}

/*FUNCAO PARA DESTRUIR LISTA
*@PARAM : L = LISTA A SER IMPRESSA
*/
void lista_destruir(Lista* l){
    if(l == NULL) return;
    if(l->qtde <= 0) return;

    destroy(l->primeiro, &l->qtde);
}