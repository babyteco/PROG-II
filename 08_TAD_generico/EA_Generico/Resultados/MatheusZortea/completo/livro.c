#ifndef _LIVRO_H
#define _LIVRO_H

#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include "livro.h"

#define MAX_TAM_TITULO 150
#define MAX_TAM_EDITORA 40
#define MAX_TAM_AUTOR 100

/**
 * @brief Estrutura de um livro.
 */
typedef struct Livro{
    char nome[MAX_TAM_TITULO];
    char autor[MAX_TAM_AUTOR];
    char editora[MAX_TAM_EDITORA];
    int ano;
} Livro;

/**
 * @brief Função que cria um novo livro e retorna o ponteiro para ele.
 *
 * @param titulo Título do livro.
 * @param autor Autor do livro.
 * @param editora Editora do livro.
 * @param ano Ano de publicação do livro.
 * @return Ponteiro para o novo livro criado.
 */
Livro *criarLivro(char *titulo, char *autor, char *editora, int ano){
    Livro *l = (Livro*) malloc(sizeof(Livro));
    l->ano = ano;
    strcpy(l->autor, autor);
    strcpy(l->editora, editora);
    strcpy(l->nome, titulo);

    return l;
}

/**
 * @brief Funçaõ que lê os dados de um livro da entrada padrão de acordo com a descrição do trabalho.
 * Dica: veja os casos de teste para entender o formato de entrada.
 *
 * @return Ponteiro para o livro lido.
 */
Livro *lerLivro(){
    char nome[MAX_TAM_TITULO];
    char autor[MAX_TAM_AUTOR];
    char editora[MAX_TAM_EDITORA];
    int ano;

    scanf("%[^\n]\n", nome);
    scanf("%[^\n]\n", autor);
    scanf("%[^\n]\n", editora);
    scanf("%d\n", &ano);

    Livro *l = criarLivro(nome, autor, editora, ano);
    return l;
}

/*
L (caractere que indica o cadastro de um Livro) 
O ULTIMO REINO (título do livro) 
BERNARD CORNWELL (nome do autor) 
NOVO TEMPO (nome da editora) 
2004 (ano de publicação)
*/

/**
 * @brief Função que compara o autor de um livro com uma chave. Essa chave é recebida como um ponteiro void.
 * Faça a manipulação necessária para comparar o autor do livro com a chave.
 *
 * @param dado Ponteiro para o livro.
 * @param chave Ponteiro para a chave de comparação.
 * @return 1 se o autor do livro corresponde à chave, 0 caso contrário.
 */
int compararAutorLivro(void *dado, void *chave){
    char chaverr[MAX_TAM_AUTOR];
    strcpy(chaverr, (char*) chave);
    Livro *l = (Livro*)dado;

    if (strcmp(l->autor, chaverr) == 0){
        return 1;
    } 
    return 0;
    
}

/**
 * @brief Função que compara o ano de um livro com uma chave. Essa chave é recebida como um ponteiro void.
 * Faça a manipulação necessária para comparar o ano do livro com a chave.
 *
 * @param dado Ponteiro para o livro.
 * @param chave Ponteiro para a chave de comparação.
 * @return 1 se o ano do livro corresponde à chave, 0 caso contrário.
 */
int compararAnoLivro(void *dado, void *chave){
    Livro *l = (Livro*)dado;
    int *ano;
    ano = (int*)chave;

    if (l->ano == *ano){
        return 1;
    }
    return 0;
}

/**
 * @brief Função que desaloca a memória de um livro.
 *
 * @param dado Ponteiro para o livro a ser desalocado.
 */
void desalocarLivro(void *dado){
    Livro *l = (Livro*)dado;
    free(l);
    dado = NULL;
    l = NULL;
}

/**
 * @brief Função que imprime os dados de um livro.
 * Dica: veja os casos de teste para entender o formato de saída e não perder tempo.
 *
 * @param dado Ponteiro para o livro a ser impresso.
 */
void imprimirLivro(void *dado){
    Livro *l = (Livro*)dado;
    printf("- - - Livro - - -\n");
    printf("Titulo: %s\n", l->nome);
    printf("Autor: %s\n", l->autor);
    printf("Editora: %s\n", l->editora);
    printf("Ano: %d\n", l->ano);
    printf("- - - - - - - - -\n");
}

/*
- - - Livro - - -
Titulo: A SOMBRA DO PASSADO
Autor: CARLOS MENDES
Editora: EDITORA LUZ
Ano: 2015
- - - - - - - - -
*/

#endif