#include<stdio.h>

float normal(float n, float expoente){

    if(expoente == 0){return 1;}

    if(expoente < 0){

          expoente *= -1;

          for(int i = 1; i < expoente; i++){
              n *= n;
          }

          return 1/n;

    }else{

          for(int i = 1; i < expoente; i++){
              n = n * n;
          }

          return n;
    }
}


int metodoscanf(float n, float expoente, float* res){
  if(expoente == 0){ *res = 1; return 1;}

  if(expoente < 0){
    expoente *= -1;

    for(int i = 1; i < expoente; i++){
        n *= n;
    }

    *res =  1/n;
    return 1;
}else{

    for(int i = 1; i < expoente; i++){
        n = n * n;
    }

    *res = n;

    }
}

void main(){

  printf("%.2f\n", normal(2,2));
  printf("%.2f\n", normal(2,0));
  printf("%.2f\n", normal(2,-2));

  float res = 0;
  printf("\nscanf\n\n");

  metodoscanf(8,2, &res);
  printf("%.2f\n", res);

  metodoscanf(4,0, &res);
  printf("%.2f\n", res);

  metodoscanf(4,-2, &res);
  printf("%.2f\n", res);
}
