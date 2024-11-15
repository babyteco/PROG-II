#include<stdio.h>
#include "matrix_utils.h"

int main(){

    int rows1,cols1,rows2,cols2;
    
    scanf("%d %d",&rows1,&cols1);
    int matrix1[rows1][cols1];
    matrix_read(rows1,cols2,matrix1);

    scanf("%d %d",&rows2,&cols2);
    int matrix2[rows2][cols2];
    matrix_read(rows1,cols2,matrix2);

    int operacao;
    while(operacao != 6){

        printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida:\n");

        if(operacao == 1){
            if(possible_matrix_sum(rows1,cols1,rows2,cols2) == 1){
                int result[rows1][cols1];
                matrix_add(rows1,cols1,matrix1,rows2,cols2,matrix2,result);
                matrix_print(rows1,cols1,result);
            }
        }

        if(operacao == 2){
            if(possible_matrix_sub(rows1,cols1,rows2,cols2) == 1){
                int result[rows1][cols1];
                matrix_sub(rows1,cols1,matrix1,rows2,cols2,matrix2,result);
                matrix_print(rows1,cols1,result);
            }    
        }

        if(operacao == 3){
            if(possible_matrix_multiply(cols1,rows2) == 1){
                int result[rows1][cols2];
                matrix_multiply(rows1,cols1,matrix1,rows2,cols2,matrix2,result);
                matrix_print(rows1,cols2,result);
            }    
        }

        if(operacao == 4){
            int escalar, opcao;
            scanf("%d %d",&escalar,&opcao);
            if(opcao == 1){
                scalar_multiply(rows1,cols1,matrix1,escalar);
                matrix_print(rows1,cols1,matrix1);
            }
            else{ 
                scalar_multiply(rows2,cols2,matrix2,escalar);
                matrix_print(rows2,cols2,matrix2);
            }
        }

        //o programa deve solicitar qual matriz deve ser transposta?
        if(operacao == 5){
            transpose_matrix(rows1,cols1,matrix1,matrix1);
            matrix_print(rows1,cols1,matrix1);
            printf("\n");
            transpose_matrix(rows2,cols2,matrix2,matrix2);
            matrix_print(rows2,cols2,matrix2);
            printf("\n");
        }
    }

    printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida:\n");

    return 0;
}