#include<stdio.h>
#include"utils.h"


void LeIntervalo(int * m, int * n){
    scanf("%d %d",m,n);
}

int EhPrimo(int n){
    int cont = 0;
    for(int i = n;i >= 1; i--){
        if(n % i == 0){
            cont++;
        }
    }
    if(cont <= 2){
        return 1;
    } else{
        return 0;
    }
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior){
    int flag = 1;
    for(int i = m; i <= n; i++){
        if(EhPrimo(i)){
            if(flag){
                flag = 0;
                *menor = i;
            }
            *maior = i;
        }
    }
}
