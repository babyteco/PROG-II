#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"
#include "gerenciadorpacotes.h"

int main(){
    printf("tad_gen_02\n");
    
    tGerenciador *g = CriaGerenciador();

    while (1){
        int opcao;
        scanf("%d", &opcao);

        
        printf("\nEscolha uma opcao:\n");
        printf("	(1) Cadastrar um novo pacote\n");
        printf("	(2) Imprimir um pacote específico\n");
        printf("	(3) Imprimir todos os pacotes e sair\n");
        
        if (opcao == 1){
            printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem:");
            int tipo, numEle;
            scanf("%d %d", &tipo, &numEle);
            if (!(tipo == 0 || tipo == 1)){
                printf("\nDigite um tipo valido!");
            }
            if (tipo == 0){
                tipo = 2;
                tPacote *p = CriaPacote(tipo, numEle);
                LePacote(p);
                AdicionaPacoteNoGerenciador(g, p); 
            }
            if (tipo == 1){
                tPacote *p = CriaPacote(tipo, numEle);
                LePacote(p);
                AdicionaPacoteNoGerenciador(g, p); 
            }
            
        } else if(opcao == 2){
            int i;
            scanf("%d\n", &i);
            ImprimirPacoteNoIndice(g, i);
        } else if(opcao == 3){
            ImprimirTodosPacotes(g);
            break;
        } else {
            printf("Escolha uma opcao valida para o menu!\n");
        }
    }
    
    DestroiGerenciador(g);

    return 0;
}