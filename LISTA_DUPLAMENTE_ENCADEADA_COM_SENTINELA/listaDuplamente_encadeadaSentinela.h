#include<stdlib.h>

typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;


typedef struct no{
    Tipo dado;
    struct no* prox;
    struct no* ant;
}No;

typedef struct{
    No* sentinela;
    int qtde;
}Lista;


Lista* lista_criar(); // OK
Lista* lista_destruir(Lista* l);//OK

Boolean lista_inserir(Lista* l, Tipo elemento, int posicao);//OK
Boolean lista_inserir_fim(Lista* l, Tipo elemento);//OK

Tipo* lista_remover1(Lista* l, int posicao);//OK
Boolean lista_remover2(Lista* l, int posicao, Tipo* endereco);//OK
Boolean lista_remover_elemento(Lista* l, Tipo elemento);//OK


Boolean lista_buscar(Lista* l, int posicao, Tipo* endereco);//ok
Boolean lista_contem(Lista* l, Tipo elemento);//OK
int lista_posicao(Lista* l, Tipo elemento);//OK

int lista_tamanho(Lista* l);//OK
void lista_imprimir(Lista* l);//OK


/*FUNCOES AUXILIARES*/
void insertFirstPosition(Lista* l, No* elemento);//OK
void insertLastPosition(Lista* l, No* elemento);//OK
void insertInTheMiddle(Lista* l, No* elemento, int posicao);//OK
No* findPositionfromBeginning(Lista* l, int pos);//OK
No* findPositionfromEnd(Lista* l, int pos);//OK
No* auxFindPosition(Lista* l, int posicao);//OK
void destroy(No* no, int* qtde);//OK

/*FUNCAO QUE CRIA UMA LISTA NOVA
*@RETURN: RETORNA O ENDEREÇO DA LISTA CRIADA
*/
Lista* lista_criar(){
    Lista* list = (Lista*) malloc(sizeof(Lista));
    No* no = (No*) malloc(sizeof(No));
    no->prox = no;
    no->ant = no;
    
    list->sentinela = no;
    list->qtde = 0;

    return list;
}


/*FUNCAO QUE BUSCA POSICAO NA LISTA E RETORNA SEU CONTEUDO
*@param: l = lista onde sera procurada posicao
*@param: posicao = posicao a ser encontrada
*@param: endereco = lugar onde sera armazenado a posicao encontrada
*@return true caso contém e false caso contrario
*/
Boolean lista_buscar(Lista* l, int posicao, Tipo* endereco){
    if(l == NULL || posicao > l->qtde-1 || posicao < 0) return false;
    No* aux = auxFindPosition(l, posicao);
    *endereco = aux->dado;
    return true;
}

/*FUNCAO QUE VERIFICA SE ELEMENTO ESTÁ NA LISTA
/*TAL FUNÇÃO COMEÇA SUA PROCURA PELO INICIO DA LISTA
*@param: l = lista onde sera procurada posicao
*@param: elemento = valor a ser procurado
*@return true caso contém e false caso contrario
*/
Boolean lista_contem(Lista* l, Tipo elemento){
    if(l == NULL) return false;

    No* aux = l->sentinela->prox;
    for(int i = 0; i < l->qtde; i++){
        if(aux->dado == elemento) return true;
        aux = aux->prox;
    }
    return false;
}


/*FUNCAO QUE RETORNA O INDICE DO ELEMENTO INFORMADO
/*TAL FUNÇÃO COMEÇA SUA PROCURA PELO INICIO DA LISTA
*@param: l = lista onde sera procurada posicao
*@param: elemento = valor a ser procurado
*@return indice do elemento
*/
int lista_posicao(Lista* l, Tipo elemento){
    if(l == NULL) return -1;

    No* aux = l->sentinela->prox;
    for(int i = 0; i < l->qtde; i++){
        if(aux->dado == elemento) return i;
        aux = aux->prox;
    }
    return -1;
}


/*FUNCAO QUE PROCURA POSICAO DESEJADA E RETORNA ENDEREÇO DA POSICAO
*@param: l = lista onde sera procurada posicao
*@param: posicao = posicao procurada
*/
No* auxFindPosition(Lista* l, int posicao){
    No* pos;

    int middlePosition = l->qtde / 2;
    if(middlePosition >= posicao ) pos = findPositionfromBeginning(l, posicao);
    else if(middlePosition < posicao ) pos = findPositionfromEnd(l, posicao);

    return pos;
}


/*FUNCAO QUE REMOVE E RETORNA ENDEREÇO REMOVIDO
*@param: l = lista onde sera procurada posicao
*@param posicao = posicao a ser procurada
*@return endereço dessa posição
*/
Tipo* lista_remover1(Lista* l, int posicao){
   if(l == NULL || posicao < 0 || posicao >= l->qtde) return NULL;
   
    No* aux = auxFindPosition(l, posicao);
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    l->qtde--;
    return &(aux->dado);
}

