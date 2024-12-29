#include<stdio.h>
#include"tDepartamento.h"

int main(){

    int qtdDep;
    scanf("%d",&qtdDep);
    int total = qtdDep;
    tDepartamento d[STRING_MAX];

    while(qtdDep){
        int m1, m2, m3;
        char nomeDep[STRING_MAX], diretor[STRING_MAX], curso1[STRING_MAX], curso2[STRING_MAX], curso3[STRING_MAX];
        scanf("%s",nomeDep);
        scanf("%s",diretor);
        scanf("%s",curso1);
        scanf("%s",curso2);
        scanf("%s",curso3);
        scanf("%d %d %d", &m1, &m2, &m3);
        if(m1 >= 0 && m2 >= 0 && m3 >= 0){
            int i = total - qtdDep; 
            d[i] = CriaDepartamento(curso1, curso2, curso3, nomeDep, m1, m2, m3, diretor);
            qtdDep--;
        }else{
            printf("Digite um departamento com médias válidas\n");
        }
    }


    OrdenaDepartamentosPorMedia(d,total);
    int j = 0;
    while(total){
        ImprimeAtributosDepartamento(d[j]);
        j = j + 1;
        total--;
    }
    

    // ( char *curso1, char *curso2, char *curso3, char *nome, int m1, int m2, int m3, char *diretor )


    return 0;
}