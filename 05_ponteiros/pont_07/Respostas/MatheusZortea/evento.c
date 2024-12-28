#include<stdio.h>
#include"evento.h"

#define MAX_EVENTOS 10


void cadastrarEvento(Evento* eventos, int* numEventos){
    scanf("%s",&eventos[*numEventos].nome);
    scanf("%d %d %d",&eventos[*numEventos].dia,&eventos[*numEventos].mes,&eventos[*numEventos].ano);
    (*numEventos)++;
    printf("Evento cadastrado com sucesso!\n");
}

void exibirEventos(Evento* eventos, int* numEventos){
    printf("Eventos cadastrados:\n");
    for(int i = 0; i < *numEventos; i++){
        printf("%d - %s - %d/%d/%d\n",i,eventos[i].nome,eventos[i].dia,eventos[i].mes,eventos[i].ano);
    }
}

void trocarDataEvento(Evento* eventos, int* numEventos){
    int i;
    scanf("%d",&i);
    scanf("%d %d %d",&eventos[i].dia,&eventos[i].mes,&eventos[i].ano);
    printf("Data modificada com sucesso!\n");
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){
    if(*indiceA < *numEventos && *indiceB < *numEventos){
        printf("Eventos trocados com sucesso!\n");
        int dia,mes,ano;
        dia = eventos[*indiceA].dia;
        mes = eventos[*indiceA].mes;
        ano = eventos[*indiceA].ano;
        eventos[*indiceA].dia = eventos[*indiceB].dia;
        eventos[*indiceA].mes = eventos[*indiceB].mes;
        eventos[*indiceA].ano = eventos[*indiceB].ano;
        eventos[*indiceB].dia = dia;
        eventos[*indiceB].mes = mes;
        eventos[*indiceB].ano = ano;
    } else{
        printf("Indices invalidos!\n");
    }
}

