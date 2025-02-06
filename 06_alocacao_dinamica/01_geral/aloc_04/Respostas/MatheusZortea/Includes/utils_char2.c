#include<stdio.h>
#include<stdlib.h>
#include"utils_char2.h"
#define TAM_PADRAO 10


char *CriaVetorTamPadrao(){
    char *vetor = (char*) malloc(TAM_PADRAO * sizeof(char));
    
    if (vetor == NULL){
        printf("Erro na alocação de memoria do vetor\n");
        exit(1);
    }
    
    for (int i = 0; i < TAM_PADRAO; i++){
        vetor[i] = '_';
    }
    
    vetor[TAM_PADRAO] = '\0';

    return vetor;
}

char *AumentaTamanhoVetor(char* vetor, int tamanhoantigo){

    int novoTamanho = (tamanhoantigo * sizeof(char)) + (TAM_PADRAO * sizeof(char));
    vetor = (char*) realloc(vetor, novoTamanho);

    if (vetor == NULL){
        printf("Erro na realocação de memoria do vetor\n");
        exit(1);
    }

    for (int i = tamanhoantigo; i < novoTamanho/sizeof(char); i++){
        vetor[i] = '_';
    }

    vetor[novoTamanho] = '\0';
    
    return vetor;
}

char* LeVetor(char *vetor, int *tamanho){
    int i = 0;
    while (scanf("%c",&vetor[i]) && vetor[i] != '\n'){
        i++;
        if (i > *tamanho){
            vetor = AumentaTamanhoVetor(vetor, *tamanho);
            *tamanho = *tamanho + TAM_PADRAO;
        }   
    }
    vetor[i] = '_';

    return vetor;
}


void ImprimeString(char *vetor){
    printf("%s\n",vetor);
}


void LiberaVetor(char *vetor){
    free(vetor);
}
