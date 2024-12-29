#include<stdio.h>
#include<string.h>
#include"tDepartamento.h"

tDepartamento CriaDepartamento( char *curso1, char *curso2, char *curso3, char *nome, int m1, int m2, int m3, char *diretor ){
    tDepartamento d;
    strcpy(d.curso1,curso1);
    strcpy(d.curso2,curso2);
    strcpy(d.curso3,curso3);
    strcpy(d.nome,nome);
    strcpy(d.diretor,diretor);
    d.m1 = m1;
    d.m2 = m2;
    d.m3 = m3;
    return d;
}

void ImprimeAtributosDepartamento(tDepartamento depto){
    float media = (depto.m1 + depto.m2 + depto.m3)/3.0;
    printf("Departamento: %s\n    Diretor: %s\n",depto.nome,depto.diretor);
    printf("    1o curso: %s\n    Media do 1o curso: %d\n    2o curso: %s\n    Media do 2o curso: %d\n    3o curso: %s\n    Media do 3o curso: %d\n    Media dos cursos: %.2f\n",depto.curso1,depto.m1,depto.curso2,depto.m2,depto.curso3,depto.m3,media);
}

float media(tDepartamento depto){
    float a = (depto.m1 + depto.m2 + depto.m3)/3.0;
    return a;
}

void TrocaOrdem(tDepartamento *d1, tDepartamento *d2){
    char temp[STRING_MAX];
    strcpy(temp ,d1->curso1);
    strcpy(d1->curso1, d2->curso1);
    strcpy(d2->curso1, temp);

    strcpy(temp ,d1->curso2);
    strcpy(d1->curso2, d2->curso2);
    strcpy(d2->curso2, temp);

    strcpy(temp ,d1->curso3);
    strcpy(d1->curso3, d2->curso3);
    strcpy(d2->curso3, temp);

    strcpy(temp ,d1->diretor);
    strcpy(d1->diretor, d2->diretor);
    strcpy(d2->diretor, temp);

    strcpy(temp ,d1->nome);
    strcpy(d1->nome, d2->nome);
    strcpy(d2->nome, temp);
    
    int tempo;
    tempo = d1->m1;
    d1->m1 = d2->m1;
    d2->m1 = tempo;

    tempo = d1->m2;
    d1->m2 = d2->m2;
    d2->m2 = tempo;

    tempo = d1->m3;
    d1->m3 = d2->m3;
    d2->m3 = tempo;
}

void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos){
    for(int j = 0; j < num_deptos - 1; j++){
        for(int i = 0; i < num_deptos - 1 - j; i++){
            if(media(vetor_deptos[i]) < media(vetor_deptos[i+1])){
                TrocaOrdem(&vetor_deptos[i], &vetor_deptos[i+1]);
            }
        }
    }
}
