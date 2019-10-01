#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char numero[16];
    char whatsapp[2]; // S ou N;    
}Telefone;

typedef struct{
    char cep[11];
    int numero;
    char estado[3];
}Endereco;

typedef struct{
    char* nome;
    // char nome[40];
    int idade;
    char* email;
    Endereco endereco;
    Telefone* telefones[4];
    int qtdeContatos; // quantidade de contatos armazenados
}Pessoa;

typedef struct{
    char* descricao;
    Pessoa** pessoas;
    int tamVetor; // tamanho do vetor de pessoas
    int qtdePessoas; // quantidade de pessoas armazenadas
}Agenda;


Agenda* agenda_novo(char* name){
    Agenda* lista = (Agenda*) malloc(sizeof(Agenda));
    lista->pessoas = (Pessoa**) calloc(10, sizeof(Pessoa*));
    lista->tamVetor = 10;
    lista->qtdePessoas = 0;
    return lista;
}



int agenda_consultaPorEstado(Agenda* agenda, char* estado, Telefone* contatos){
    int qtdContatos = 0;
    
    for(int i = 0; i < agenda->qtdePessoas; i++){
        if(strcmp(agenda->pessoas[i]->endereco.estado, estado) == 0){
           for(int x = 0; x < agenda->pessoas[i]->qtdeContatos; x++){
            strcpy(contatos[x].numero, agenda->pessoas[i]->telefones[x]->numero);
            strcpy(contatos[x].whatsapp, agenda->pessoas[i]->telefones[x]->whatsapp);
            qtdContatos++;
           }
        }

    }
    return qtdContatos;
}



Pessoa* pessoa_novo(char* nome, int idade, char* email){
    Pessoa* novo = (Pessoa*) malloc(sizeof(Pessoa));
    novo->nome = (char*) calloc(strlen(nome) + 1, sizeof(char) );
    strcpy(novo->nome, nome);
    novo->idade = idade;
    novo->email = (char*) calloc(strlen(email) + 1, sizeof(char) );
    strcpy(novo->email, email);
    novo->qtdeContatos = 0;

    return novo;
}

void pessoa_defineEndereco(Pessoa* p, char* cep, int num, char* estado){
    strcpy(p->endereco.cep, cep);
    p->endereco.numero = num;
    strcpy(p->endereco.estado, estado);
}

void pessoa_cadastrarContato(Pessoa* p, char* numero, char* flagWhats){
    
    Telefone* contato = (Telefone*) malloc(sizeof(Telefone));
    strcpy(contato->numero, numero);
    strcpy(contato->whatsapp, flagWhats);

    p->telefones[p->qtdeContatos++] = contato;
}



void agenda_inserirPessoa(Agenda* agenda, Pessoa* p){
    if(agenda->qtdePessoas > agenda->tamVetor) return;

    agenda->pessoas[agenda->qtdePessoas++] = p;
    
}
int verifica_email(Agenda* agenda, char* email, int* index){
    for(int i = 0; i < agenda->qtdePessoas; i++){
        if(strcmp(agenda->pessoas[i]->email, email) == 0){
            *index = i;
            return 1;
        }
    }
    return 0;
}

void pessoa_desalocar(Pessoa* p){
    free(p->email);
    free(p->nome);
    free(p);
}


// Reduzir o tamanho do vetor de pessoas pela metada quando a taxa de ocupação for inferior a 25%
void agenda_verificaReduzTamanho(Agenda* agenda){
    float perc = (float) agenda->qtdePessoas/agenda->tamVetor;
    if(perc >= 0.25) return;
    
    Pessoa** pessoa_Nova = (Pessoa**) calloc(agenda->tamVetor/2, sizeof(Pessoa*));

    for(int i = 0; i < agenda->qtdePessoas; i++){
        pessoa_Nova[i] = agenda->pessoas[i];
    }

    agenda->pessoas = pessoa_Nova;
    agenda->tamVetor /= 2;
}

