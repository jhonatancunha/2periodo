#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define OUT_OF_RANGE INT_MIN //Utilizado para indicar indice inexistente no vetor
#define SIZE_VET 5//Tamanho padrão criado no inicio



typedef int DataType;
typedef enum {false, true} Boolean;

typedef struct{
    int* vetor;
    int size;//Quantidade de campos preenchidos do vetor
    int length;//Tamanho do vetor
} Vetor;


//Cria uma struct utilizando alocação dinamica e retorna o endereço dessa struct.
//A quantidade de campos preenchido é zero.
//O tamanho do vetor inicia com o tamanho padrão cinco.
Vetor* vetor_new();

//Libera o espaço alocado na memoria do vetor informado
void vetor_free(Vetor* v);

//Imprime todo o conteudo dentro do vetor informado
void vetor_print(Vetor* m);

//Insere um valor informado no index informado pelo usuario
Boolean vetor_insert(Vetor* v, DataType element, int index);

// //Duplica o tamanho do vetor para que o mesmo tenha espaços suficientes para serem utilizado
void doubleVetor(Vetor* v);

//Faz um shift de bits para ordenar vetor
//E acrescenta o valor passado na posição
void vetor_shiftBitsAddValue(Vetor* v, int index, int number);

//Adiciona o numero no final do vetor
Boolean vetor_add(Vetor* v, DataType element);

//Remove um valor em determinada posicão do vetor
//Retorna o valor daquela posição excluida
//Tamanho do vetor reduz pela metade caso o tamamho ocupado seja menor que 25%
DataType vetor_remove1(Vetor* v, int index);

//Faz o shift de bits para reorganizar vetor depois de remover um elemento dentro dele
void vetor_shiftBitsRemoveValue(Vetor* v, int index);

//Caso a quantidade de casas ocupadas no vetor for menor que 25%
//O mesmo é diminuido pela mentade
void vetor_resize(Vetor* v);

//Remove um valor em determinada posicão do vetor
//Retorna via ponteiro o valor da posicao escolhida
//Tamanho do vetor reduz pela metade caso o tamamho ocupado seja menor que 25%
Boolean vetor_remove2(Vetor* v, int index, DataType* ptr);

//Remove o elemento da primeira posição
//Posição invalida = OUT_OF_RANGE
//Retorna o valor da posicao escolhida
//Tamanho do vetor reduz pela metade caso o tamamho ocupado seja menor que 25%
DataType vetor_shift1(Vetor* v);

//Remove o elemento da primeira posição
//Posicao Invalida = false
//Retorna via ponteiro o valor da posicao escolhida
//Tamanho do vetor reduz pela metade caso o tamamho ocupado seja menor que 25%
Boolean vetor_shift2(Vetor* v, DataType* ptr);

//Acessa e retorna um valor do vetor pelo indice passado na função
//Posicao invalida = OUT_OF_RANGE
DataType vetor_get1(Vetor* v, int index);

//Acessa e retorna como ponteiro o valor em determinada posicao caso seja válida
//Posicao Inválida = false
Boolean vetor_get2(Vetor* v, int index, DataType *ptr);

//Acessa determinada posicao do vetor
//Retorna o endereço da posicao onde está armazenada o valor sugerido
//Posição Inválida = NULL
DataType* vetor_get3(Vetor* v, int index);


//Verifica se a posicao informada é invalida
//Caso for retorna true
Boolean posicaoInvalida(Vetor* v, int index);

//Verifica se o vetor está vazio
//Retorna true caso esteja vazio
Boolean vetor_isEmpty(Vetor* v);

//Altera um elemento na posicao informada caso essa posição seja valida
//Posição Inválida = false
Boolean vetor_set(Vetor* v, int index, DataType valor);

//Realiza a operação de determinada função passada por parâmetro em todos os elementos do vetor
void vetor_map(Vetor* v, void (*funcao)(DataType*));

//Cria um sub-vetor a partir do indice informado
//Quando o índice é negativo, ele representará as posições do fim para o inicio.
// Por exemplo, o índice ́-1́  representa a última posição do vetor, ‒2 a penúltima e assim por diante.
//Retorna o endereço do novo sub-vetor
//Caso Indice for invalido retorna NULL;
Vetor* vetor_sub1(Vetor* v, int index);


