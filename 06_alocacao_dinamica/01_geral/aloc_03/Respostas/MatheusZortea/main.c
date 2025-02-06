#include<stdio.h>
#include<stdlib.h>
#include"utils_char.h"

int main(){

    int tamanho;
    scanf("%d\n",&tamanho);
    char *strong;
    strong = CriaVetor(tamanho);
    for (int i = 0; i < tamanho; i++){
        printf("%c",strong[i]);
    }
    printf("\n");
    LeVetor(strong,tamanho);
    ImprimeString(strong, tamanho);
    LiberaVetor(strong);
    return 0;
}