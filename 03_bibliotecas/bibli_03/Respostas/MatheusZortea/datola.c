#include <stdio.h>
#include "data.h"

//so falta acertar o numero de dias no caso 6

int main(){

    int dia1, mes1, ano1, dia2, mes2, ano2;

    scanf("%d/%d/%d\n%d/%d/%d",&dia1,&mes1,&ano1,&dia2,&mes2,&ano2);

    if(verificaDataValida(dia1,mes1,ano1) == 0 || verificaDataValida(dia2,mes2,ano2) == 0){
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return 0;
    }

    printf("Primeira data: ");
    imprimeDataExtenso(dia1,mes1,ano1);

    printf("Segunda data: ");
    imprimeDataExtenso(dia2,mes2,ano2);


    if(comparaData(dia1,mes1,ano1,dia2,mes2,ano2) == -1){
        printf("A primeira data eh mais antiga\n");
    }
    if(comparaData(dia1,mes1,ano1,dia2,mes2,ano2) == 1){
        printf("A segunda data eh mais antiga\n");
    }
    if(comparaData(dia1,mes1,ano1,dia2,mes2,ano2) == 0){
        printf("As datas sao iguais\n");
    }

    printf("A diferenca em dias entre as datas eh: %02d dias",calculaDiferencaDias(dia1,mes1,ano1,dia2,mes2,ano2));

    return 0;
}