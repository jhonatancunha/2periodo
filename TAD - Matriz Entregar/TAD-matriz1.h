#include<stdlib.h>

typedef struct{
    int** m;
    int linhas;
    int colunas;
} Matriz;

Matriz* cria_matriz(int linhas, int colunas);

void addValor_matriz(Matriz* matriz, int valor);
void print_Matriz(Matriz* matriz);
int matriz_atribui(Matriz *m, int lin, int col, int valor);
int* acessa_Matriz(Matriz* matriz, int linha, int coluna);
void matriz_acessa2(Matriz *m, int lin, int col, int *end);
void delete_Matriz(Matriz *matriz);
int matriz_linhas(Matriz* m);
int matriz_colunas(Matriz* m);
void matriz_map1(Matriz* m, void (*funcao)(int*));
int* matriz_cloneLinha(Matriz* m, int linha, int* tamanho);
int* matriz_cloneColuna(Matriz* m, int coluna,int* tamanho);
Matriz* matriz_multiplica(Matriz* a, Matriz* b);
int matriz_ehQuadrada(Matriz* m);
int matriz_ehIdentidade(Matriz* m);
Matriz* matriz_transposta(Matriz* m);
Matriz* matriz_oposta(Matriz* m);
int matriz_ehDiagonal(Matriz* m);



Matriz* cria_matriz(int linhas, int colunas){
    Matriz *m1 = malloc(sizeof(Matriz));

    m1->m = (int**) calloc(linhas, sizeof(int*));

    for(int i = 0; i < linhas; i++){
      m1->m[i] = (int*) calloc(colunas,sizeof(int));
    }

    m1->colunas = colunas;
    m1->linhas = linhas;

    return m1;
}

int matriz_atribui(Matriz *m, int lin, int col, int valor){
    if(lin > m->linhas || col > m->colunas) return -1;

    m->m[lin][col] = valor;
    return 1;
}

void matriz_map1(Matriz* m, void (*funcao)(int*)){
    for(int i = 0; i < m->linhas; i++){
        funcao(m->m[i]);
      }
}

int matriz_ehDiagonal(Matriz* m){
    if(!matriz_ehQuadrada(m)) return -1;
    int cont = 0;

    for(int i = 0; i < m->linhas; i++){
      for(int j = 0; j < m->colunas; j++){
        if(i != j){
          if(m->m[i][j] == 0){
            cont++;
          }
        }
      }
    }

    if(cont == (m->linhas*m->colunas)-m->linhas){
      return 1;
    }else{
      return 0;
    }
}


int matriz_ehIdentidade(Matriz* m){
    if(!matriz_ehQuadrada(m)) return -1;
    int cont = 0;
    int cont2 =0;

    for(int i = 0; i < m->linhas; i++){
      for(int j = 0; j < m->colunas; j++){
        if(i==j){
          if((m->m[i][j] == 1)){ cont++; }
        }else{
          if(m->m[i][j] == 0){
            cont2++;
          }
        }
      }
    }

    if(cont == m->linhas && cont2 == (m->linhas*m->colunas)-m->linhas){
      return 1;
    }else{
      return 0;
    }
}

Matriz* matriz_oposta(Matriz* m){
  Matriz* oposta = cria_matriz(m->linhas, m->colunas);

  for(int i = 0; i < m->linhas; i++){
    for(int j = 0; j < m->colunas; j++){
      int aux = m->m[i][j] *-1;
      oposta->m[i][j] =  aux;
    }
  }

  return oposta;
}

Matriz* matriz_transposta(Matriz* m){
  Matriz* transposta = cria_matriz(m->colunas, m->linhas);

  for(int i = 0; i < m->colunas; i++){
    for(int j = 0; j < m->linhas; j++){
      transposta->m[i][j] = m->m[j][i];
    }
  }

  return transposta;
}

void addValor_matriz(Matriz* matriz, int valor){

      for(int i = 0; i < matriz->linhas; i++){
        for(int j = 0; j < matriz->colunas; j++){
          matriz -> m[i][j] = valor;
        }
      }

}

void print_Matriz(Matriz *matriz){
    for(int i = 0; i < matriz->linhas; i++){
      for(int j = 0; j < matriz->colunas; j++){
        printf("%d\t", matriz -> m[i][j]);
      }
      printf("\n");
    }
  }

Matriz* matriz_multiplica(Matriz* a, Matriz* b){
  if(a->colunas != b->linhas) return NULL;

  Matriz* copia = cria_matriz(a->linhas , b-> colunas);

  int aux= 0;
  int j = 0;

  for(int i = 0; i < copia->linhas; i++){
      for(j = 0; j < copia->colunas; j++){
        for(int k = 0; k < a->colunas; k++){
          aux += (a->m[i][k]) * (b->m[k][j]);
        }
        copia->m[i][j] = aux;
        aux = 0;
      }
    }


  return copia;
}


int* matriz_cloneLinha(Matriz* m, int linha,int* tamanho){
    if(linha > m->linhas) return NULL;

    int *clone = calloc(m->colunas, sizeof(int));
    int i;
    for(i = 0; i < m->colunas; i++){
      clone[i] = m->m[linha][i];
    }
    *tamanho = i;
    return clone;
}

int matriz_ehQuadrada(Matriz* m){
  if(m->linhas == m->colunas){return 1;}  else {return 0;}
}

int* matriz_cloneColuna(Matriz* m, int coluna,int* tamanho){
    if(coluna > m->colunas) return NULL;

    int *clone = calloc(m->linhas, sizeof(int));
    int i;
    for(i = 0; i < m->linhas; i++){
      clone[i] = m->m[i][coluna];
    }
    *tamanho = i;
    return clone;
}

int* acessa_Matriz(Matriz* matriz, int linha, int coluna){
  if(linha >= matriz->linhas || coluna >= matriz->colunas) return NULL;

  int* valor = (int*) malloc(sizeof(int));
  *valor = matriz->m[linha][coluna];
  return valor;
}

void matriz_acessa2(Matriz *m, int lin, int col, int *end){
  if(lin >= m->linhas || col >= m->colunas) end = NULL;
  *end = m->m[lin][col];
}


int matriz_linhas(Matriz* m){
  return m->linhas;
}
int matriz_colunas(Matriz* m){
  return m->colunas;
}



void delete_Matriz(Matriz *matriz){

  for(int i = 0; i < matriz->linhas; i++){
      free(matriz->m[i]);
  }

  free(matriz->m);
  free(matriz);

}
