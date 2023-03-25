#include <stdio.h>
#include "lista_encadeada.h"




lista criacao_da_lista_vazia()
{
    lista Lista;
    Lista.tamAtual = 0;
    Lista.inicio = NULL;

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


int Obter_o_tamanho_da_lista(lista Lista)
{
    return(Lista.tamAtual);
}

int Obter_o_valor_do_elemento_de_uma_determinada_posicao_na_lista(lista Lista, int num, int tipo)
{
        int cont =1;
        no *aux;
        aux = Lista.inicio;


        if (Verificar_se_a_lista_esta_vazia(Lista) == 1){
                return(-1);
        }
        else{
                if (tipo==0){
                        if ((num > Lista.tamAtual) || (num <= 0)){
                                return(-1);
                        }
                        else{
                                for(int i=1; i < num; i++){
                                        aux = aux->proximo;
                                }
                                return(aux->valor);
                        }
                }
                else{
                        while(aux != NULL){
                                if (aux->valor == num)
                                {
                                        return(cont);
                                }
                                aux = aux->proximo;
                                cont++;
                        }
                }
        }
}

lista insere_inicio_lista(lista Lista ,int c){

        no *novo;

        novo = malloc(sizeof(no));
        novo->valor = c;
        novo->proximo = Lista.inicio;

        Lista.inicio = novo;
        Lista.tamAtual++;

        return(Lista);
        

}

lista insere_fim_lista(lista Lista ,int c){

        no *aux;
        aux = Lista.inicio;

        while( aux->proximo != NULL){
                aux = aux->proximo;
        }

        no *novo;

        novo = malloc(sizeof(no));
        novo->valor = c;
        novo->proximo = NULL;



        aux->proximo = novo;
        Lista.tamAtual++;

        return(Lista);
        

}

lista insere_meio_lista(lista Lista , int num , int c){
        
        no *aux;
        aux = Lista.inicio;

        for(int i=0; i < num; i++){
                aux = aux->proximo;
        }

        no *novo;

        novo = malloc(sizeof(no));
        novo->valor = c;
        novo->proximo = aux->proximo;

        aux->proximo = novo;

        Lista.tamAtual++;

        return(Lista);
        

}


lista Inserir_um_elemento_em_uma_determinada_posicao(lista Lista, int num, int c)
{
        if(((Verificar_se_a_lista_esta_vazia(Lista) == 1) && (num != 1)) || (num > Lista.tamAtual+1)){
                return(Lista);
        }
        else{
                if (num == 1){
                        return (insere_inicio_lista(Lista , c));
                }
                else if (num == Lista.tamAtual+1){
                        return (insere_fim_lista(Lista , c));
                }
                else{
                        return (insere_meio_lista(Lista, num, c));
                }

        }
}



lista remove_inicio_lista(lista Lista){
        no *aux;
        aux = Lista.inicio;
        Lista.inicio = aux->proximo;
        free(aux);

        return(Lista);
}

lista remove_da_lista(lista Lista , int num ){
        no *aux;
        aux = Lista.inicio;
        no *antes;
        for(int i=0; i < num; i++){
                antes = aux;
                aux = aux->proximo;
        }
        antes->proximo = aux->proximo;
        free(aux);

        return(Lista);
}

lista Retirar_um_elemento_em_uma_determinada_posicao(lista Lista, int num)
{
        if((Verificar_se_a_lista_esta_vazia(Lista) == 1) || (num > Lista.tamAtual)){
                return(Lista);
        }
        else{
                if (num == 1){
                        return (remove_inicio_lista(Lista));
                }
                else{
                        return (remove_da_lista(Lista, num));
                }

        }
}

void Imprimir_os_elementos_de_toda_a_lista(lista Lista)
{
        no *aux;
        aux = Lista.inicio;

        while( aux->proximo != NULL){
                printf("%d\n",aux->valor);
                aux = aux->proximo;
        }
        printf("%d\n",aux->valor);

}