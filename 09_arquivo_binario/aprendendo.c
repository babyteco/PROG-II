#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *arq;
    arq = fopen("arquivo_criado_por_mim", "w+b");
    
    int numeros[] = {10, 20, 30, 40};
    int  n = fwrite(numeros, sizeof(int), 4, arq);
    
    int dadosSalvos[3];
    int qtdLidos = fread(dadosSalvos, sizeof(int), 3, arq);

    for (int i = 0; i < 3; i++){
        printf("%d\n",dadosSalvos[i]);
    }
    
    // printf("RETORNO DA FUNCAO FWRITE: %d\n",n);
    
    fclose(arq);
    return 0;
}