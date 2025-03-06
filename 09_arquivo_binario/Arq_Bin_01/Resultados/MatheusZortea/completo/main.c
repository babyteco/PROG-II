#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "aluno.h"


int main(){
    int numAlunos;
    printf("Digite o numero de alunos: ");
    scanf("%d\n", &numAlunos);

    Aluno **alunos = CriaVetorAlunos(numAlunos);
    LeAlunos(alunos, numAlunos);

    char *nomeArq = "alunos.bin";
    SalvaAlunosBinario(alunos, nomeArq, numAlunos);

    Aluno **a;
    a = CriaVetorAlunos(numAlunos);
    CarregaAlunosBinario(a, "alunos.bin");
    ImprimeAlunos(a, numAlunos);
    return 0;
}