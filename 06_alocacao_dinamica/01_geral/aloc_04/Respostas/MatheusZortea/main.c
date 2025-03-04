#include<stdio.h>
#include<stdlib.h>
#include"utils_char2.h"

int main(){
    char* vetor;
    vetor = CriaVetorTamPadrao();
    int tam = TAM_PADRAO + 1;
    vetor = LeVetor(vetor, &tam);
    ImprimeString(vetor);
    LiberaVetor(vetor);
    return 0;
}