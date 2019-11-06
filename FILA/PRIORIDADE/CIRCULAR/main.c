#include"filaCircular.h"

void teste(){  
    Fila* circular = fila_criar();
    fila_inserir(circular, 5);
    fila_inserir(circular, 4);
    fila_inserir(circular, 10);
    fila_inserir(circular, 1);
    fila_inserir(circular, 6);
    fila_inserir(circular, 7);
    fila_inserir(circular, 2);

    fila_imprimir(circular);
    Tipo* type = fila_remover1(circular);    
    printf("\nRemovido: %d\n", *type);

    type = fila_remover1(circular);    
    printf("\nRemovido: %d\n", *type);

    type = fila_remover1(circular);    
    printf("\nRemovido: %d\n", *type);



    fila_imprimir(circular);
    fila_inserir(circular, 1);
    fila_inserir(circular, 11);
    printf("\n");
    fila_imprimir(circular);
//     int aux2;
//     fila_remover2(circular, &aux2); 
//     printf("\nRemovido: %d\n", aux2);

//         printf("\n");
//     fila_imprimir(circular);
//     printf("\n");

//      fila_remover2(circular, &aux2); 
//     printf("\nRemovido: %d\n", aux2);
     

  
  
//     printf("\n");
//     fila_imprimir(circular);
//     printf("\n");
    


//     fila_inserir(circular, x++);
//     fila_inserir(circular, x++);
//     fila_inserir(circular, x++);
//     fila_inserir(circular, x++);

// printf("\n");
//     fila_imprimir(circular);
//     printf("\n");
    
}

void main(){
    teste();
}