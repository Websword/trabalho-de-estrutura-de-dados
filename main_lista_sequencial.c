#include <stdio.h>
#include "lista_sequencial.h"


int main()
{
    lista x = criacao_da_lista_vazia();
    
    int f = Verificar_se_a_lista_esta_vazia(x);
    printf("%d\n",f);

    x = Inserir_um_elemento_em_uma_determinada_posicao(x, 1, 14);

    f = Verificar_se_a_lista_esta_vazia(x);

    printf("%d\n",f);

    x = Inserir_um_elemento_em_uma_determinada_posicao(x, 2, 15);

    x = Inserir_um_elemento_em_uma_determinada_posicao(x, 1, 13);

    f = Obter_o_tamanho_da_lista(x);

    printf("%d\n",f);

    f = Obter_o_valor_do_elemento_de_uma_determinada_posicao_na_lista(x, 2, 0);

    printf("%d\n",f);
    
    f = Obter_o_valor_do_elemento_de_uma_determinada_posicao_na_lista(x, 14, 1);

    printf("%d\n",f);


    x = Retirar_um_elemento_em_uma_determinada_posicao(x, 1);

    f = Verificar_se_a_lista_esta_cheia(x);

    printf("%d\n",f);
}