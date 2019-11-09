#include <stdio.h>
#include<string.h>

typedef char Tipo; 

void pilha_push(Tipo* verify, Tipo caracter, int* qtde){
    if(verify == NULL) return;
    if(*qtde == 1000001) return;
    verify[(*qtde)] =  caracter;
    (*qtde) += 1;
}


Tipo* pilha_pop1(Tipo* verify, int* qtde){
    if(verify == NULL) return NULL;
        Tipo* aux = verify+(*qtde)-1;
        (*qtde) -= 1;
        return aux;
}

Tipo verificaInsercao(Tipo* A){
    
    Tipo verify[1000001];
    int qtde = 0;

    char resultado = 'N';

    for(int i = 0; i < strlen(A); i++){
        if(A[i] == '[' || A[i] == '(' || A[i] == '{'){
             pilha_push(verify, A[i], &qtde);
        }else{
            if(qtde == 0){  resultado = 'N';    break;} 

            Tipo* aux = pilha_pop1(verify, &qtde);
            

            if(*aux == '[' && A[i] == ']') {resultado = 'S';}
            else if(*aux == '{' && A[i] == '}') {resultado = 'S';}
            else if(*aux == '(' && A[i] == ')') {resultado = 'S';}
            else{   resultado = 'N';    break;     }
         }
    }

    if(qtde != 0) resultado = 'N';
    return resultado;
}

int main(){
    int T;
    Tipo A[1000001];
   
    do{
        scanf("%d", &T);
    }while(T < 1 || T > 20 );

    for(int i = 0; i<T; i++){
        scanf("%s", A);
        char resultado = verificaInsercao(A);
        printf("%c\n", resultado);
    }


    return 0;
}