#include<stdio.h>
#include<stdlib.h>
#include "data.h"
#include "lesao.h"

#define TAM_NOME 100 /**< Tamanho máximo do nome do paciente. */
#define TAM_CSUS 19 /**< Tamanho máximo do número do cartão SUS do paciente. */
#define QTD_LESAO 10 /**< Quantidade de lesões que o paciente pode ter. */


typedef struct paciente{
    char * nome;
    tData* nascimento;
    char * cartaoSus;
    char genero;
    tLesao**  listaLesao;
    int qtdLesoes;
    int maxLesoes;
} tPaciente;


char* GetCartaoSusPaciente(tPaciente* p){
    return p->cartaoSus;
}


int GetQtdLesoesPaciente(tPaciente* p){
    return p->qtdLesoes;
}


int GetQtdCirurgiasPaciente(tPaciente* p){
    int qtd = 0;
    for (int i = 0; i < p->qtdLesoes; i++){
        if (PrecisaCirurgiaLesao(p->listaLesao[i])){
            qtd++;
        }
    }
    
}


tData* GetNascimentoPaciente(tPaciente* p){
    return p->nascimento;
}


tPaciente* CriaPaciente(){
    tPaciente *p = (tPaciente*) malloc(sizeof(tPaciente));
    return p;
}

void LePaciente(tPaciente* p){
    scanf("%[^\n]\n",p->nome);
    p->nascimento = LeData();
    scanf("%[^\n]\n",p->cartaoSus);
    scanf("%c\n",&p->genero);
}


void ImprimePaciente(tPaciente* p){
    if(p->qtdLesoes> 0){
        printf("- %s - ",p->nome);
        for (int i = 0; i < p->qtdLesoes; i++){
            printf("%s ",GetIdLesao(p->listaLesao[i]));
        }
        printf("\n");
    }
}


void LiberaPaciente(tPaciente* p){
    for (int i = 0; i < p->qtdLesoes; i++){
        free(p->listaLesao[i]);
    }
    LiberaData(p->nascimento);
    free(p->cartaoSus);
    free(p->nome);
}


/**
 * @brief Adiciona uma lesão à lista de lesões do paciente.
 * 
 * @param p Ponteiro para a estrutura de dados tPaciente contendo as informações do paciente.
 * @param l Ponteiro para a estrutura de dados tLesao contendo as informações da lesão.
*/
void AdicionaLesaoPaciente(tPaciente* p, tLesao* l){
    
}
