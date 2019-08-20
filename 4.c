#include<stdio.h>
#include<string.h>

 int contCMes(int mes){
       switch (mes)
       {
       case 1:
             return 8;
             break;
       
       case 2:
             return 10;
             break;
       
       case 3:
             return 6;
             break;
       
       case 4:
             return 6;
             break;
       
       case 5:
             return 5;
             break;
       
       case 6:
             return 6;
             break;
       
       case 7:
             return 6;
             break;
       
       case 8:
             return 7;
             break;
       
       case 9:
             return 9;
             break;
       
       case 10:
             return 8;
             break;
       
       case 11:
             return 9;
             break;
       
       case 12:
             return 9;
             break;

       }
 }

int contCDia(int dia){
    switch (dia) {
      case 1:
            return 3;
            break;
      case 2:
            return 6;
      break;

      case 3:
            return 5;
      break;

      case 4:
            return 7;
      break;

      case 5:
            return 6;
      break;

      case 6:
            return 5;
      break;

      case 7:
            return 5;
      break;

      case 8:
            return 5;
      break;

      case 9:
            return 5;
      break;

      case 10:
            return 4;
      break;

      case 11:
            return 5;
      break;

      case 12:
            return 5;
      break;

      case 13:
            return 6;
      break;

      case 14:
            return 9;
      break;

      case 15:
            return 7;
      break;

      case 16:
            return 10;
      break;

      case 17:
            return 10;
      break;

      case 18:
            return 8;
      break;

      case 19:
            return 9;
      break;

      case 20:
            return 6;
      break;

      case 21:
            return 11;
      break;

      case 22:
            return 13;
      break;

      case 23:
            return 13;
      break;

      case 24:
            return 15;
      break;

      case 25:
            return 14;
      break;

      case 26:
            return 13;
      break;

      case 27:
            return 13;
      break;

      case 28:
            return 13;
      break;

      case 29:
            return 13;
      break;

      case 30:
            return 7;
      break;

      case 31:
            return 12;
      break;
      default: return -1;
      break;
    }
}

void retornaMesString(int mes, char *stringMes){
      switch (mes) {
      case 1:
            strcpy(stringMes,"janeiro");
            break;
      
      case 2:
            strcpy(stringMes,"fevereiro");
            break;
      
      case 3:
            strcpy(stringMes,"março");
            break;
      
      case 4:
            strcpy(stringMes,"abril");
            break;
      
      case 5:
            strcpy(stringMes,"maio");
            break;
      
      case 6:
            strcpy(stringMes,"junho");
            break;
      
      case 7:
            strcpy(stringMes,"julho");
            break;
      
      case 8:
            strcpy(stringMes,"agosto");
            break;
      
      case 9:
            strcpy(stringMes,"setembro");
            break;
      
      case 10:
            strcpy(stringMes,"outubro");
            break;
      
      case 11:
            strcpy(stringMes,"novembro");
            break;
      
      case 12:
            strcpy(stringMes,"dezembro");
            break;
      
    }
}

void retornaDiaString(int dia, char *stringDia){
      switch (dia)
      {
      case 1:
            strcpy(stringDia, "Um");
      break;
      case 2:
            strcpy(stringDia, "Dois");
      break;

      case 3:
            strcpy(stringDia, "Tres");
      break;

      case 4:
            strcpy(stringDia, "Quatro");
      break;

      case 5:
           strcpy(stringDia, "Cinco");
      break;

      case 6:
            strcpy(stringDia, "Seis");

      case 7:
            strcpy(stringDia, "Sete");
      break;

      case 8:
            strcpy(stringDia, "Oito");
      break;

      case 9:
           strcpy(stringDia, "Nove");
      break;

      case 10:
            strcpy(stringDia, "Dez");
      break;

      case 11:
           strcpy(stringDia, "Onze");
      break;

      case 12:
            strcpy(stringDia, "Doze");
      break;

      case 13:
            strcpy(stringDia, "Treze");
      break;

      case 14:
            strcpy(stringDia, "Quatorze");
      break;

      case 15:
            strcpy(stringDia, "Quinze");
      break;

      case 16:
            strcpy(stringDia, "Dezesseis");
      break;

      case 17:
            strcpy(stringDia, "Dezesete");
      break;

      case 18:
            strcpy(stringDia, "Dezoito");
      break;

      case 19:
           strcpy(stringDia, "Dezenove");
      break;

      case 20:
            strcpy(stringDia, "Vinte");
      break;

      case 21:
           strcpy(stringDia, "Vinte e um");
      break;

      case 22:
            strcpy(stringDia, "Vinte e dois");
      break;

      case 23:
            strcpy(stringDia, "Vinte e tres");
      break;

      case 24:
           strcpy(stringDia, "Vinte e quatro");
      break;

      case 25:
           strcpy(stringDia, "Vinte e cinco");
      break;

      case 26:
           strcpy(stringDia, "Vinte e seis");
      break;

      case 27:
           strcpy(stringDia, "Vinte e sete");
      break;

      case 28:
            strcpy(stringDia, "Vinte e oito");
      break;

      case 29:
            strcpy(stringDia, "Vinte e nove");
      break;

      case 30:
           strcpy(stringDia, "Trinta");
      break;

      case 31:
            strcpy(stringDia, "Trinta e um");
      break;
      }
      
      
}

void main(){
      int dia = 12;
      int mes = 8;
      int ano = 2019;

      int stringDia = contCDia(dia);
      int stringMes = contCMes(mes);

      char cDia[stringDia];
      char cMes[stringMes];
      retornaMesString(mes, cMes);
      retornaDiaString(dia, cDia);

      printf("%d/%d/%d: %s de %s de %d.\n", dia, mes, ano, cDia, cMes, ano);
}
