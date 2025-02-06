#include<stdio.h>
#include<stdlib.h>
#include"lesao.h"


tLesao* CriaLesao(){
    tLesao *les = (tLesao*) malloc(sizeof(tLesao));
    les->diagnostico = (char*) malloc(sizeof(char) * TAM_DIAG);
    les->id = (char*) malloc(sizeof(char) * TAM_ID);
    les->regiao_corpo = (char*) malloc(sizeof(char) * TAM_REG);
    return les;
}


void LeLesao(tLesao* l){
    scanf("%[^\n]\n",l->id);
    scanf("%[^\n]\n",l->diagnostico);
    scanf("%[^\n]\n",l->regiao_corpo);
    scanf("%d\n", &l->chance_malignidade);
}

void LiberaLesao(tLesao* l){
    free(l->diagnostico);
    free(l->id);
    free(l->regiao_corpo);
    free(l);
}


char* GetIdLesao(tLesao* l){
    return l->id;
}


int PrecisaCirurgiaLesao(tLesao* l){
    if(l->chance_malignidade > 50){
        return 1;
    }
    return 0;
}
