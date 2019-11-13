#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int verificaCaracter10(int* cpf, int aux){
    for(int i = 1; i < 10; i++){
        aux += (i* cpf[i-1]);
    }
    return (aux%11)%10;
    
}

int verificaCaracter11(int* cpf, int aux){
    for(int i = 2; i < 11; i++){
        aux += ((i-1)* cpf[i-1]);
    }
    return (aux%11)%10;
}

int verificaCPF(int* cpf){
    int flag = 0;
    int n10 = verificaCaracter10(cpf, 0);
    
    if(cpf[9] != n10){
        cpf[9] = n10;
        flag = 1;
    } 
    
    int n11 = verificaCaracter11(cpf, 0);
    
    if(cpf[10] != n11){
         cpf[10] = n11;
         flag = 1;
     } 
    return flag;
}



int main (void){
    int cpf[11];

    printf("Digite seu CPF\n");
    for(int i = 0; i < 11; i++){
        printf("Numero %d: ", i+1);
        scanf("%d", &cpf[i]);
    }
    int verify = verificaCPF(cpf);

    if(verify == 0) printf("CPF CORRETO!\n");
    if(verify == 1) printf("ERRO ENCONTRADO E CORRIGIDO!\n");

    for(int i = 0; i < 11; i++){
        printf("%d", cpf[i]);
    }
}
