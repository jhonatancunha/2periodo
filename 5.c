
// Escreva um algoritmo para um caixa eletrônico que dado um valor a ser sacado calcule o menor número de
// cédular possível. Considere que sempre haverá quantidade suficiente de cédulas para efetuar o saque.
// As cédulas disponíveis são: 100, 50, 20, 10, 5 e 2.
// Obs.: Garanta que o valor informado será

#include<stdio.h>

void saque(float* saldo, int* cem, int* cinquenta, int* vinte, int* dez, int* cinco, int* dois, float* resto){
  if(*saldo >= 100){
      *cem = *saldo / 100;
      *saldo = (int) *saldo % 100;
      *resto -= 100 * (*cem);
  }else if(*saldo >= 50){
      *cinquenta = *saldo / 50;
      *saldo = (int) *saldo % 50;
      *resto -= 50 * (*cinquenta);
  }else if(*saldo >= 20){
    *vinte = *saldo / 20;
    *saldo = (int) *saldo %20;
    *resto -= 20 * (*vinte);
  }else if(*saldo >= 10){
    *dez = *saldo / 10;
    *saldo = (int) *saldo % 10;
    *resto -= 10 * (*dez);
  }else if(*saldo >= 5){
    *cinco = *saldo / 5;
    *saldo = (int) *saldo % 5;
    *resto -= 5 * (*cinco);
  }else if(*saldo >= 2){
    *dois = *saldo / 2;
    *saldo = (int) *saldo % 2;
    *resto -= 2 * (*dois);
  }
}

void main(){
  float saldo = 500.50;
  float resto = saldo;
  int cem = 0;
  int cinquenta = 0;
  int vinte = 0;
  int dez = 0;
  int cinco = 0;
  int dois = 0;


printf("Total: R$%.2f\n\n", saldo);
  while(saldo != 0){
      saque(&saldo, &cem, &cinquenta, &vinte, &dez, &cinco, &dois, &resto);
      if(cem > 0){
        printf("%d notas de cem reais, ", cem);
        cem = 0;
      }else if(cinquenta > 0){
        printf("%d notas de cinquenta reais, ", cinquenta);
        cinquenta = 0;
      }else if(vinte > 0){
        printf("%d notas de vinte reais, ", vinte);
        vinte = 0;
      }else if(dez > 0){
        printf("%d notas de dez reais, ", dez);
        dez = 0;
      }else if(cinco > 0){
        printf("%d notas de cinco reais, ", cinco);
        cinco = 0;
      }else if(dois > 0){
        printf("%d notas de dois reais, ", dois);
        dois = 0;
      }
    }
printf("\n\nAtual: R$%.2f\n", resto);

}
