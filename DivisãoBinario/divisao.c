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
        if(i >= 0){
            s = somaBit(m[i], q[i], &overflow);
        }else{
            s = somaBit(m[i], 0, &overflow);
        }
        binFinal[i] = s;
    }  
    return binFinal;
}

/*FUNÇÃO QUE REALIZA SHIFT DE BITS EM UM VETOR
*@param:    a = vetor
*@param:    size = tamanho do vetor
*/
void shiftBitA(int* a, int size, int q0){
    int aux = a[size];
    int aux2;
    a[size] = q0;

    for(int i = size; i >= 0; i--){
        aux2 = a[i-1];
        a[i-1] = aux;
        aux = aux2;    
    } 
}

/*FUNÇÃO QUE REALIZA SHIFT DE BITS EM UM VETOR
*@param:    a = vetor
*@param:    size = tamanho do vetor
*/
void shiftBit(int* a, int size){
    int aux = a[size];
    int aux2;
    a[size] = 0;
    

    for(int i = size; i >= 0; i--){
        aux2 = a[i-1];
        a[i-1] = aux;
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

//FAZ O COMPLEMENTO DE 2 NO M
char* inversion(char* m){
    int flag = 0;
    char* mComplemento = (char*) calloc(strlen(m), sizeof(char));

    for(int i = strlen(m)-1; i >= 0; i--){
        if(flag == 0){
            mComplemento[i] = m[i];
            if(mComplemento[i] == '1')flag = 1;
        }else{
            if(m[i] == '1') mComplemento[i] = '0';
            else mComplemento[i] = '1';
        }
    }

    return mComplemento;
}

//FUNCAO QUE REALIZA DIVISAO DE BINARIOS
void divisionOfBinary(char* mChar,char* qChar,char* mComplementoChar){
    //CRIAR VETORES
    int* m = (int*) calloc(strlen(mChar), sizeof(int));
    int* q = (int*) calloc(strlen(qChar), sizeof(int));
    int* mComplemento = (int*) calloc(strlen(mComplementoChar), sizeof(int));
    int* a = (int*) calloc((strlen(mChar)), sizeof(int));
    
    //PREENCHER VETORES
    fillBin(qChar , q, strlen(qChar)-1);
    fillBin(mChar , m, strlen(mChar)-1);
    fillBin(mComplementoChar,mComplemento, strlen(mComplementoChar)-1);


    //BIT MAIS SIGNIFICADO DE M É ZERADO
    m[0] = 0;

    printf("A: ");
    for(int i = 0; i < (strlen(mChar)); i++) printf("%d", a[i]);
    printf("\tQ: ");
    for(int i = 0; i < (strlen(qChar)); i++) printf("%d", q[i]);
    printf("\n");
    int cont = 1;


    while(cont != strlen(qChar)+1){

        //5 - DESCOLA TUDO PARA ESQUERDA
        shiftBitA(a, strlen(mChar)-1, q[0]);
        shiftBit(q, strlen(qChar));
        
        
        printf("A: ");
        for(int i = 0; i < (strlen(mChar)); i++) printf("%d", a[i]);
        printf("\tQ: ");
        for(int i = 0; i < (strlen(qChar)); i++) printf("%d", q[i]);
        printf("\n");
        //6 -PASSO DE SOMAR A-M
        a = somaBinario(mComplemento, a, (strlen(mChar)));

        printf("A: ");
        for(int i = 0; i < (strlen(mChar)); i++) printf("%d", a[i]);
        printf("\tQ: ");
        for(int i = 0; i < (strlen(qChar)); i++) printf("%d", q[i]);
        printf("\n");
        
        //7 -VERIFICA BIT Q4
        int q4 = strlen(mChar)-4;

        if(a[q4] == 0){
            q[strlen(qChar)-1] = 1;
        }else{
            //PASSO DE SOMAR A+M
            a = somaBinario(m, a, (strlen(mChar)+1));
            q[strlen(qChar)-1] = 0;
        }
        printf("================================\n");

        printf("A: ");
        for(int i = 0; i < (strlen(mChar)); i++) printf("%d", a[i]);
        printf("\tQ: ");
        for(int i = 0; i < (strlen(qChar)); i++) printf("%d", q[i]);
        printf("\n");
        cont++;
    }

    printf("   RESTO\tQUOCIENTE\n");

}

int main(){
    char m[MAX];
    char q[MAX];

    do{
        printf("DIGITE O DIVISOR (M): ");
        scanf("%s",m);
    }while(strlen(m) >= MAX);


    do{
        printf("DIGITE O DIVIDENDO (Q): ");
        scanf("%s",q);
    }while(strlen(q) >= MAX);

    char* mComplemento = inversion(m);

    printf("PROCESSO DE DIVISÃO DE BINARIO!\n================================\n");
    divisionOfBinary(m,q,mComplemento);

    return 0;
}