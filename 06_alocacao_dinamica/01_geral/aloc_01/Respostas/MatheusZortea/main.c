#include<stdio.h>
#include<stdlib.h>

int main(){

    int qtd;
    scanf("%d",&qtd);

    int *vet = (int *) calloc(qtd, sizeof(int));

    for (int i = 0; i < qtd; i++){
        scanf("%d", &vet[i]);
    }

    float media = 0;
    for (int i = 0; i < qtd; i++){
        media += vet[i];
    }

    media = media / qtd;

    printf("%.2f\n",media);

    free(vet);

    return 0;
}