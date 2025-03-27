#ifndef _Artigo_H
#define _Artigo_H

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAM_TITULO 150
#define MAX_TAM_JORNAL 40
#define MAX_TAM_AUTOR 100


typedef struct Artigo Artigo;

Artigo *criarArtigo(char *autor, char *jornal, char *nome, int paginas, int ano);

Artigo *lerArtigo();

int compararAutorArtigo(void *dado, void *chave);

int compararAnoArtigo(void *dado, void *chave);

void desalocarArtigo(void *dado);


void imprimirArtigo(void *dado);

#endif