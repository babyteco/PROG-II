#include<stdio.h>
#include<stdlib.h>


int **CriaMatriz(int linhas, int colunas){

    int **matrix = (int **) calloc( linhas, sizeof(int));

    if(matrix == NULL){
        printf("erro de alocação de memória para linhas\n");
        return NULL;
    }

    for (int i = 0; i < linhas; i++){
        matrix[i] = (int *) calloc(colunas, sizeof(int));
        
        if(matrix[i] == NULL){
            printf("erro de alocação de memória para colunas");
        }
    } 

    return matrix;
    
}

void LiberaMatriz(int **matriz, int linhas){
    for (int i = 0; i < linhas; i++){
        free(matriz[i]);
    }

    free(matriz);
}

void LeMatriz(int **matriz, int linhas, int colunas){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            scanf("%d", &matriz[i][j]);      
        }
    }    
}

void ImprimeMatrizTransposta(int **matriz, int linhas, int colunas){
    for (int i = 0; i < colunas; i++){
        for (int j = 0; j < linhas; j++){
            printf("%d ", matriz[j][i]);      
        }
        printf("\n");
    } 
}
