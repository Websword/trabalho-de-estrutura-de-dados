#include <stdio.h>
#include <stdlib.h>
#include "pilha_encadeada.h"




pilha criacao_da_pilha_vazia()
{
    pilha Pilha;
    Pilha.tam = -1;
    Pilha.top = NULL;

    return(Pilha);
}

int Indicar_se_a_pilha_esta_vazia(pilha Pilha)
{
    if (Pilha.tam == -1){
        return(1);
        }
    else{
        return(0);
        }
}


pilha  Inserir_no_topo_da_pilha(pilha Pilha, int num)
{
    no *novo;

        novo = malloc(sizeof(no));
        novo->valor = num;
        novo->proximo = Pilha.top;

    Pilha.top = novo;
    Pilha.tam++;

    return(Pilha);
}

pilha  Remover_do_topo_da_pilha(pilha Pilha)
{
    if((Indicar_se_a_pilha_esta_vazia(Pilha) == 1)){
        return(Pilha);
    }
    
    no *aux;
    aux = Pilha.top;
    Pilha.top = aux->proximo;
    Pilha.tam--;

    printf("%d\n", aux->valor);
    free(aux);
    return(Pilha);
}
int  Ler_o_topo_da_pilha(pilha Pilha)
{
    no *aux;
    aux = Pilha.top;
    return("%d\n", aux->valor);
}

int  Retornar_o_tamanho_da_pilha(pilha Pilha)
{
    return(Pilha.tam+1);
}