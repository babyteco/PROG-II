#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct pessoa{
    char nome[30];
    int dia, mes, ano;
    char cpf[20];
} Pessoa;

void ColocaBinario(Pessoa* p);
void LeBinario();

int main(){
    Pessoa* p = (Pessoa*) malloc(sizeof(Pessoa));
    // p->nome = (char*) malloc(30 * sizeof(char)); 
    // p->cpf = (char*) malloc(17 * sizeof(char));

    strcpy(p->nome ,"Lolly Pop");
    p->dia = 6;
    p->mes = 6;
    p->ano = 2005;
    strcpy(p->cpf ,"140.404.827-86");

    ColocaBinario(p);
    free(p);
    LeBinario();
    return 0;
}

void ColocaBinario(Pessoa* p){
    FILE *arq = fopen("arquivola", "wb");
    fwrite(p, sizeof(Pessoa), 1, arq);
    fclose(arq);   
}

void LeBinario(){
    FILE *arq = fopen("arquivola", "rb");
    Pessoa p;
    fread(&p, sizeof(Pessoa), 1, arq);
    fclose(arq);
    
    printf("NOME: %s\n", p.nome);
    printf("CPF: %s\n", p.cpf);
    printf("NASCIMENTO: %02d/%02d/%d\n", p.dia, p.mes, p.ano);
}




/*

Crie uma estrutura chamada pessoa, que armazena nome, data de nascimento e cpf
Crie e inicialize um array de pessoas
Crie uma função para salvar este array de pessoas em um arquivo binário
Crie uma função para ler o array de pessoas a partir do arquivo binário

*/