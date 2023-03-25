#ifndef LISTA_ENCADEADA_H_INCLUDED
#define LISTA_ENCADEADA_H_INCLUDED

typedef struct 
{
        int valor;
        struct no *proximo;
        
} no;

typedef struct 
{
        int tamAtual;
        no *inicio;
        
} lista;

lista criacao_da_lista_vazia();
int Verificar_se_a_lista_esta_vazia(lista Lista);
int Obter_o_tamanho_da_lista(lista Lista);
int Obter_o_valor_do_elemento_de_uma_determinada_posicao_na_lista(lista Lista, int num, int tipo);

lista insere_inicio_lista(lista Lista ,int c);
lista insere_fim_lista(lista Lista ,int c);
lista insere_meio_lista(lista Lista , int num , int c);

lista Inserir_um_elemento_em_uma_determinada_posicao(lista Lista, int num, int c);

lista remove_inicio_lista(lista Lista);
lista remove_da_lista(lista Lista , int num );

lista Retirar_um_elemento_em_uma_determinada_posicao(lista Lista, int num);
void Imprimir_os_elementos_de_toda_a_lista(lista Lista);

#endif // LISTA_ENCADEADA_H_INCLUDED