#include<stdio.h>
#include<stdlib.h>
#include"paciente.h"
#include "data.h"
#include "lesao.h"

#define TAM_NOME 100
#define TAM_SUS 19

typedef struct
{
    char *nome;            // salva o nome do paciente
    Data *dataNasc;        // salva a data de nascimento do paciente
    char *cartaoSus;       // salva o cartão do SUS do paciente
    char genero;           // salva o gênero do paciente
    Lesao **lesoes;        // salva as lesões do paciente
    int qtdLesoes;         // salva a quantidade de lesões do paciente
    int qtdLesoesAlocadas; // controla a quantidade de lesões alocadas
} Paciente;


Paciente *lePaciente(){
    Paciente* p = (Paciente*) malloc(sizeof(Paciente));
    p->nome = (char*) malloc(sizeof(char) * TAM_NOME);
    p->cartaoSus = (char*) malloc(sizeof(char) * TAM_SUS);
    
    scanf("%[^\n]\n", p->nome);
    p->dataNasc = leData();
    scanf("%[^\n]\n", p->cartaoSus);
    scanf("%c\n", p->genero);
}


void liberaPaciente(Paciente *p){
    if (p != NULL)
    {
        if (p->nome != NULL)
        {
            free(p->nome);
        }

        if (p->dataNasc != NULL)
        {
            liberaData(p->dataNasc);
        }
        
        if (p->cartaoSus != NULL)
        {
            free(p->cartaoSus);
        }

        if (p->lesoes != NULL)
        {
            for (int i = 0; i < p->qtdLesoesAlocadas; i++)
            {
                if (p->lesoes[i] != NULL)
                {
                    liberaLesao(p->lesoes[i]);
                }                    
            }
        }
        
    }
    
}

/*
Função que recebe um paciente e uma lesão e adiciona a lesão ao paciente no grupo de lesões que ele possui.
Se for necessário mais memória para alocar uma nova lesão, essa função deve realocar a memória necessária.
*/
void adicionaLesaoPaciente(Paciente *p, Lesao *l){
    p->lesoes[p->qtdLesoesAlocadas] = (Lesao*) realloc(p->lesoes[p->qtdLesoesAlocadas], sizeof(Lesao));
    p->qtdLesoesAlocadas++;
}


int calculaIdadePaciente(Paciente *p, Data *ref){
    return calculaDiffAnosData(p->dataNasc, ref);
}


int getQtdCirurgiasPaciente(Paciente *p){
    int qtd = 0;
    for (int i = 0; i < getQtdLesoesPaciente; i++)
    {
        if (precisaCirurgiaLesao(p->lesoes[i]))
        {
            qtd++;
        }
    }
    return qtd;
}


char *getCartaoSusPaciente(Paciente *p){
    return p->cartaoSus;
}

Data *getDataNascPaciente(Paciente *p){
    return p->dataNasc;
}


int getQtdLesoesPaciente(Paciente *p){
    return p->qtdLesoes;
}

/*
Função que imprime o nome do paciente, seguido do IDs das lesões associadas a ele.
Ela verifica se existe lesão. Se não existir, nada é impresso.
Essa impressão segue o padrão da descrição.
*/
void imprimeIdLesoesPaciente(Paciente *p){
    if ()
    {
        /* code */
    }
        
    printf("- %s",p->nome);
    
}

/*
TOTAL PACIENTES: 4
MEDIA IDADE (ANOS): 30
TOTAL LESOES: 3
TOTAL CIRURGIAS: 2
LISTA DE PACIENTES:
- TRISTANA - L8 
- LUCIAN - L2 
- LUX - L100 
*/
