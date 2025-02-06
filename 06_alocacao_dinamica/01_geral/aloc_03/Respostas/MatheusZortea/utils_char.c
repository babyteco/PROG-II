#include<stdio.h>
#include<stdlib.h>
#include"utils_char.h"

char *CriaVetor(int tamanho){
    char *string = (char*) malloc(tamanho * sizeof(char));

    if(string == NULL){
        printf("erro na alocação de memória para a string\n");
        return NULL;
    }

    for (int i = 0; i < tamanho; i++){
        string[i] = '_';
    }

    // for (int i = 0; i < tamanho; i++){
    //     printf("%c",string[i]);
    // }
    // printf("\n");

    return string;
}


void LeVetor(char *vetor, int tamanho){
    int i = 0;
    while (scanf("%c",&vetor[i]) && vetor[i] != '\n'){
        i++;
    }
    vetor[i] = '_';
}


void ImprimeString(char *vetor, int tamanho){
    for (int i = 0; i < tamanho; i++){
        printf("%c",vetor[i]);
    }
    printf("\n");
}


void LiberaVetor(char *vetor){
    free(vetor);
}