/*FUNCAO QUE REMOVE ELEMENTO NA POSICAO INFORMADA
*@param: l = lista onde sera procurada posicao
*@param: posicao = posicao a ser procurada
*@param: endereco = onde sera armazenado valor removido
*@return true caso remova e false caso contrario
*/
Boolean lista_remover2(Lista* l, int posicao, Tipo* endereco){
   Tipo* aux = lista_remover1(l,posicao);
   if(aux == NULL) return false;
    *endereco = *aux;
    return true;
}


/*FUNCAO QUE REMOVE ELEMENTO INFORMADO
*@param: l = lista onde sera procurada posicao
*@param: elemento = elemento a ser removido
*@return true caso remova e false caso contrario
*/
Boolean lista_remover_elemento(Lista* l, Tipo elemento){
    if(l->qtde == 0) return false;

    //PROCURA INDICE DO ELEMENTO
    int indice = lista_posicao(l, elemento);

    //REMOVE ELEMENTO DO INDICE OBTIDO
    if(lista_remover1(l, indice) != NULL) return true;
    return false;
}

/*FUNCAO QUE RETORNA ENDEREÇO ONDE SERA INSERIDO VALOR
/*TAL FUNÇÃO COMEÇA SUA PROCURA PELO INICIO DA LISTA
*@param: l = lista onde sera procurada posicao
*@return endereço dessa posição
*/
No* findPositionfromBeginning(Lista* l, int pos){
    No* aux = l->sentinela->prox;
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
    No* aux = l->sentinela->ant;

    for(int i = l->qtde-1; i > pos; i--) {
        aux = aux->ant;
    }
    return aux;
}

/*FUNCAO QUE INSERI ELEMENTO NO FIM DA LISTA
*@param: l = lista onde o elemento irá ser inserido
*/
Boolean lista_inserir_fim(Lista* l, Tipo elemento){
    if(l == NULL) return false;
    
    No* aux = (No*) malloc(sizeof(No));
    aux->dado = elemento;

    insertLastPosition(l, aux);
    return true;
}


/*FUNCAO QUE INSERI ELEMENTO NA ULTIMA POSICAO
*@param: l = lista onde o elemento irá ser inserido
*@param: elemento = valor que será atribuido a lista
*/
void insertLastPosition(Lista* l, No* elemento){
    elemento->prox = l->sentinela;
    l->sentinela->ant->prox = elemento;
    elemento->ant = l->sentinela->ant;
    l->sentinela->ant = elemento;
    l->qtde++;
}


/*FUNCAO QUE INSERI ELEMENTO NA PRIMEIRA POSICAO
*@param: l = lista onde o elemento irá ser inserido
*@param: elemento = valor que será atribuido a lista
*/
void insertFirstPosition(Lista* l,No* elemento){
    l->sentinela->prox = elemento;
    l->sentinela->ant = elemento;
    elemento->prox = l->sentinela;
    elemento->ant = l->sentinela;
    l->qtde++;

}

/*FUNCAO QUE INSERI ELEMENTO NO MEIO DA LISTA
*@param: l = lista onde o elemento irá ser inserido
*@param: elemento = valor que será atribuido a lista
*/
void insertInTheMiddle(Lista* l, No* elemento, int posicao){
    No* position = auxFindPosition(l, posicao);  
    elemento->ant = position->ant;
    elemento->prox = position;
    position->ant->prox = elemento;
    position->ant = elemento;
        
    l->qtde++;
}

/*FUNCAO QUE INSERI ELEMENTO NA POSICAO INFORMADA
*@param: l = lista onde o elemento irá ser inserido
*@param: elemento = valor que será atribuido a lista
*@param: posicao = posicao onde será armazenado esse valor
*/
Boolean lista_inserir(Lista* l, Tipo elemento, int posicao){
    if(l == NULL || posicao < 0 || posicao > l->qtde) return false;
    
    No* aux = (No*) malloc(sizeof(No));
    aux->dado = elemento;

    if(l->qtde == 0){
        insertFirstPosition(l,aux);
    }else if(posicao == l->qtde){
        insertLastPosition(l, aux);
    }else{
        insertInTheMiddle(l, aux, posicao);
    }


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
    if(l == NULL){
        printf("Lista Inexistente!\n");
        return;
    }else if(l->qtde == 0){
        printf("Lista Vazia!\n");
        return;
    }

    No* aux = l->sentinela->prox;

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
*@return NULL
*/
Lista* lista_destruir(Lista* l){
    if(l == NULL) return NULL;
    if(l->qtde > 0) destroy(l->sentinela->prox, &l->qtde);

    free(l->sentinela);
    free(l);
    return NULL;
}