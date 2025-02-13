#include<stdio.h>
#include<stdlib.h>
#include"data.h"



Data *leData(){
    Data* d = (Data*) malloc(sizeof(Data));
    scanf("%d/%d/%d\n",&d->dia,&d->mes,&d->ano);
    return d;
}


Data *criaData(int dia, int mes, int ano){
    Data* d = (Data*) malloc(sizeof(Data));
    d->ano = ano;
    d->mes = mes;
    d->dia = dia;
    return d;
}


void liberaData(Data *d){
    if (d != NULL){
        free(d);
    }
}


int calculaDiffAnosData(Data *d, Data *atual){
    int dif = atual->ano - d->ano;
    if(atual->mes < d->mes){
        dif--;
    } else if(atual->mes == d->mes){
        if(atual->dia < d->dia){
            dif--;
        }
    }
    return dif;
}


void imprimeData(Data *d){
    printf("%d/%d/%d\n",d->dia,d->mes,d->ano);
}
