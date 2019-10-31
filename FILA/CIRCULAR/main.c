#include"filaCircular.h"

void teste(){
    int x =1;
    Fila* circular = fila_criar();
    fila_inserir(circular, x++);
    fila_inserir(circular, x++);
    fila_inserir(circular, x++);
    fila_inserir(circular, x++);
    fila_inserir(circular, x++);
    fila_inserir(circular, x++);

    // fila_imprimir(circular);

    // int aux;
    // fila_primeiro(circular, &aux);
    // printf("\nPRIMEIRA POSIÇÃO: %d\n", aux);

    // if(fila_contem(circular, 6)) printf("EXISTE NUMERO!\n");
    
    // Tipo* type = fila_remover1(circular);    
    // printf("Removido: %d\n", *type);
     fila_imprimir(circular);

    int aux2;
    fila_remover2(circular, &aux2); 
    printf("\nRemovido: %d\n", aux2);

        printf("\n");
    fila_imprimir(circular);
    printf("\n");

     fila_remover2(circular, &aux2); 
    printf("\nRemovido: %d\n", aux2);
     

  
  
    printf("\n");
    fila_imprimir(circular);
    printf("\n");
    


    fila_inserir(circular, x++);
    fila_inserir(circular, x++);
    fila_inserir(circular, x++);
    fila_inserir(circular, x++);

printf("\n");
    fila_imprimir(circular);
    printf("\n");
    
}

void main(){
    teste();
}