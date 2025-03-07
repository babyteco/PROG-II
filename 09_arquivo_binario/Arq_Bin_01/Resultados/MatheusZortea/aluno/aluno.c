#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"aluno.h"

typedef struct aluno{
    char nome[100];
    char nascimento[100];
    char curso[100];
    char periodo[100];
    int inteiro;
    float cr;
} Aluno;

Aluno** CriaVetorAlunos(int numeroAlunos){
    Aluno **a = (Aluno**)malloc(numeroAlunos * sizeof(Aluno*));
    return a;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA){
    Aluno *a = (Aluno*)malloc(sizeof(Aluno));
    a->cr = CRA;
    a->inteiro = percConclusao;
    strcpy(a->periodo, periodoIngresso);
    strcpy(a->curso, cursoUfes);
    strcpy(a->nascimento, dtNasc);
    strcpy(a->nome, nome);
    return a;
}


void LeAlunos(Aluno** vetorAlunos, int numeroAlunos){    
    for (int i = 0; i < numeroAlunos; i++){
        char nome[100], dtNasc[100], curso[100], ingresso[100];
        int conclusao;
        float cr;
        scanf("%[^\n]\n", nome);
        scanf("%[^\n]\n", dtNasc);
        scanf("%[^\n]\n",curso);
        scanf("%[^\n]\n",ingresso);
        scanf("%d\n", &conclusao);
        scanf("%f\n",&cr);
        vetorAlunos[i] = CriaAluno(nome, dtNasc, curso, ingresso, conclusao, cr);
    }
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos){
    for (int i = 0; i < numeroAlunos; i++){
        free(alunos[i]);
    }
    free(alunos);
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos){
    int bytesSalvos = 0;
    FILE *arq = fopen(fileName, "wb");
    for (int i = 0; i < numeroAlunos; i++){
        fwrite(alunos[i], sizeof(Aluno), 1, arq);
        bytesSalvos +=  (strlen(alunos[i]->nome) + 1) * sizeof(char);
        bytesSalvos += (strlen(alunos[i]->nascimento) + 1)  * sizeof(char); 
        bytesSalvos += (strlen(alunos[i]->curso) + 1)  * sizeof(char);
        bytesSalvos += sizeof(int);
        bytesSalvos += sizeof(float);
    }
    fclose(arq);
    printf("Numero de bytes salvos: %d\n", bytesSalvos);
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName){
    FILE *arq = fopen(fileName, "rb");
    for (int i = 0; i < 2; i++){
        fread(alunos[i], sizeof(Aluno), 1, arq);
    }
    fclose(arq);
}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos){
    for (int i = 0; i < numeroAlunos; i++){
        printf("Aluno %d\n", i);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Data Nascimento: %s\n", alunos[i]->nascimento);
        printf("Curso: %s\n", alunos[i]->curso);
        printf("Periodo Ingresso: %s\n", alunos[i]->periodo);
        printf("%% Conclusao do Curso: %d\n", alunos[i]->inteiro);
        printf("CRA: %f\n", alunos[i]->cr);
    }
}
