#include <stdio.h>
#include "matrix_utils.h"


void matrix_read(int rows, int cols, int matrix[rows][cols]){
    for(int i = 0; i < rows; i++){
        for ( int j = 0; j < cols; j++){
            scanf("%d",&matrix[i][j]);
        } 
    }
}


void matrix_print(int rows, int cols, int matrix[rows][cols]){
    for(int i = 0; i < rows; i++){
        for ( int j = 0; j < cols; j++){
            printf("%d ",matrix[i][j]);
        } 
        printf("\n");
    }
}


int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2){
    if(rows1 == rows2 && cols1 == cols2){
        return 1;
    }
    return 0;
}


int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2){
    if(rows1 == rows2 && cols1 == cols2){
        return 1;
    }
    return 0;
}


int possible_matrix_multiply(int cols1, int rows2){
    if (cols1 == rows2){
        return 1;
    }
    return 0;
}

void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]){
    for(int i = 0; i < rows1; i++){
        for ( int j = 0; j < cols1; j++){
            matrix1[i][j] = matrix1[i][j] + matrix2[i][j];
            result[i][j] = matrix1[i][j];
        } 
    }
}

void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]){
    for(int i = 0; i < rows1; i++){
        for ( int j = 0; j < cols1; j++){
            matrix1[i][j] = matrix1[i][j] - matrix2[i][j];
            result[i][j] = matrix1[i][j];
        } 
    }
}

void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]){
    
    for(int h = 0 ; h < rows1; h++){
        for(int i = 0; i < cols2; i++){
            result[h][i] = 0;
            for ( int j = 0; j < cols1; j++){
                result[h][i] += matrix1[h][j] * matrix2[j][i];
            }    
        }
    }
}


void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]){
    for(int i = 0; i < rows; i++){
        for (int j = 0; j < cols; i++){
            result[j][i] = matrix[i][j];
        }
    }
     
}


void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar){
    for(int i = 0; i < rows; i++){
        for ( int j = 0; j < cols; j++){
            matrix[i][j] = scalar * matrix[i][j];
        } 
    }
}