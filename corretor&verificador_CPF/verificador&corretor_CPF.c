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
    char teste[12];

do{
    printf("DIGITE SEU CPF: ");
    scanf("%s", teste);
    if(strlen(teste) <9 ) printf("O CPF DEVE TER NO MINIMO 9 DIGITOS\n"); 
}while(strlen(teste) < 9);
    printf("\n");

    for(int i = 0; i < strlen(teste); i++){
        char aux[]={teste[i],'\0'};
        cpf[i] = atoi(aux);
    }

    int verify = verificaCPF(cpf);

    if(verify == 0) printf("CPF CORRETO!\n");
    if(verify == 1) printf("ERRO ENCONTRADO E CORRIGIDO!\n");


    int cont = 0;
    for(int i = 0; i < 11; i++){
        if(cont == 2 || cont == 5) {printf("%d.", cpf[i]);}
        else if(cont == 9) {printf("-%d", cpf[i]);}
        else{printf("%d", cpf[i]);}
        cont++;
    }
}
