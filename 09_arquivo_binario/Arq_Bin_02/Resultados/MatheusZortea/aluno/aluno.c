#include"aluno.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * @brief Estrutura para representar um aluno.
 */
typedef struct Aluno{
    char nome[100];
    char nascimento[11];
    char curso[50];
    float cr;
    int periodo;
} tAluno;

/**
 * @brief Função para criar um novo aluno.
 * 
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso em que o aluno está matriculado.
 * @param periodo Período do curso em que o aluno está.
 * @param coeficienteRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para o aluno recém-criado. Se houver erro na alocação de memória, o programa é encerrado.
 */
tAluno* CriarAluno(char* nome, char* dataNascimento, char* curso, int periodo, float coeficienteRendimento){
    tAluno *a = (tAluno*) malloc(sizeof(tAluno));
    strcpy(a->nome, nome);
    strcpy(a->curso, curso);
    strcpy(a->nascimento, dataNascimento);
    a->cr = coeficienteRendimento;
    a->periodo = periodo;
    return a;
}

/**
 * @brief Função para destruir um aluno.
 * 
 * @param aluno O aluno a ser destruído.
 */
void DestruirAluno(tAluno* aluno){
    free(aluno);
}

/**
 * @brief Função para ler um aluno de um arquivo binário.
 * 
 * @param arquivo_binario O arquivo binário para ler o aluno.
 * @return Um ponteiro para o aluno lido.
 */
tAluno *LeAluno(FILE *arquivo_binario){
    tAluno *a = CriarAluno("vazio", "vazio", "vazio", 0, 0);
    fread(&a->nome, sizeof(char), 100, arquivo_binario);
    fread(&a->nascimento, sizeof(char), 11, arquivo_binario);
    fread(&a->curso, sizeof(char), 50, arquivo_binario);
    fread(&a->periodo, sizeof(int), 1, arquivo_binario);
    fread(&a->cr, sizeof(float), 1, arquivo_binario);
    return a;
}

/*
Um inteiro de 4 bytes contendo o número de alunos a serem lidos. 
Para cada produto: 
* Uma string de tamanho máximo 100 contendo o nome do aluno. 
* Uma string de tamanho máximo 11 para armazenar a data de nascimento. 
* Uma string de tamanho máximo 50 com o nome do curso. 
* Um float de 4 bytes com o coeficiente de rendimento do aluno
*/

/**
 * @brief Função para obter o coeficiente de rendimento de um aluno.
 * 
 * @param aluno O aluno para obter o coeficiente de rendimento.
 * @return O coeficiente de rendimento do aluno.
 */
float GetCoeficienteRendimentoAluno(tAluno* aluno){
    return aluno->cr;
}