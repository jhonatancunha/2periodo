#include<stdio.h>

int returnInverso(int num){
  int numResto = 0;
  int inv = 0;
  while(num > 0){
    numResto = num % 10;
    inv = (inv * 10) + numResto;
    num = num / 10;
  }
  return inv;
}

void reverseNumber(int* number, int* inversoFuncao){
    *inversoFuncao = *number % 10;
    *number = *number / 10;
}

int qtdCaracter(int numero){
  int cont = 0;
    do{
      numero /= 10;
      cont++;
    }while(numero != 0);
    return cont - 1;
}

void main(){
  int decimal = 4563;
  int qtd = qtdCaracter(numero);


      printf("%d\n",returnInverso(512));
      printf("%d\n",returnInverso(9985));
      printf("%d\n\n",returnInverso(12));

      for(int i =0; i <= qtd; i++){
        int inverso = 0;
        reverseNumber(&numero, &inverso);
        printf("%d", inverso);
      }

}
