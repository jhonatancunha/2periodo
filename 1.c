#include<stdio.h>
float potencia(float num, float vezes){

  if(vezes < 0){
    float r = 1;
    vezes = vezes * -1;
      for(int i = 0; i < vezes; i++){
        r = r * num;
      }

      return 1/r;
  }else if(vezes == 0){
    return 1;
  }else{

      float r = 1;
      for(int i = 0; i < vezes; i++){
        r = r * num;
      }
      return r;

  }
}

void main(){

  float numero = 2;
  float vezes = 0;
  float resp = potencia(numero,vezes);

  printf("%.2f\n",resp);

}
