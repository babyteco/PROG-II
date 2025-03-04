#include<stdio.h>
#include <stdlib.h>
#include"livro.h"

// Estrutura que representa um livro
typedef struct Livros{
    char *titulo;
    char *autor;
    int ano;
} tLivros;


/**
 * Cria um livro "vazio". Ponteiros devem receber null e os atributos numéricos valor -1;
 *
 * @return Um ponteiro para um livro livro "vazio"
 */
tLivros* CriaLivro(){
    tLivros *l = (tLivros*) malloc(1 * sizeof(tLivros));
    l->titulo = NULL;
    l->autor = NULL;
    l->ano = -1;
    return l;
}

/**
 * Lê os atributos de um livro a partir da entrada padrão (teclado).
 *
 * @param livro Um ponteiro para um livro que receberá os atributos lidos
 */
void LerLivro(tLivros* livro){
    livro->autor = (char*) malloc(sizeof(char)); 
}

/**
 * Imprime os atributos da TAD tLivros (título, autor e ano de publicação).
 * 
 * @param livro Um ponteiro para o livro cujos atributos serão impressos
*/
void ImprimeLivro(tLivros* livro);

/**
 * Retorna o título do livro.
 * 
 * @param livro Ponteiro para o livro cujo título será retornado.
 * @return O título do livro.
*/
char *getTitulo(tLivros* livro);

/**
 * Função para liberar toda a memória alocada por um livro
 * 
 * @param livro Um ponteiro para o livro cujos atributos serão apagados/liberados
*/
void ApagaLivro(tLivros* livro);

