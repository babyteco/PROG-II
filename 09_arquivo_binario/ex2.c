#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){

    FILE *arq = fopen("img-1-int.bin", "rb");
    int vet[3];
    fread(vet, sizeof(int), 3, arq);
    printf("M:%d  \nN:%d\n",vet[0], vet[1]);
    int matrix[vet[0]][vet[1]];
    // fread(matrix, sizeof(int), vet[0]*vet[1], arq);
    for (int i = 0; i < vet[0]; i++) {
        if (fread(matrix[i], sizeof(int), vet[1], arq) != vet[1]) {
            printf("Erro ao ler os pixels da imagem.\n");
            fclose(arq);
            return 1;
        }
    }
    
    for (int i = 0; i < vet[0]; i++){
        for (int j = 0; j < vet[1]; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    

    fclose(arq);

    return 0;
}




/*

O arquivo disponível neste link representa uma imagem
Faça uma função que leia este arquivo e imprima na tela maior, o menor e o pixel médio
Os dados da imagem estão organizados da seguinte forma:
Dois inteiros de 4 bytes contendo o número de linhas M e de colunas N da imagem
Um inteiro de 4 bytes representando o tipo da imagem (pode desconsiderar)
M * N valores dos tipos int com 4 bytes cada representando os pixels


*/