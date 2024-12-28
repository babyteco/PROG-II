#include <stdio.h>
# include "data.h"


int verificaDataValida(int dia, int mes, int ano){
    
    if(ano < 0){
        return 0;
    }
    
    switch (mes)
    {
    case 1:
        if(dia <= numeroDiasMes(1,ano) && dia >= 1){
            return 1;
        }
        break;
    
    case 2:
        if(dia <= numeroDiasMes(2,mes) && dia >= 1){
            return 1;
        }
        break;
    
    case 3:
        if(dia <= numeroDiasMes(3,ano) && dia >= 1){
            return 1;
        }
        break;

    case 4:
        if(dia <= numeroDiasMes(4,ano) && dia >= 1){
            return 1;
        }
        break;
    
    case 5:
        if(dia <= numeroDiasMes(5,ano) && dia >= 1){
            return 1;
        }
        break;
    
    case 6:
        if(dia <= numeroDiasMes(6,ano) && dia >= 1){
            return 1;
        }
        break;
    
    case 7:
        if(dia <= numeroDiasMes(7,ano) && dia >= 1){
            return 1;
        }
        break;

    case 8:
        if(dia <= numeroDiasMes(8,ano) && dia >= 1){
            return 1;
        }
        break;

    case 9:
        if(dia <= numeroDiasMes(9,ano) && dia >= 1){
            return 1;
        }
        break;

    case 10:
        if(dia <= numeroDiasMes(10,ano) && dia >= 1){
            return 1;
        }
        break;

    case 11:
        if(dia <= numeroDiasMes(11,ano) && dia >= 1){
            return 1;
        }
        break;
    case 12:
        if(dia <= numeroDiasMes(12,ano) && dia >= 1){
            return 1;
        }
        break;

    default:
        break;
    }

    return 0;
}

void imprimeMesExtenso(int mes){
    switch (mes)
    {
    case 1:
        printf("Janeiro");
        break;
    
    case 2:
        printf("Fevereiro");
        break;
    
    case 3:
        printf("Marco");
        break;
    
    case 4:
        printf("Abril");
        break;
    
    case 5:
        printf("Maio");
        break;

    case 6:
        printf("Junho");
        break;

    case 7:
        printf("Julho");
        break;

    case 8:
        printf("Agosto");
        break;
    
    case 9:
        printf("Setembro");
        break;

    case 10:
        printf("Outubro");
        break;

    case 11:
        printf("Novembro");
        break;

    case 12:
        printf("Dezembro");
        break;

    default:
        break;
    }
}

void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%d de ",dia);
    imprimeMesExtenso(mes);
    printf(" de %d\n",ano);
}

int verificaBissexto(int ano){
    if(ano % 4 == 0){
        return 1;
    }
    return 0;
}

int numeroDiasMes(int mes, int ano){
    switch (mes)
    {
    case 1:
        return 31;
        break;
    case 2:
        if(verificaBissexto(mes) == 1){
            return 29;
        } else return 28;
        break;
    case 3:
        return 31;
        break;
    case 4:
        return 30;
        break;
    case 5:
        return 31;
        break;
    case 6:
        return 30;
        break;
    case 7:
        return 31;
        break;
    case 8:
        return 31;
        break;
    case 9:
        return 30;
        break;
    case 10:
        return 31;
        break;
    case 11:
        return 30;
        break;
    case 12:
        return 31;
        break;    

    default:
        break;
    }
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    if(dia1 == dia2 && mes1 == mes2 && ano1 == ano2){
        return 0;
    }
    if(ano1 > ano2){
        return 1;
    } else if(ano2 > ano1){
        return -1;
    }

    if(ano1 == ano2){
        if(mes1 > mes2){
            return 1;
        } else if(mes2 > mes1){
            return -1;
        }

        if(mes1 == mes2){
            if(dia1 > dia2){
                return 1;
            }else {
                return -1;
            }
        }
    }

}

int calculaDiasAteMes(int mes, int ano){
    int dias = 0;
    for(int i = 1; i <= mes; i++){
        dias += numeroDiasMes(i,ano);
    }
    return dias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    
    int status = comparaData(dia1,mes1,ano1,dia2,mes2,ano2);
    if(status == 0){
        return 0;
    }

    int dias = 0;

    if(status == 1){

        //conta todos os dias de 1 de janeiro do ano2 ate 1 de janeiro do ano1
        for(int i = ano2; ano1 - i != 0; i++){
            dias += calculaDiasAteMes(12,i);
        }

        //tira os dias contados que passaram até a data 2
        dias = dias - calculaDiasAteMes(mes2 - 1,ano2) - dia2;

        //adiciona os dias de 1 de janeiro do ano1 ate a data 1
        dias += calculaDiasAteMes(mes1 - 1, ano1) + dia1;

        return dias;
    }
    
    if(status == -1){

        //conta todos os dias de 1 de janeiro do ano1 ate 1 de janeiro do ano2
        for(int i = ano1; ano2 - i != 0; i++){
            dias += calculaDiasAteMes(12,i);
        }

        //tira os dias contados que passaram de janeiro até a data 1
        dias =  dias - calculaDiasAteMes(mes1 - 1,ano1) - dia1;

        //adiciona os dias de 1 de janeiro do ano1 ate a data 1
        dias += calculaDiasAteMes(mes2 - 1, ano2) + dia2;

        return dias;
    }
}