//Cria um sub-vetor do vetor informado
//Em relação ao intervalo de indices informados
//Retorna o endereço do novo sub-vetor
//Caso o intervalo for invalido retorna NULL;
Vetor* vetor_sub2(Vetor* v, int start, int end);

//Função que auxilia a criação do sub-vetor no tamanho ideal para a atribuição de dados
Vetor* vetor_copyForSubVetor(Vetor* v,int index);

//Função que auxilia a criação do sub-vetor no tamanho ideal para a atribuição de dados
Vetor* vetor_copyForSubVetor2(int start, int end);

//Retorna o tamanho do vetor
int vetor_size(Vetor* v);

//Função para atribuir valor ao sub-vetor
//v = vetor original
//subv = sub-vetor do vetor original
//index = posicao inicial
//end = posicao final onde quer a copia
void vetor_subAtribui(Vetor* v, Vetor* subv,int index, int end);

//Usada para criar um vetor filtrado por uma função passada por parametro
//Como usar?
//Passe o vetor original
//E passe a função que você queira aplicar nele
//E ele retornara um vetor novo de acordo com o filtro estabelecido
//Ex: UM VETOR SOMENTE DE NUMEROS PARES
Vetor* vetor_filter(Vetor* v, Boolean (*funcao)(DataType*));

//Função de ordenação de vetores
//Só funciona com valores numericos
void vetor_sort(Vetor* v);


//Funcao troca auxilia na ordenação de vetores com valores numericos
void troca(int* n1, int* n2);

//Função generica de ordenação de vetores
//Recebe um ponteiro de função mostrará por qual criterio o vetor sera ordenado
void vetor_genericSort(Vetor* v, int (*pfuncao)(DataType* a, DataType* b));

//Importa valores presentes em um arquivo txt para dentro do vetor
//Valores com o seguinte padrão: {12,33, 44, 55}
int vetor_import(Vetor* v, char* nomeArquivo);

//Auxilia a funcao vetor_import
//é usada para contar os caracteres do numero ate a primeira virgula dentro do arquivo txt
int cont_QTD(FILE* arq);


//Salva o vetor na memoria
/*
* Parâmetros
* v: endereço do TAD na memória
* nomeArquivo: nome do arquivo a ser criado
*
* Retorno: número de bytes armazenados no arquivo
*/
//Salva somente um vetor em cada arquivo
int vetor_save(Vetor* v, char* nomeArquivo);


/*
* Parâmetros
* nomeArquivo: nome do arquivo a ser lido
*
* Retorno: endereço do TAD vetor criado e carregado na memória
*/
Vetor* vetor_load(char* nomeArquivo);


Vetor* vetor_load(char* nomeArquivo){
    Vetor* vLoad = vetor_new();
    FILE* arq = fopen(nomeArquivo, "rb");
    if(arq == NULL) return NULL;

    fread(vLoad, sizeof(*vLoad),1 , arq);

    for(int i = 0; i < vLoad->size; i++){
       fread(&vLoad->vetor[i], sizeof(int), 1, arq);
    }

    fclose(arq);
    return vLoad;
}

int vetor_save(Vetor* v, char* nomeArquivo){
    FILE* saved;
    saved = fopen(nomeArquivo, "wb");

    if(saved == NULL) return -1;

    fwrite(v, sizeof(*v), 1, saved);

    for(int i = 0; i < v->size; i++){
       fwrite(&v->vetor[i], sizeof(int), 1, saved);
    }

    if(ferror(saved)) return -1;
    fclose(saved);
    return sizeof(*v) + sizeof(int) * v->size;
}

int cont_QTD(FILE* arq){
    int cont= 0;
    while(feof(arq) == 0){
        char c = fgetc(arq);
        if(c != ' ' && c != ','){
            cont++;
        
       }else{
            fseek(arq, sizeof(char), SEEK_CUR);
            printf("Numeros de bytes: %d\n", cont);
            return cont;
       }
    }
}

