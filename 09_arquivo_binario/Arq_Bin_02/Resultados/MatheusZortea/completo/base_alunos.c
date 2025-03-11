#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"base_alunos.h"
#include"aluno.h"

/**
 * @brief Estrutura para representar uma base de alunos.
 */
typedef struct BaseAlunos{
    tAluno **a;
    int qtd;
} tBaseAlunos;

/**
 * @brief Função para criar uma nova base de alunos.
 * 
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos* CriarBaseAlunos(){
    tBaseAlunos *b = (tBaseAlunos*) malloc(sizeof(tBaseAlunos));
        if(b == NULL){
            printf("erro na alocacao de memoria");
            exit (0);
        }
    b->a = (tAluno**) malloc(sizeof(tAluno*));
    return b;
}

/**
 * @brief Função para destruir uma base de alunos.
 * 
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos* baseAlunos){
    for (int i = 0; i < baseAlunos->qtd; i++){
        DestruirAluno(baseAlunos->a[i]);
    }
    free(baseAlunos->a);
    free(baseAlunos);
}



/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 * 
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo){
    FILE *arq = fopen(nomeArquivo, "rb");
    fread(&baseAlunos->qtd, sizeof(int), 1, arq);

    baseAlunos->a = (tAluno **) realloc(baseAlunos->a, baseAlunos->qtd * sizeof(tAluno *));

    for (int i = 0; i < baseAlunos->qtd; i++){
        baseAlunos->a[i] = LeAluno(arq);
    }
    fclose(arq);
}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de alunos.
 * 
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos){
    float soma = 0;
    for (int i = 0; i < baseAlunos->qtd; i++){
        soma += GetCoeficienteRendimentoAluno(baseAlunos->a[i]);
    }
    float div = baseAlunos->qtd;
    soma = soma/div;
    return soma;
}