#include<stdio.h>
#include<stdlib.h>

typedef enum boolean{false=0, true=1} Boolean;
typedef int Tipo;

typedef struct node{
    int linha;
    int coluna;
    int valor;
    struct node* direita;
    struct node* cima;        
    struct node* esquerda;
    struct node* baixo;
    
}Node;

typedef struct{
    Node** linhas;    //ponteiro para o vetor cujas células são ponteiros de nós
    Node** colunas;    //ponteiro para o vetor cujas células são ponteiros de nós
    int numLinhas;    //Quantidade de linhas da matriz
    int numColunas;    //Quantidade de colunas da matriz
}Matriz;


/*FUNÇÕES PRINCIPAIS*/
Matriz* matriz_criar(int qtdeLinhas, int qtdeColunas);
Boolean matriz_atribuir(Matriz* m, int linha, int coluna, int valor);
int matriz_acessar(Matriz* m, int linha, int coluna);
void matriz_imprimir(Matriz* m);
Matriz* matriz_desalocar(Matriz** m);


/*FUNÇÕES AUXILIARES*/
void insereColuna(int linha, int coluna, Node* no, Matriz* m);
void insereLinha(int linha,int coluna , Node* no, Matriz* m);
Node* findNodeColuna(Node* aux,int linha, Node* sentinela);
Node* findNodeLinha(Node* aux,int coluna, Node* sentinela);


//Libera toda memória alocada dinamicamente para a matriz.
Matriz* matriz_desalocar(Matriz** EnderecoMatriz){
    Matriz* m = *EnderecoMatriz;
    if(m == NULL){
        printf("Matriz Inexistente!\n");
        return NULL;
    }
    int i = 0;
    Node* sentinela = m->linhas[i];

    //DESALOCA VALORES
    while(i < m->numLinhas){
        if(sentinela != sentinela->direita){
            Node* aux = sentinela->direita;
            while(aux != sentinela){
                sentinela->direita = aux->direita;
                free(aux);
                aux = sentinela->direita;
            }
        }
        sentinela = m->linhas[++i];
    }

    //DESALOCA SENTINELAS LINHA
    for(int i = 0; i < m->numLinhas; i++){
        Node* aux = m->linhas[i];
        free(aux);
    }
    //DESALOCA SENTINELAS COLUNAS
    for(int i = 0; i < m->numColunas; i++){
        Node* aux = m->colunas[i];
        free(aux);
    }

    //FREE's
    free(m->colunas);
    free(m->linhas);
    free(m);
    *EnderecoMatriz = NULL;
}


//Cria uma matriz vazia e devolve seu endereço de memória.
Matriz* matriz_criar(int qtdeLinhas, int qtdeColunas){
    //Alocando Matriz
    Matriz* matriz = (Matriz*) malloc(sizeof(Matriz));
    matriz->numColunas = qtdeColunas;
    matriz->numLinhas = qtdeLinhas;
    
    //Alocando Quantidade de Colunas
    Node** colunas = (Node**) calloc(qtdeColunas, sizeof(Tipo*));
    matriz->colunas = colunas;

    //Alocando Quantiade de Linhas
    Node** linhas = (Node**) calloc(qtdeLinhas, sizeof(Tipo*));
    matriz->linhas = linhas;

    //Atribuindo Sentinela Colunas
    for(int i = 0; i < qtdeColunas; i++){
        Node* sentinela = (Node*) malloc(sizeof(Node));
        sentinela->cima = sentinela;
        sentinela->baixo = sentinela;
        colunas[i] = sentinela;
    }
    //Atribuindo Sentinelas Linhas
    for(int i = 0; i < qtdeLinhas; i++){
        Node* sentinela = (Node*) malloc(sizeof(Node));
        sentinela->esquerda = sentinela;
        sentinela->direita = sentinela;
        linhas[i] = sentinela;
    }

    return matriz;
}


//DEVOLVE O VALOR CORRESPONDENDO A LINHA E COLUNA PASSADO COMO PARAMETRO
//CASO POSICAO SEJA INVALIDA DEVOLVE ZERO
int matriz_acessar(Matriz* m, int linha, int coluna){
    if(m == NULL) return 0;
    if(linha >= m->numLinhas || linha < 0) return 0;
    if(coluna >= m->numColunas || coluna < 0) return 0;

    Node* aux1 = findNodeLinha(m->linhas[linha]->direita, coluna,m->linhas[linha]);
    return aux1->valor;
}


//ACHA A POSICAO ANTERIOR A SER INSERIDA O NODE
Node* findNodeColuna(Node* aux,int linha, Node* sentinela){
    
    while(aux != sentinela && linha > aux->linha){
        aux = aux->baixo;
    }

    // for(int i = 0; i < linha; i++){
    //     if(aux->linha <= linha && aux->baixo != sentinela) aux = aux->baixo;
    // }
    return aux;
}


Node* findNodeLinha(Node* aux,int coluna, Node* sentinela){
    
    while(aux != sentinela && coluna > aux->coluna){
        aux = aux->direita;
    }

    // for(int i = 0; i < coluna; i++){        
    //     if(aux->coluna != coluna && aux->direita != sentinela){
    //         aux = aux->direita;
    //     }
         
    // } 
    return aux;
}


//Insere o Nó na coluna informada
void insereColuna(int linha, int coluna, Node* no, Matriz* m){
    Node* sentinela = m->colunas[coluna];   
    Node* aux = findNodeColuna(sentinela->baixo, linha, sentinela);
    
    if(aux != sentinela && linha == aux->linha){
        aux->valor = no->valor;
        free(no);
    }else{
        no->baixo = aux;
        no->cima = aux->cima;
        aux->cima->baixo = no;
        aux->cima = no;
    }

}


//Insere o Nó na linha informada
void insereLinha(int linha,int coluna, Node* no, Matriz* m){
    Node* sentinela = m->linhas[linha];
    Node* aux = findNodeLinha(sentinela->direita,coluna, sentinela);

    if(aux != sentinela && aux->coluna == coluna){
        aux->valor = no->valor;
        free(no);
    }else{
        no->direita = aux;
        no->esquerda = aux->esquerda;            
        aux->esquerda->direita = no;
        aux->esquerda = no;
    }
}


//Insere o <valor> na matriz <m> na linha <linha> e coluna <coluna>. Caso a posição já exista, substitua o valor da célula.
Boolean matriz_atribuir(Matriz* m, int linha, int coluna, int valor){
    if(m == NULL) return false;
    
    Node* no = (Node*) malloc(sizeof(Node));
    no->valor = valor;
    no->coluna = coluna;
    no->linha = linha;
    insereColuna(linha,coluna, no, m);
    insereLinha(linha,coluna, no, m);

    return true;
}


//Imprime os valores da matriz na tela. Cada linha deve ser impressa em uma linha diferente e os elementos separados por espaço ou tabulação. Os elementos não representados na matriz (valor zero), também devem ser impressos.
void matriz_imprimir(Matriz* m){
    if(m == NULL){
        printf("Matriz Inexistente!\n");
        return;
    }

    for(int i = 0; i < m->numLinhas; i++){
        Node* aux = m->linhas[i]->direita;
        for(int j = 0; j < m->numColunas; j++){
            if(j != aux->coluna || aux == m->linhas[i]) printf("0\t");  
            else{
                printf("%d\t",aux->valor);
                aux = aux->direita;
            }  
        }
        printf("\n");
    }
    printf("\n");
}