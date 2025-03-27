#ifndef _tadgen
#define _tadgen

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    FLOAT = 0,
    INT = 1
} Type;

typedef struct generic{
    void *vetor;
    Type tipo;
    int qtd;
} tGeneric;

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem){
    tGeneric *tg = (tGeneric*) malloc(sizeof(tGeneric));
    tg->tipo = type;
    tg->qtd = numElem;

    if (tg->tipo == 0){
        tg->vetor = malloc(tg->qtd * sizeof(float));
    } else {
        tg->vetor = malloc(tg->qtd * sizeof(int));
    }
    return tg;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen){
    free(gen->vetor);
    free(gen);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen){
    printf("\nDigite o vetor:\n");
    if (gen->tipo == 0){
        float temp[gen->qtd];
        for (int i = 0; i < gen->qtd; i++){
            scanf("%f", &temp[i]);
            ((float*)gen->vetor)[i] = temp[i];
        }
    } else {
        int temp[gen->qtd];
        for (int i = 0; i < gen->qtd; i++){
            scanf("%d", &temp[i]);
            ((int*)gen->vetor)[i] = temp[i];
        }
    }
    
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen){
    if(gen->tipo == 0) {
        for (int i = 0; i < gen->qtd; i++){
            printf("%.2f ", ((float*)gen->vetor)[i]);
        }
    } else {
        for (int i = 0; i < gen->qtd; i++){
            printf("%d ", ((int*)gen->vetor)[i]);
        }
    }
    printf("\n");
}

#endif
