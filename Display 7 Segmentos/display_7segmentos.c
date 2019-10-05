#include<stdio.h>


//FUNÇÕES LÓGICAS
int f_2OR(int a, int b){
    if((a < 0 || a > 1) || (b < 0 || b > 1) ) return -1;
    return (a || b == 1) ? 1 : 0; 
}

int f_3OR(int a, int b, int c){
    if((a < 0 || a > 1) || (b < 0 || b > 1) || (c < 0 || c > 1) ) return -1;
    return (a || b || c == 1) ? 1 : 0; 
}

int f_4OR(int a, int b, int c, int d){
    if((a < 0 || a > 1) || (b < 0 || b > 1) || (c < 0 || c > 1) || (d < 0 || d > 1) ) return -1;
    return (a || b || c || d == 1) ? 1 : 0; 
}

int f_2AND(int a, int b){
    if((a < 0 || a > 1) || (b < 0 || b > 1) ) return -1;
    return (a && b == 1) ? 1: 0;
}


int f_3AND(int a, int b, int c){
    if((a < 0 || a > 1) || (b < 0 || b > 1) || (c < 0 || c > 1) ) return -1;
    return (a && b && c == 1) ? 1: 0;
}

int fNOT(int a){
    if((a < 0 || a > 1)) return -1;
    return (a == 0) ? 1: 0;
}

int f_2XOR(int a, int b){
    if((a < 0 || a > 1) || (b < 0 || b > 1) ) return -1;
    return (a != b) ? 1 : 0;
}

void main(){
//ENTRADAS
    int e1 = 0;//A
    int e2 = 0;//B
    int e3 = 0;//C
    int e4 = 1;//D

//SAIDAS DO DISPLAY (7 SEGMENTOS)
    int a = f_4OR(f_2AND(e3, f_3OR(fNOT(e4),fNOT(e1),e2)), f_2AND(fNOT(e3), f_2AND(e1, f_2OR(fNOT(e2),fNOT(e4)))), f_3AND(fNOT(e1),e2,e4),f_2AND(fNOT(e2),fNOT(e4)));
    
    int b = f_3OR( f_2AND( fNOT(e1), f_3OR(fNOT(e2), f_2AND(fNOT(e3), fNOT(e4)), f_2AND(e3,e4) )), f_3AND(e1, fNOT(e3), e4), f_2AND(fNOT(e2), fNOT(e4))); 

    int c = f_3OR( f_2AND( fNOT(e1), f_3OR( e2, e4, fNOT(e3) ) ), f_2AND( e1, fNOT(e2) ), f_2AND( fNOT(e3), e4 ) );

    int d = f_2OR( f_2AND( fNOT(e4), f_3OR( f_2AND(fNOT(e1), fNOT(e2) ), f_2AND(e2,e3), f_2AND(e1, fNOT(e3)) )),  f_2AND(e4, f_2XOR(e3,e2)) );
    
    int e = f_2OR( f_2AND( fNOT(e4), f_2OR(fNOT(e2), e3) ), f_2AND(e1, f_2OR(e2, e3)) );

    int f = f_3OR( f_2AND( e1, f_2OR( fNOT(e2), e3 ) ), f_2AND( e2, f_2OR( f_2AND(e3, fNOT(e4)), f_2AND( fNOT(e1), fNOT(e3) ) ) ), f_2AND(fNOT(e3), fNOT(e4)) );

    int g = f_3OR( f_2AND(e1, f_3OR(e3, e4, fNOT(e2))), f_2AND(e3, f_2OR(fNOT(e4), fNOT(e2))), f_3AND( fNOT(e1), e2, fNOT(e3)) );

//CONDIÇÕES DE PRINTS USADO PARA TESTAR CIRCUITO
    if(a == 1 && b == 1 && c == 1 && d == 1 && e == 1 & f == 1 && g == 0){
        printf("0");
    }else  if(a == 0 && b == 1 && c == 1 && d == 0 && e == 0 & f == 0 && g == 0){
        printf("1");
    }else  if(a == 1 && b == 1 && c == 0 && d == 1 && e == 1 & f == 0 && g == 1){
        printf("2");
    }else if(a == 1 && b == 1 && c == 1 && d ==1 && e == 0 & f == 0 && g == 1){
        printf("3");
    }else if(a == 0 && b == 1 && c == 1 && d == 0 && e == 0 & f == 1 && g == 1){
        printf("4");
    }else if(a == 1 && b == 0 && c == 1 && d == 1 && e == 0 & f == 1 && g == 1){
        printf("5");
    }else if(a == 1 && b == 0 && c == 1 && d == 1 && e == 1 & f == 1 && g == 1){
        printf("6");
    }else if(a == 1 && b == 1 && c == 1 && d == 0 && e == 0 & f == 0 && g == 0){
        printf("7");
    }else if(a == 1 && b == 1 && c == 1 && d == 1 && e == 1 & f == 1 && g == 1){
        printf("8");
    }else if(a == 1 && b == 1 && c == 1 && d == 0 && e == 0 & f == 1 && g == 1){
        printf("9");
    }else if(a == 1 && b == 1 && c == 1 && d == 0 && e == 1 & f == 1 && g == 1){
        printf("A");
    }else if(a == 0 && b == 0 && c == 1 && d == 1 && e == 1 & f == 1 && g == 1){
        printf("B");
    }else if(a == 1 && b == 0 && c == 0 && d == 1 && e == 1 & f == 1 && g == 0){
        printf("C");
    }else if(a == 0 && b == 1 && c == 1 && d == 1 && e == 1 & f == 0 && g == 1){
        printf("D");
    }else if(a == 1 && b == 0 && c == 0 && d == 1 && e == 1 & f == 1 && g == 1){
        printf("E");
    }else if(a == 1 && b == 0 && c == 0 && d == 0 && e == 1 & f == 1 && g == 1){
        printf("F");
    }else{
        printf("ERRO: Valores de entradas invalidos.\n");
    }
}