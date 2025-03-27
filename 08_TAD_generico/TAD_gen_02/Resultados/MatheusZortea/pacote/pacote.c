#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"

typedef struct pacote{
    void *dado;
    Type tipo;
    int qtd;
    int soma;
} tPacote;



/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote* CriaPacote(Type type, int numElem){
    tPacote *pac = malloc(sizeof(tPacote));

    pac->tipo = type;
    pac->qtd = numElem;
    pac->soma = 0;

    switch (type)
    {
    case INT:
        pac->dado = malloc(sizeof(int) * pac->qtd);
        break;
    case CHAR:
        pac->dado = malloc(sizeof(char) * (pac->qtd+1));
        break;
    default:
        break;
    }

    return pac;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote* pac){
    free(pac->dado);
    free(pac);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote* pac){
    scanf("%*c");
    // char buffer[100];
    // scanf("%[^\n]s", buffer);
    // scanf("%*c");
    // printf("Buffer: %s\n", buffer);
    
    printf("\nDigite o conteúdo do vetor/mensagem:");
    int i;
    char c;
    switch (pac->tipo)
    {
        case INT:
        for (i = 0; i < pac->qtd; i++)
        {
            scanf("%d", &((int *)pac->dado)[i]);
        }
        //scanf("%*c");
        break;
        case CHAR:
        for (i = 0; i < pac->qtd; i++)
        {
            scanf("%c", &c);
            if (c == '\n')
            {
                break;
            }
            else 
            {
                ((char *)pac->dado)[i] = c;
            }
            //printf("caracter %d: %c\n", i, ((char *)pac->dado)[i]);
        }
        ((char *)pac->dado)[i] = '\0';
        //scanf("%*c");
        // if (((char *)pac->dado)[pac->qtd] == '\n')
        // {
            //     ((char *)pac->dado)[pac->qtd] = '\0';
            // }
            break;
            default:
            break;
        }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac){
    CalculaSomaVerificacaoPacote(pac);
    printf("%d ", pac->soma);
    switch (pac->tipo)
    {
    case INT:
    for (int i = 0; i < pac->qtd; i++)
    {
        printf("%d ", ((int *)pac->dado)[i]);
        }
        break;
        case CHAR:
        printf("%s", (char*)pac->dado);
        break;
        default:
        break;
    }

    printf("\n");
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac){
    for (int i = 0; i < pac->qtd; i++)
    {
        switch (pac->tipo)
        {
        case INT:
            pac->soma += ((int*)pac->dado)[i];
            break;
        case CHAR:
            pac->soma += ((char*)pac->dado)[i];
        default:
            break;
        }
    }  
}

