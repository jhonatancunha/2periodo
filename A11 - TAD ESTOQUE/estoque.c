#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char cod[6];
    char* nome;
    float* preco;
    int qtde; // qtde de produtos no estoque
    int qtdePrecos;//qtde de preços
}Produto;

typedef struct{
    char* nome;
    Produto** produtos;
    int qtde;//qtde de produtos
    int tam;//tamanho do vetor
}Empresa;


//Cria empresa
Empresa* new_Empresa(char* nome);

//Cadastra um produto informado na empresa
void cadastra_ProdutoEmpresa(Empresa* e1, Produto* p1);

//Cadastra um novo produto
Produto* novoProduto(char* cod, char* nome, float preco, int qtde);

//Insere um novo preço em um produto já cadastrado
void inseri_Preco(Produto* p1, float novoPreco);

//Copia preços para auxiliar funcão inseri preço
float* copiaValor(Produto* p1, float valor, int tam, float* newPreco);

//Retorna a media do preço do produto
//Tendo em vistas dos preços cadastrados
float mediaDePreco(Empresa* e);

//Calcula o preço medio de um produto
float mediaPrecoProduto(Produto* p1);

//Preenche um vetor 'a' com os valors do vetor produto dentro da empresa 'b'
Produto** passaProduto(Produto** a, Empresa* b);

int buscaRemoveDuplicados(Empresa* e, char* cod);


Empresa* new_Empresa(char* nome){
    Empresa* company = (Empresa*) malloc(sizeof(Empresa));
    company->nome = (char*) calloc(strlen(nome), sizeof(char));
    company->qtde = 0;
    company->tam = 5;
    return company;
}

Produto** passaProduto(Produto** a, Empresa* b){
    for(int i = 0; i < b->qtde; i++){
        a[i] = b->produtos[i];
        for(int j = 0; j < b->produtos[i]->qtdePrecos; j++){
            a[i]->preco[j] = b->produtos[i]->preco[j];
        }
    }

    return a;
}

void cadastra_ProdutoEmpresa(Empresa* e1, Produto* p1){
    int aux = (e1->tam == e1->qtde) ? e1->tam + 1: e1-> tam;

    Produto** nVetor = (Produto**) calloc(aux, sizeof(Produto));

    nVetor = passaProduto(nVetor, e1);

    nVetor[e1->qtde++] = p1;
    e1->produtos = nVetor;
}


Produto* novoProduto(char* cod, char* nome, float preco, int qtde){
    Produto* p1 = (Produto*) malloc(sizeof(Produto));
    strcpy(p1->cod, cod);
    p1->nome = (char*) calloc(strlen(nome),sizeof(char));
    strcpy(p1->nome, nome);
    p1->preco = (float*) malloc(sizeof(float));
    p1->preco[0] = preco;
    p1->qtdePrecos++;
    p1->qtde = qtde;

    return p1;
}

float* copiaValor(Produto* p1, float valor, int tam, float* newPreco){
    for(int i = 0; i < tam-1; i++){
        newPreco[i] = p1->preco[i];
    }
    newPreco[tam-1] = valor;
    return newPreco;
}

void inseri_Preco(Produto* p1, float novoPreco){

    float* precoNew = (float*) calloc(++p1->qtdePrecos, sizeof(float));
    precoNew = copiaValor(p1, novoPreco, p1->qtdePrecos, precoNew);
    p1->preco = precoNew;

}

float mediaPrecoProduto(Produto* p1){
    float soma = 0;
    for(int i = 0; i < p1->qtdePrecos; i++){
        soma += p1->preco[i]; 
   }
   return (float) soma/p1->qtdePrecos;
}

float mediaDePreco(Empresa* e){
    float somaMediaPreco = 0;
    for(int i = 0; i < e->qtde; i++){
        somaMediaPreco += mediaPrecoProduto(e->produtos[i]);
    }

    return (float) somaMediaPreco / e->qtde;
}

void liberaProduto(Produto* eliminado){
    free(eliminado->preco);
    free(eliminado->nome);
    free(eliminado);
}

void shiftBitsProdutos(Produto** p, int index, int qtde){
   for(int i = index; i <= qtde; i++){
      p[i] = p[i+1];
   }
}

int buscaRemoveDuplicados(Empresa* e, char* cod){
    int qtd = 0;
    int tam = e->qtde;
    for(int i = 0; i < e->qtde;){
        if(strcmp(e->produtos[i]->cod, cod) == 0){
            liberaProduto(e->produtos[i]);
            shiftBitsProdutos(e->produtos, i, e->qtde);
            qtd++;
            e->qtde--;
        }else{
            i++;
        }
    }
    return qtd;
}

void printEmpresaProduto(Empresa* e){
    for(int j = 0; j < e->qtde; j++){
        printf("===========================\n");
        printf("Codigo: %s\n", e->produtos[j]->cod);
        printf("Nome: %s\n", e->produtos[j]->nome);
        printf("Quantidade estoque: %d\n", e->produtos[j]->qtde);
        for(int i = 0; i < e->produtos[j]->qtdePrecos; i++){
            printf("Preço[%d]: R$%.2f\n", i, e->produtos[j]->preco[i]);
        }
        printf("Media de preço : R$%.2f\n", mediaPrecoProduto(e->produtos[j]));
    }    
}

void main(){

    Empresa* e1 = new_Empresa("Jhonatan Company");

    Produto* p1 = novoProduto("123", "Sabonete", 5.56, 3);
    inseri_Preco(p1, 1.2);
    cadastra_ProdutoEmpresa(e1, p1);

    Produto* p2 = novoProduto("123", "Esponja", 0.99, 50);
    inseri_Preco(p2, 1.20);
    cadastra_ProdutoEmpresa(e1, p2);

    Produto* p3 = novoProduto("123", "Esponja Dupla", 2, 50);
    inseri_Preco(p3, 1.80);
    cadastra_ProdutoEmpresa(e1, p3);

    Produto* p4 = novoProduto("123-a", "Frango", 6, 50);
    inseri_Preco(p4, 7.50);
    inseri_Preco(p4, 8);
    cadastra_ProdutoEmpresa(e1, p4);

    float preco = mediaDePreco(e1);
    printf("Media de preço da empresa : R$%.2f\n", preco);

    printEmpresaProduto(e1);
    
    int qtd = buscaRemoveDuplicados(e1, "123");
    printf("\nOcorrencias removidas: %d\n", qtd);

    printEmpresaProduto(e1);
}