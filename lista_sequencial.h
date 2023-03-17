#ifndef LISTA_SEQUENCIAL_H_INCLUDED
#define LISTA_SEQUENCIAL_H_INCLUDED


typedef struct 
{
        int *dados; 
        int tamAtual;
        
} lista;

lista criacao_da_lista_vazia();
int Verificar_se_a_lista_esta_vazia(lista Lista);
int Verificar_se_a_lista_esta_cheia(lista Lista);
int Obter_o_tamanho_da_lista(lista Lista);
int Obter_o_valor_do_elemento_de_uma_determinada_posicao_na_lista(lista Lista, int num, int tipo);
lista Inserir_um_elemento_em_uma_determinada_posicao(lista Lista, int num, int c);
lista Retirar_um_elemento_em_uma_determinada_posicao(lista Lista, int num);



#endif // LISTA_SEQUENCIAL_H_INCLUDED