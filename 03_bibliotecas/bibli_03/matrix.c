#include <stdio.h>
#include "matrix_utils.h"

int main(){
    
    int i1, j1, i2, j2;
    scanf("%d %d",&i1, &j1);
    int matrix1[i1][j1];
    matrix_read(i1,j1,matrix1);

    scanf("%d %d",&i2, &j2);
    int matrix2[i2][j2];
    matrix_read(i2,j2,matrix2);

    return 0;
}