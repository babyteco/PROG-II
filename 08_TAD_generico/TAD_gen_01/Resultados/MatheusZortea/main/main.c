#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

int main(){
    printf("tad_gen_01\n");
    int tipo, qtd;
    printf("Digite o tipo e numero de elementos: \n");
    scanf("%d %d\n", &tipo, &qtd);

    tGeneric *tg = CriaGenerico(tipo, qtd);
    LeGenerico(tg);
    ImprimeGenerico(tg);
    DestroiGenerico(tg);
    return 0;
}