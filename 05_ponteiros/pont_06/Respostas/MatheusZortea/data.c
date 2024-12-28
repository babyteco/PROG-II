#include<stdio.h>
#include"data.h"

void InicializaDataParam( int dia, int mes, int ano, tData *data){
    //(*data).dia == data->dia
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
}

void LeData( tData *data ){
    scanf("%d %d %d",&data->dia,&data->mes,&data->ano);
}

void ImprimeData( tData *data ){
    printf("'%02d/%02d/%02d'",data->dia,data->mes,data->ano);
}

int EhBissexto( tData *data ){
    if(data->ano % 4){
        return 0;
    } else {
        return 1;
    }
}

int InformaQtdDiasNoMes( tData *data ){
    if(data->mes == 1){
        return 31;
    }
    if(data->mes == 2){
        if(EhBissexto(data)){
            return 29;
        } else{
            return 28;
        }
    }
    if(data->mes == 3){
        return 31;
    }
    if(data->mes == 4){
        return 30;
    }
    if(data->mes == 5){
        return 31;
    }
    if(data->mes == 6){
        return 30;
    }
    if(data->mes == 7){
        return 31;
    }
    if(data->mes == 8){
        return 31;
    }
    if(data->mes == 9){
        return 30;
    }
    if(data->mes == 10){
        return 31;
    }
    if(data->mes == 11){
        return 30;
    }
    if(data->mes == 12){
        return 31;
    }
}

void AvancaParaDiaSeguinte( tData *data ){
    if(data->dia == InformaQtdDiasNoMes(data)){
        if(data->mes == 12){
            data->ano++;
            data->mes = 1;
            data->dia = 1;
        } else{
            data->mes++;
            data->dia = 1;
        }
    } else{
        data->dia ++;
    }
}

int EhIgual( tData *data1, tData *data2 ){
    if((data1->dia == data2->dia) && (data1->mes == data2->mes) && (data1->ano == data2->ano)){
        return 1;
    }
    return 0;
}
