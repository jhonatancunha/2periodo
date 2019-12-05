/************************************************/
//  ALGORITMO DE MULTIPLICAÇÃO DE BINARIOS       //
//  ALUNO: JHONATAN GUILHERME DE OLIVEIRA CUNHA  //
//  RA: 2135590                                  //
//  DISCIPLINA: ELEMENTOS DE LÓGICA DIGITAL      //
/************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#define MAX 1000


//FUNÇÕES UTILIZADAS NESSA ATIVIDADE
char somaBit(int a, int b, int* overflow);
int* somaBinario(int* m, int* q, int maior);
void shiftBit(int* a, int size);
void fillBin(char* vetChar, int* m, int size);
int CharBinToDec(char* bin, int size);
int IntBinToDec(int* bin, int size);
int* multiplyBin(char* m, char* q, int size);


/*FUNÇÃO QUE SIMULA CIRCUITO SOMADOR
*@param:    a = valor em binario
*@param:    b = valor em binario
*@param:    overflow = "C-in" e ("C-Out" do proximo)
*@return:   retorn o valor referete ao "S"
*/
char somaBit(int a, int b, int* overflow){
    if(a == 0 && b == 0 && *overflow == 0) return 0;
    if(a == 0 && b == 1 && *overflow == 0) return 1;
    if(a == 1 && b == 0 && *overflow == 0) return 1;
    if(a == 0 && b == 0 && *overflow == 1) {
        *overflow = 0;
        return 1;
    }
    if(a == 1 && b == 1 && *overflow == 0){
        *overflow = 1;
        return 0;
    }else if(a == 0 && b == 1 && *overflow == 1){
        *overflow = 1;
        return 0;
    }else if(a == 1 && b == 0 && *overflow == 1){
        *overflow = 1;
        return 0;
    }else if(a == 1 && b == 1 && *overflow == 1){
        *overflow = 1;
        return 1;
    }
}


/*FUNÇÃO QUE REALIZA SOMA DE VETOR DE BINARIOS
*@param:    m = vetor
*@param:    q = vetor
*@param:    size = tamanho do vetor
*@return:   retorna o binario final
*/
int* somaBinario(int* m, int* q, int size){
    int overflow = 0;
    int s = 0;
    int* binFinal = calloc(size+1, sizeof(int));
    for(int i = size-1; i >= 0; i--){
        s = somaBit(m[i], q[i], &overflow);
        binFinal[i] = s;
    }  
    return binFinal;
}


/*FUNÇÃO QUE REALIZA SHIFT DE BITS EM UM VETOR
*@param:    a = vetor
*@param:    size = tamanho do vetor
*/
void shiftBit(int* a, int size){
    int cont = size-1;
    int aux = a[0];
    int aux2;
    a[0] = 0;

    for(int i = 0; i < size; i++){
        aux2 = a[i+1];
        a[i+1] = aux;
        aux = aux2;    
    } 
}


/*FUNÇÃO AUXILIAR QUE PREENCHE TRANSFERE DADOS DO VETOR DE "CHAR" PARA "INT"
*@param:    vetChar = vetor de char (binario)
*@param:    m = vetor inteiro que sera armazenado os valores (binario)
*@param:    size = tamanho do vetor
*/
void fillBin(char* vetChar, int* m, int size){
    int cont = strlen(vetChar);
    for(int i = size; i >= 0 ; i--){
        if(cont <= 0) return;
        char aux[]={vetChar[cont-1],'\0'};
        m[i] = atoi(aux);
        cont--;
    }   
}


/*FUNÇÃO QUE CONVERTE VETOR DE CARACTER DE BINARIO PARA DECIMAL
*@param:    bin = vetor binario
*@param:    size = tamanho do vetor
*@return:   valor referente ao binario
*/
int CharBinToDec(char* bin, int size){
    int soma = 0;
    int aux = size;
    for(int i = 0; i <= size; i++){
        if(bin[i] == '1') soma += pow(2,aux);
        aux--;
    }
    return soma;
}


/*FUNÇÃO QUE CONVERTE VETOR DE INTEIRO DE BINARIO PARA DECIMAL
*@param:    bin = vetor binario
*@param:    size = tamanho do vetor
*@return:   valor referente ao binario
*/
int IntBinToDec(int* bin, int size){
    int soma = 0;
    int aux = size;
    for(int i = 0; i <= size; i++){
        if(bin[i] == 1)soma += pow(2,aux);
        aux--;
    } 
    return soma;
}


/*FUNÇÃO QUE MULTIPLICA DOIS BINARIOS
*@param:    m = multiplicando
*@param:    q = multiplicador
*@return:   binario final
*/
int* multiplyBin(char* m, char* q, int size){
    int tam = strlen(q);
    int *vet = calloc(size, sizeof(int));
    int *vet2 = calloc(size, sizeof(int));
    int* resul = (int*) calloc(size, sizeof(int));

    fillBin(q , vet, size-1);
    fillBin(m , vet2, size-strlen(q)-1);

    // //MULTIPLICA OS VETORES
    while(tam > 0){
        if(vet[size-1] == 1){
            vet = somaBinario(vet,vet2, size);
        }    
        shiftBit(vet, size);
        tam--;
    }
    return vet;
}


int main(){
    char m[MAX];
    char q[MAX];
    do{
        printf("DIGITE O MULTIPLICANDO (M): ");
        scanf("%s",m);
    }while(strlen(m) >= MAX);

    do{
    printf("DIGITE O MULTIPLICADOR (Q): ");
    scanf("%s",q);
    }while(strlen(m) >= MAX);
    int size = strlen(m) + strlen(q) + 1;
    int* resultado = multiplyBin(m,q,size);

    //PRINTS PARA DEMONSTRAÇÃO DA FUNÇÃO
    printf("=================================\n");
    printf("MULTIPLICAÇÃO DE BINARIO!\n");
    for(int i = 0; i < strlen(q); i++) printf("%c", q[i]);
    printf(" [Decimal: %d]\n", CharBinToDec(q,strlen(q)-1));
    for(int i = 0; i < strlen(m); i++) printf("%c", m[i]);
    printf(" [Decimal: %d]\n", CharBinToDec(m,strlen(m)-1));
    printf("=================================\n");
    printf("RESULTADO: ");
    for(int i = 0; i < size; i++) printf("%d", resultado[i]);
    printf(" [Decimal: %d]\n", IntBinToDec(resultado,size-1));

    return 0;
}