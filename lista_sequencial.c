#include <stdio.h>
#include "lista_sequencial.h"
#define MAX 100


lista criacao_da_lista_vazia()
{
    int arr[MAX];

    lista Lista;
    Lista.dados = arr;
    Lista.tamAtual = 0;

    return(Lista);
}

int Verificar_se_a_lista_esta_vazia(lista Lista)
{
    if (Lista.tamAtual == 0){
        return(1);
        }
    else{
        return(0);
        }
}

int Verificar_se_a_lista_esta_cheia(lista Lista)
{
    if (Lista.tamAtual == MAX){
        return(1);
        }
    else{
        return(0);
        }
}

int Obter_o_tamanho_da_lista(lista Lista)
{
    return(Lista.tamAtual);
}

int Obter_o_valor_do_elemento_de_uma_determinada_posicao_na_lista(lista Lista, int num, int tipo)
{
    if (tipo==0){
        if ((num >= MAX) || (num <= 0)){
            return(-1);
        }
        else{
            int res = Lista.dados[num-1];
        }
    }
    else{
        for(int i=0; i < Lista.tamAtual; i++){
            if (Lista.dados[i] == num){
                return(i+1);
            }
        }
        return(-1);
    }
}


lista Inserir_um_elemento_em_uma_determinada_posicao(lista Lista, int num, int c)
{
    if((Verificar_se_a_lista_esta_cheia(Lista) == 1) || (num > Lista.tamAtual+1)){
        return(Lista);
    }
    for(int i=Lista.tamAtual; i >= num; i--){
        Lista.dados[i] = Lista.dados[i-1];
    }
    Lista.dados[num-1] = c;
    Lista.tamAtual++;
    return(Lista);
}

lista Retirar_um_elemento_em_uma_determinada_posicao(lista Lista, int num)
{
    if((Verificar_se_a_lista_esta_vazia(Lista) == 1) || (num > Lista.tamAtual+1)){
        return(Lista);
    }
    printf("%d\n",Lista.dados[num-1]);
    for(int i = num-1; i < Lista.tamAtual-1; i++){
        Lista.dados[i] = Lista.dados[i+1];
    }
    Lista.tamAtual--;
    return(Lista);
}