int vetor_import(Vetor* v, char* nomeArquivo){
    FILE* arq = fopen(nomeArquivo, "r");
    FILE* arqAux = fopen(nomeArquivo, "r");


    if(arq == NULL) return -1;

    int i = 0;
    int qtdNumbers = 0;

    char* num = (char*) calloc(cont_QTD(arqAux)+1, sizeof(char));

    printf("NUMEROS: %d\n", sizeof(num));


     while(feof(arq) == 0){
        char c = fgetc(arq);
        if( c != ',' && !feof(arq)){
            num[i] = c;
            i++;
       }else{
          
            i=0;
            int aux = atoi(num);
            vetor_add(v, aux);
            free(num);
            num = (char*) calloc(cont_QTD(arqAux)+1, sizeof(char));
            qtdNumbers++;
       }
     }
     free(num);
    fclose(arq);
    return qtdNumbers;
}


void vetor_genericSort(Vetor* v, int (*pfuncao)(DataType* a, DataType* b)){
    for(int x = v->size-1; x > 0; x--){
        int flag = 0;
        for(int i = 0; i < x; i++){
            if(pfuncao(&v->vetor[i], &v->vetor[i+1]) == 1){
                troca(&v->vetor[i], &v->vetor[i+1]);
                flag = 1;
            }
        }
        if(flag == 0) return;
    }
}

void troca(int* n1, int* n2){
    int aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}


void vetor_sort(Vetor* v){
    for(int i = v->size-1; i > 0 ; i--){
        int flag = 0;
        for(int x = 0; x < i; x++){
            if(v->vetor[x] > v->vetor[x+1]){
                troca(&v->vetor[x], &v->vetor[x+1]);
                flag = 1;
            }
        }
        if(flag == 0) return;
    } 
}   

Vetor* vetor_filter(Vetor* v, Boolean (*funcao)(DataType*)){
    Vetor* filtrado = vetor_new();

    for(int i = 0; i < v->size; i++){
        if(funcao((v->vetor+i))){
            vetor_add(filtrado, v->vetor[i]);
        }
    }

    return filtrado;
}

void vetor_map(Vetor* v, void (*funcao)(DataType*)){
    for(DataType i = 0; i< v->size; i++){
        funcao(v->vetor+i);
    }
}
 

Vetor* vetor_new(){
    Vetor* v0 = (Vetor*) malloc(sizeof(Vetor));
    v0->vetor = (DataType*) calloc(SIZE_VET, sizeof(DataType));
    v0->size = 0;
    v0->length = SIZE_VET;
    return v0;
}

int vetor_size(Vetor* v){
    return v->size;
}

void vetor_free(Vetor* v){
    free(v->vetor);
    free(v);
}

void vetor_print(Vetor* m){
    if(m->size == 0){
        printf("Vetor Vazio!\n");
    }else{
        printf("(");
        for(DataType i = 0; i < m->size; i++){
            if(i == m->size - 1){
                printf("%d)\n", m->vetor[i]);
            }else{
                printf("%d, ",m->vetor[i]);
            }
        }
    }
}

void doubleVetor(Vetor* v){
    DataType* vet1 = (DataType*) calloc((v->length)*2, sizeof(DataType));

    for(DataType i = 0; i < v->size; i++){
        vet1[i] = v->vetor[i];
    }

    v->length *= 2;
    free(v->vetor);
    v->vetor = vet1;
}

Vetor* vetor_copyForSubVetor(Vetor* v,int index){
    Vetor* v1Copy = (Vetor*) malloc(sizeof(Vetor));
    v1Copy->vetor = (DataType*) calloc((v->size - index), sizeof(DataType));
    v1Copy->size = 0;
    v1Copy->length = v->size - index;
    return v1Copy;
}

Vetor* vetor_copyForSubVetor2(int start, int end){
    Vetor* v2Copy = (Vetor*) malloc(sizeof(Vetor));
    v2Copy->vetor = (DataType*) calloc(end-start, sizeof(DataType));
    v2Copy->size = 0;
    v2Copy->length = end-start;
    return v2Copy;
}

void vetor_subAtribui(Vetor* v, Vetor* subv,int index, int end){
    int cont = 0;
    for(DataType i = index; i < end; i++){
        subv->vetor[cont] = v->vetor[i];
        cont++;
        subv->size++;
    }
}

