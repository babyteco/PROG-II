#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "artigo.h"
#define MAX_TAM_TITULO 150
#define MAX_TAM_JORNAL 40
#define MAX_TAM_AUTOR 100

/**
 * @brief Estrutura de um Artigo.
 */
typedef struct Artigo{
    char nome[MAX_TAM_TITULO];
    char autor[MAX_TAM_AUTOR];
    char jornal[MAX_TAM_JORNAL];
    int ano;
    int paginas;
}Artigo;

/**
 * @brief Função que cria um novo Artigo e retorna o ponteiro para ele.
 *
 * @param titulo Título do Artigo.
 * @param autor Autor do Artigo.
 * @param editora Editora do Artigo.
 * @param ano Ano de publicação do Artigo.
 * @return Ponteiro para o novo Artigo criado.
 */
Artigo *criarArtigo(char *autor, char *jornal, char *nome, int paginas, int ano){
    Artigo *a = (Artigo*) malloc(sizeof(Artigo));
    strcpy(a->autor, autor);
    strcpy(a->jornal, jornal);
    strcpy(a->nome, nome);
    a->ano = ano;
    a->paginas = paginas;
    return a;
}

/**
 * @brief Funçaõ que lê os dados de um Artigo da entrada padrão de acordo com a descrição do trabalho.
 * Dica: veja os casos de teste para entender o formato de entrada.
 *
 * @return Ponteiro para o Artigo lido.
 */
Artigo *lerArtigo(){
    char autor[MAX_TAM_AUTOR];
    char jornal[MAX_TAM_JORNAL];
    char nome[MAX_TAM_TITULO];
    int ano;
    int paginas;

    scanf("%[^\n]\n", nome);
    scanf("%[^\n]\n", autor);
    scanf("%[^\n]\n", jornal);
    scanf("%d\n", &ano);
    scanf("%d\n", &paginas);

    Artigo *a = criarArtigo(autor, jornal, nome, paginas, ano);

    return a;
}

int compararAutorArtigo(void *dado, void *chave){
    char chaverr[MAX_TAM_AUTOR];
    strcpy(chaverr, (char*) chave);
    Artigo *a = (Artigo*)dado;

    if (strcmp(a->autor, chaverr) == 0){
        return 1;
    } 
    return 0;
    
}

int compararAnoArtigo(void *dado, void *chave){
    Artigo *a = (Artigo*)dado;
    int *ano;
    ano = (int*)chave;

    if (a->ano == *ano){
        return 1;
    }
    return 0;
}

/**
 * @brief Função que desaloca a memória de um Artigo.
 *
 * @param dado Ponteiro para o Artigo a ser desalocado.
 */
void desalocarArtigo(void *dado){
    Artigo *a = (Artigo*)dado;
    free(a);
    dado = NULL;
    a = NULL;
}

/**
 * @brief Função que imprime os dados de um Artigo.
 * Dica: veja os casos de teste para entender o formato de saída e não perder tempo.
 *
 * @param dado Ponteiro para o Artigo a ser impresso.
 */
void imprimirArtigo(void *dado){
    Artigo *a = (Artigo*)dado;
    printf("- - - Artigo - - -\n");
    printf("Titulo: %s\n", a->nome);
    printf("Autor: %s\n", a->autor);
    printf("Jornal: %s\n", a->jornal);
    printf("Ano: %d\n", a->ano);
    printf("Num. Paginas: %d\n", a->paginas);
    printf("- - - - - - - - -\n");
}