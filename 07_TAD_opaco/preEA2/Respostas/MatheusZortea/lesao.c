#include<stdio.h>
#include<stdlib.h>
#include"lesao.h"
#define TAM_ID 10
#define TAM_DIAG 100
#define TAM_REG 100

Lesao *leLesao(){
    Lesao *l = (Lesao*) malloc(sizeof(Lesao));;
    l->id = (char*) malloc(TAM_ID * sizeof(char));
    l->diag = (char*) malloc(TAM_DIAG * sizeof(char));
    l->regiao = (char*) malloc(TAM_REG * sizeof(char));
    scanf("%[^\n]\n", l->id);
    scanf("%[^\n]\n", l->diag);
    scanf("%[^\n]\n", l->regiao);
    scanf("%d\n",&l->malignidade);
    return l; 
}

void liberaLesao(Lesao *l){
    if(l != NULL ){
        if(l->id != NULL){
            free(l->id);
        }
        if(l->diag != NULL){
            free(l->diag);
        }
        if(l->regiao != NULL){
            free(l->regiao);
        }
        free(l);
    }
}


char *getIdLesao(Lesao *l){
    return l->id;
}

/*
Função que calcula se a lesão passada como parâmetro precisa de cirurgia de acordo com a regra
informada na descrição.
*/
int precisaCirurgiaLesao(Lesao *l){
    if (l->malignidade > 50)
    {
        return 1;
    }
    return 0;
}
