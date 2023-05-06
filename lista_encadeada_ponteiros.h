#ifndef LISTA_ENCADEADA_PONTEIROS_H_INCLUDED
#define LISTA_ENCADEADA_PONTEIROS_H_INCLUDED
#include "lista_encadeada.h"
typedef struct 
{
        struct lista *lista_ponteiros;
        struct no_ponterio *proximo;
        
} no_ponterio;

typedef struct 
{
        int tamAtual;
        no_ponterio *inicio;
        
} lista_ponteiro;

lista_ponteiro criacao_da_lista_ponteiro_vazia();
int Verificar_se_a_lista_ponteiro_esta_vazia(lista_ponteiro Lista);
int Obter_o_tamanho_da_lista_ponteiro(lista_ponteiro Lista);
int Obter_o_valor_do_elemento_de_uma_determinada_ponteiro_na_lista_ponteiro(lista_ponteiro *Lista,  int num, int num2);

lista_ponteiro insere_inicio_lista_ponteiro(lista_ponteiro Lista ,lista c);
lista_ponteiro insere_fim_lista_ponteiro(lista_ponteiro Lista ,lista c);
lista_ponteiro insere_meio_lista_ponteiro(lista_ponteiro Lista , int num , lista c);

lista_ponteiro Inserir_um_elemento_em_uma_determinada_ponteiro(lista_ponteiro Lista, int num, lista c);

lista_ponteiro remove_inicio_lista_ponteiro(lista_ponteiro Lista);
lista_ponteiro remove_da_lista_ponteiro(lista_ponteiro Lista , int num );

lista_ponteiro Retirar_um_elemento_em_uma_determinada_ponteiro(lista_ponteiro Lista, int num);
void Imprimir_os_elementos_de_toda_a_lista_ponteiro(lista_ponteiro Lista);

#endif // LISTA_ENCADEADA_PONTEIROS_H_INCLUDED