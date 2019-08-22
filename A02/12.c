#include<stdio.h>
void main(){

short int i1 = 100;
short int i2 = 200;
short int i3 = 300;

short int *v2[3];

v2[0] = &i1;
v2[1] = &i2;
v2[2] = &i3;

//Printando conteudo aonde cada posicao do vetor de ponteiro está apontando;
printf("%u\n", *(*v2));
printf("%u\n", *(*(v2+1)));
printf("%u\n", *(*(v2+2)));
printf("\n\n");
//Printando o endereço que está armazenado dentro do vetor de ponteiros;
printf("%u\n", *(v2));
printf("%u\n", *(v2+1));
printf("%u\n", *(v2+2));
printf("\n\n");
//Printando endereço de cada variavel criada acima;
printf("%u\n", &i1);
printf("%u\n", &i2);
printf("%u\n", &i3);
}
