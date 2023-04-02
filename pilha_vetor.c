#include <stdio.h>
#include "pilha_vetor.h"
#define MAX 100


pilha criacao_da_pilha_vazia()
{
    int arr[MAX];

    pilha Pilha;
    Pilha.dados = arr;
    Pilha.topo = -1;

    return(Pilha);
}

int Indicar_se_a_pilha_esta_vazia(pilha Pilha)
{
    if (Pilha.topo == -1){
        return(1);
        }
    else{
        return(0);
        }
}

int Indicar_se_a_pilha_esta_cheia(pilha Pilha)
{
    if (Pilha.topo == MAX-1){
        return(1);
        }
    else{
        return(0);
        }
}

pilha  Inserir_no_topo_da_pilha(pilha Pilha, int num)
{
    if((Indicar_se_a_pilha_esta_cheia(Pilha) == 1)){
        return(Pilha);
    }
    Pilha.topo++;
    int d = Pilha.topo;
    Pilha.dados[d] = num;
    return(Pilha);
}

pilha  Remover_do_topo_da_pilha(pilha Pilha)
{
    if((Indicar_se_a_pilha_esta_vazia(Pilha) == 1)){
        return(Pilha);
    }
    printf("%d\n", Pilha.dados[Pilha.topo]);
    Pilha.dados[Pilha.topo] = NULL;
    Pilha.topo--;
    return(Pilha);
}
int  Ler_o_topo_da_pilha(pilha Pilha)
{
    return(Pilha.dados[Pilha.topo]);
}

int  Retornar_o_tamanho_da_pilha(pilha Pilha)
{
    return(Pilha.topo+1);
}