void shift_AgendaRemove(Pessoa** person, int tam, int index){
    for(int i = index; i < tam; i++){
        person[i] = person[i+1];
    }
}

Pessoa* agenda_removerPessoa(Agenda* agenda, char* email){
    int index;
    if(verifica_email(agenda, email, &index) == 0) return NULL;

    Pessoa* new = pessoa_novo(agenda->pessoas[index]->nome, agenda->pessoas[index]->idade, agenda->pessoas[index]->email);
    pessoa_defineEndereco(new, agenda->pessoas[index]->endereco.cep, agenda->pessoas[index]->endereco.numero, agenda->pessoas[index]->endereco.estado);

    for(int i = 0; i < agenda->pessoas[index]->qtdeContatos; i++){
        pessoa_cadastrarContato(new, agenda->pessoas[index]->telefones[i]->numero, agenda->pessoas[index]->telefones[i]->whatsapp);
    }

    pessoa_desalocar(agenda->pessoas[index]);
    shift_AgendaRemove(agenda->pessoas, agenda->qtdePessoas, index);
    agenda_verificaReduzTamanho(agenda);
    agenda->qtdePessoas--;
    return new;

}

void printa_Dados(Pessoa* a1){
    printf("=====================\n");
    printf("Nome: %s\n", a1->nome);
    printf("Idade: %d\n", a1->idade);
    printf("E-mail: %s\n", a1->email);
    printf("-----ENDEREÇO-----\n");
    printf("CEP: %s\n", a1->endereco.cep);
    printf("Numero: %d\n", a1->endereco.numero);
    printf("Estado: %s\n", a1->endereco.estado);
    printf("-----Telefone-----\n");
    for(int i = 0; i < a1->qtdeContatos; i++){
        printf("%s\n", a1->telefones[i]->numero);
    }
    printf("=====================\n");
}




int main(){
     Agenda* a1 = agenda_novo("pessoal");

    Pessoa* p1 = pessoa_novo("Joao", 30, "joao@gmail.com");
    Pessoa* p2 = pessoa_novo("Maria", 20, "maria@gmail.com");

    pessoa_defineEndereco(p1, "88.888-88", 100, "PR");
    pessoa_defineEndereco(p2, "99.999-9s9", 200, "SP");
    

    pessoa_cadastrarContato(p1, "(44) 91111-1111", "S");
    pessoa_cadastrarContato(p1, "(41) 92222-2222", "S");
    pessoa_cadastrarContato(p1, "(44) 3033-1234", "N");
    pessoa_cadastrarContato(p1, "(44) 2011-1234", "N");

    pessoa_cadastrarContato(p2, "(44) 94444-4444", "S");
    pessoa_cadastrarContato(p2, "(44) 95555-5555", "S");


    agenda_inserirPessoa(a1, p1);
    agenda_inserirPessoa(a1, p2);


    printf("Procura de numeros por estados:\n");
    printf("VETOR NUMEROS PR\n");
    Telefone vetPR[100], vetSP[100];
    int qtdeTelefones;
    qtdeTelefones = agenda_consultaPorEstado(a1, "PR", vetPR);
    for(int i = 0; i < qtdeTelefones; i++){
        printf("%s\n", vetPR[i].numero);
    }
    printf("==================\n");
    printf("VETOR NUMEROS SP\n");
     qtdeTelefones = agenda_consultaPorEstado(a1, "SP", vetSP);
    for(int i = 0; i < qtdeTelefones; i++){
        printf("%s\n", vetSP[i].numero);
    }
        
    printf("\nAntes da eliminação pos[0]: %s\n", a1->pessoas[0]->nome);
    printf("Tamanho vetor: %d\n", a1->tamVetor);
     Pessoa* removido = agenda_removerPessoa(a1, "joao@gmail.com");
        printa_Dados(removido);

    printf("\nDepois da eliminação pos[0]: %s\n", a1->pessoas[0]->nome);
    printf("Tamanho vetor: %d\n", a1->tamVetor);
    pessoa_desalocar(removido);

}