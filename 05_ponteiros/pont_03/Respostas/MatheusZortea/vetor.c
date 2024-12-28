#include<stdio.h>
#include"vetor.h"


void LeDadosParaVetor(int * vet, int tam){
    for(int i = 0; i < tam; i++){
        scanf("%d",&vet[i]);
    }
}


void ImprimeDadosDoVetor(int * n, int tam){
    for(int i = 0; i < tam; i++){
        printf("%d ",n[i]);
    }
    printf("\n");
}

void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar){
    
    int temp = *paraTrocar;
    int indice, flag = 0;
    for(int i = 1; i < tam; i++){
        if(vet[i] < *paraTrocar){
            *paraTrocar = vet[i];
            indice  = i;
            flag = 1;
        }
    }
    if(flag){
        vet[indice] = temp;
    }
}

//bubble sort
void OrdeneCrescente(int * vet, int tam){
    if(tam > 1){
        TrocaSeAcharMenor(vet,tam,vet);
    }
    for(int i = 0; i < tam - 1; i++){
        for (int c = 0; c < tam-i-1; c++)
        {
            if(vet[c]>vet[c+1]){
                int paliativo = vet[c];
                vet[c]=vet[c+1];
                vet[c+1]=paliativo;
            }
        }
        
    }
}
