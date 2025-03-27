#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"
#include "artigo.h"
#include "secao.h"

int main(){

    char op;
    Secao *livros = criarSecao(desalocarLivro);
    Secao *artigos = criarSecao(desalocarArtigo);

    while (1){
        scanf(" %c", &op);

        if (op == 'F'){
            break;
        }
        
        
        if (op == 'A'){
            printf("LEU A\n");
            Artigo *a = lerArtigo();
            addItemSecao(artigos, a);
        }
        
        if (op == 'L'){
            printf("LEU L\n");

            Livro *l = lerLivro();
            addItemSecao(livros, l);
        }

        
        if (op == 'E'){
            printf("MEU PAUUUUUUUUUUUUUUUUU\n");

            char operacao[100];
            fgets(operacao, 100, stdin);

            printf("LEU A OPCAO DE E, E O STING CMP DEU %d\n", strcmp(operacao, "LISTAR LIVROS"));


            if (strcmp(operacao, "LISTAR  ACERVO") == 0){
                printf("- - - LISTA DE TODOS OS ITENS DA BIBLIOTECA - - -\n");
                imprimirItensSecao(livros, imprimirLivro);
                imprimirItensSecao(artigos, imprimirArtigo);
            }
            
            if (strcmp(operacao, "LISTAR LIVROS") == 0){
                printf("- - - LISTA DE TODOS OS LIVROS DA BIBLIOTECA - - -\n");
                imprimirItensSecao(livros, imprimirLivro);
            }

            if (strcmp(operacao, "LISTAR ARTIGOS") == 0){
                printf("- - - LISTA DE TODOS OS ARTIGOS DA BIBLIOTECA - - -\n");
                imprimirItensSecao(artigos, imprimirArtigo);
            }

            if (strcmp(operacao, "LISTAR AUTOR") == 0){
                char autor[100];
                scanf("%[^\n]\n", autor);
                printf("- - - LISTA DE TODOS OS ITENS DE UM AUTOR - - -\n");
                printf("Nome do autor: %s\n", autor);
                imprimirItensPorChaveSecao(livros, autor, compararAutorLivro, imprimirLivro);
                imprimirItensPorChaveSecao(artigos, autor, compararAutorArtigo, imprimirArtigo);
            }

            if (strcmp(operacao, "LISTAR  ANO") == 0){
                int ano;
                scanf("%d", &ano);
                printf("- - - LISTA DE TODOS OS ITENS DE UM ANO - - -\n");
                printf("- Ano: %d\n", ano);
                imprimirItensPorChaveSecao(livros, &ano, compararAnoLivro, imprimirLivro);
                imprimirItensPorChaveSecao(artigos, &ano, compararAnoArtigo, imprimirArtigo);
            }
        }    
    }

    desalocarSecao(livros);
    desalocarSecao(artigos);

    return 0;
}