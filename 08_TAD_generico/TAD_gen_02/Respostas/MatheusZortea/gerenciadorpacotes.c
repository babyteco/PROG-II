#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"
#include "gerenciadorpacotes.h"

typedef struct gerenciadorpacotes{
    tPacote **listaPacotes;
    int qtdPacotes;
    int capacidade;
} tGerenciador;

/**
 * @brief Cria uma TAD que gerencia pacotes. O pacote é um TAD genérico.
 *
 *
 * @return O gerenciador de pacotes
 */
tGerenciador* CriaGerenciador(){
    tGerenciador *g = (tGerenciador*) malloc(sizeof(tGerenciador));
    g->listaPacotes = (tPacote**) malloc(2 * sizeof(tPacote*));
    g->capacidade = 2;
    g->qtdPacotes = 0;
    return g;
}

/**
 * @brief Adiciona um pacote ao gerenciador de pacotes.
 *
 * @param geren O gerenciador de pacotes que armazenará o pacote 
 * @param pac O pacote que queremos adicionar no gerenciador.
 *
 */
void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac){
    if (geren->capacidade == geren->qtdPacotes){
        geren->capacidade += 2;
        geren->listaPacotes = (tPacote**) realloc(geren->listaPacotes, geren->capacidade * sizeof(tPacote*));
    }

    geren->listaPacotes[geren->qtdPacotes] = pac;
    
    geren->qtdPacotes++;
}


/**
 * @brief Destrói um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que será destruído (memória liberada)
 *
 */
void DestroiGerenciador(tGerenciador* geren){
    for (int i = 0; i < geren->qtdPacotes; i++){
        DestroiPacote(geren->listaPacotes[i]);
    }
    free(geren->listaPacotes);
    free(geren);
}

/**
 * @brief Imprime um pacote específico do gerenciador de pacotes.
 *
 * @param geren - O gerenciador de pacotes que terá um pacote impresso
 * @param idx - O índice do pacote a ser impresso (começa em zero!)
 *
 */
void ImprimirPacoteNoIndice(tGerenciador* geren, int idx){
    ImprimePacote(geren->listaPacotes[idx]);
}


/**
 * @brief Imprime todos os pacotes de um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que terá seus pacotes impressos
 *
 */
void ImprimirTodosPacotes(tGerenciador* geren){
    for (int i = 0; i < geren->qtdPacotes; i++){
        ImprimirPacoteNoIndice(geren, i);
    }
}
