#include<stdio.h>
#include<stdlib.h>
#include"aluno.h"
#include"base_alunos.h"
#include<string.h>

int main(){

    char caminho[100];
    scanf("%[^\n]\n", caminho);
    tBaseAlunos *b = CriarBaseAlunos();
    LerBaseAlunos(b, caminho);
    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f\n", GetCoeficienteRendimentoMedioBaseAlunos(b));
    DestruirBaseAlunos(b);
    return 0;
}