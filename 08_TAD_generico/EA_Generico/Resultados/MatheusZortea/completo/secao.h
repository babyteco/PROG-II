#ifndef _SECAO_H
#define _SECAO_H

typedef void (*func_ptr_desaloca_item)(void *dado);

typedef void (*func_ptr_imprime_item)(void *dado);

typedef int (*func_ptr_comparar_item)(void *dado, void *chave);

typedef struct Secao Secao;

Secao *criarSecao(func_ptr_desaloca_item desaloca);

void addItemSecao(Secao *sec, void *item);


void imprimirItensSecao(Secao *sec, func_ptr_imprime_item imprime);


void imprimirItensPorChaveSecao(Secao *sec, void *chave, func_ptr_comparar_item compara, func_ptr_imprime_item imprime);


void desalocarSecao(Secao *sec);

#endif