Vetor* vetor_sub2(Vetor* v, int start, int end){
    if(posicaoInvalida(v, start) || posicaoInvalida(v,end+1)) return NULL;

    Vetor* subVetor =  vetor_copyForSubVetor2(start, end);
    vetor_subAtribui(v, subVetor,start, end+1);

    return subVetor;
}


Vetor* vetor_sub1(Vetor* v, int index){
    if(index < 0) index += v->size-1;
    if(posicaoInvalida(v, index)) return NULL;

    Vetor* subVetor = vetor_copyForSubVetor(v, index);
    vetor_subAtribui(v, subVetor,index, v->size);

    return subVetor;
}

Boolean vetor_set(Vetor* v, int index, DataType valor){
    if(posicaoInvalida(v, index)) return false;

    v->vetor[index] = valor;
    return true;
}

Boolean posicaoInvalida(Vetor* v, int index){
    return (index > v->size || index < 0 ? true: false);
}


DataType vetor_get1(Vetor* v, int index){
    if(posicaoInvalida(v, index) || vetor_isEmpty(v))   return OUT_OF_RANGE;
    return v->vetor[index];
}

Boolean vetor_get2(Vetor* v, int index, DataType *ptr){
    if(posicaoInvalida(v, index) || vetor_isEmpty(v)) return false;
    *ptr = v->vetor[index];
    return true;
}

DataType* vetor_get3(Vetor* v, int index){
    if(posicaoInvalida(v, index) || vetor_isEmpty(v))   return NULL;
    return &v->vetor[index];
}


void vetor_shiftBitsAddValue(Vetor* v, int index, int number){
    DataType aux = v->vetor[index];
    v->vetor[index] = number;

    for(DataType i = ++index; i <= v->size; i++){
        DataType reserve = v->vetor[i];
        v->vetor[i] = aux;
        aux = reserve;
    }
    v->size++;
}

void vetor_shiftBitsRemoveValue(Vetor* v, int index){
    for(DataType i = index; i < v->size; i++){
        v->vetor[i] = v->vetor[i+1];
    }
    v->size--;
}

void vetor_resize(Vetor* v){
    float media = (float)v->size/v->length;

    if(media < 0.25){
        DataType* vet1 = (DataType*) calloc((v->length)/2, sizeof(DataType));

        for(DataType i = 0; i < v->size; i++){
            vet1[i] = v->vetor[i];
        }

        v->length /= (DataType)2;
        free(v->vetor);
        v->vetor = vet1;
    }
}

DataType vetor_shift1(Vetor* v){
    if(vetor_isEmpty(v)) return OUT_OF_RANGE;

    DataType aux = v->vetor[0];
    vetor_shiftBitsRemoveValue(v, 0);
    vetor_resize(v);
    return aux;
}

Boolean vetor_isEmpty(Vetor* v){
   return (v->size == 0 ? true : false);
}

Boolean vetor_shift2(Vetor* v, DataType* ptr){
    if(vetor_isEmpty(v)) return false;

    *ptr = v->vetor[0];
    vetor_shiftBitsRemoveValue(v, 0);
    vetor_resize(v);
    return true;
}

DataType vetor_remove1(Vetor* v, int index){
    if(posicaoInvalida(v, index)) return OUT_OF_RANGE;

    DataType aux = v->vetor[index];
    vetor_shiftBitsRemoveValue(v, index);
    vetor_resize(v);
    return aux;
}

Boolean vetor_remove2(Vetor* v, int index, DataType* ptr){
    if(posicaoInvalida(v, index)) return false;

    *ptr = v->vetor[index];
    vetor_shiftBitsRemoveValue(v, index);
    vetor_resize(v);
    return true;
}

Boolean vetor_add(Vetor* v, DataType element){
    if(v->size > v->length)
        doubleVetor(v);

    v->vetor[v->size] = element;
    v->size++;
    return true;
}

Boolean vetor_insert(Vetor* v, DataType element, int index){
      if(posicaoInvalida(v, index)) return false;
      if(v->size == v->length){
            doubleVetor(v);
            vetor_shiftBitsAddValue(v, index, element);
            return true;
      }else if(index < v->size && index >= 0){
            vetor_shiftBitsAddValue(v, index, element);
            return true;
      }else{
          v->vetor[index] = element;
          v->size += 1;
          return true;
      }
}