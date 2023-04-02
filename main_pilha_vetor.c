#include <stdio.h>
#include "pilha_vetor.h"

int main()
{

    pilha x = criacao_da_pilha_vazia();

    int f = Indicar_se_a_pilha_esta_vazia(x);
    printf("%d\n",f);

    x = Inserir_no_topo_da_pilha(x, 10);

    f = Indicar_se_a_pilha_esta_vazia(x);
    printf("%d\n",f);



    f = Ler_o_topo_da_pilha(x);
    printf("%d\n",f);

    f = Retornar_o_tamanho_da_pilha(x);
    printf("%d\n",f);

    x = Remover_do_topo_da_pilha(x);

    f = Indicar_se_a_pilha_esta_vazia(x);
    printf("%d\n",f);

    

    return(0);
}