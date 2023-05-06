#include <stdio.h>
#include "lista_encadeada_ponteiros.h"
#include "lista_encadeada.h"




lista_ponteiro criacao_da_lista_ponteiro_vazia()
{
    lista_ponteiro Lista;
    Lista.tamAtual = 0;
    Lista.inicio = NULL;

    return(Lista);
}

int Verificar_se_a_lista_ponteiro_esta_vazia(lista_ponteiro Lista)
{
        if (Lista.tamAtual == 0){
                return(1);
                }
        else{
                return(0);
                }
}


int Obter_o_tamanho_da_lista_ponteiro(lista_ponteiro Lista)
{
    return(Lista.tamAtual);
}

int Obter_o_valor_do_elemento_de_uma_determinada_ponteiro_na_lista_ponteiro(lista_ponteiro *Lista, int num, int num2)
{
        int cont =1;
        no_ponterio *aux;
        aux = Lista->inicio;
        for(int i=1; i < num; i++){
                aux = aux->proximo;
        }

        lista* redundancia = aux->lista_ponteiros;

        int cont =1;
        no *aux2;
        aux2 = redundancia->inicio;

        if ((num2 > redundancia->tamAtual) || (num2 <= 0)){
                return(-1);
        }
        else{
                for(int i=1; i < num; i++){
                        aux2 = aux2->proximo;
                }
                return(aux2->valor);
        }
        

}

lista_ponteiro insere_inicio_lista_ponteiro(lista_ponteiro Lista ,lista c){

        no_ponterio *novo;

        novo = malloc(sizeof(no_ponterio));
        novo->lista_ponteiros = &c;
        novo->proximo = Lista.inicio;

        Lista.inicio = novo;
        Lista.tamAtual++;

        return(Lista);
        

}

lista_ponteiro insere_fim_lista_ponteiro(lista_ponteiro Lista ,lista c){

        no_ponterio *aux;
        aux = Lista.inicio;

        while( aux->proximo != NULL){
                aux = aux->proximo;
        }

        no_ponterio *novo;

        novo = malloc(sizeof(no_ponterio));
        novo->lista_ponteiros = &c;
        novo->proximo = NULL;



        aux->proximo = novo;
        Lista.tamAtual++;

        return(Lista);
        

}

lista_ponteiro insere_meio_lista_ponteiro(lista_ponteiro Lista , int num , lista c){
        
        no_ponterio *aux;
        aux = Lista.inicio;

        for(int i=0; i < num; i++){
                aux = aux->proximo;
        }

        no_ponterio *novo;

        novo = malloc(sizeof(no_ponterio));
        novo->lista_ponteiros = &c;
        novo->proximo = aux->proximo;

        aux->proximo = novo;

        Lista.tamAtual++;

        return(Lista);
        

}


lista_ponteiro Inserir_um_elemento_em_uma_determinada_ponteiro(lista_ponteiro Lista, int num, lista c)
{
        if(((Verificar_se_a_lista_ponteiro_esta_vazia(Lista) == 1) && (num != 1)) || (num > Lista.tamAtual+1)){
                return(Lista);
        }
        else{
                if (num == 1){
                        return (insere_inicio_lista_ponteiro(Lista , c));
                }
                else if (num == Lista.tamAtual+1){
                        return (insere_fim_lista_ponteiro(Lista , c));
                }
                else{
                        return (insere_meio_lista_ponteiro(Lista, num, c));
                }

        }
}



lista_ponteiro remove_inicio_lista_ponteiro(lista_ponteiro Lista){
        no_ponterio *aux;
        aux = Lista.inicio;
        Lista.inicio = aux->proximo;
        free(aux);

        return(Lista);
}

lista_ponteiro remove_da_lista_ponteiro(lista_ponteiro Lista , int num ){
        no_ponterio *aux;
        aux = Lista.inicio;
        no_ponterio *antes;
        for(int i=0; i < num; i++){
                antes = aux;
                aux = aux->proximo;
        }
        antes->proximo = aux->proximo;
        free(aux);

        return(Lista);
}

lista_ponteiro Retirar_um_elemento_em_uma_determinada_ponteiro(lista_ponteiro Lista, int num)
{
        if((Verificar_se_a_lista_ponteiro_esta_vazia(Lista) == 1) || (num > Lista.tamAtual)){
                return(Lista);
        }
        else{
                if (num == 1){
                        return (remove_inicio_lista_ponteiro(Lista));
                }
                else{
                        return (remove_da_lista_ponteiro(Lista, num));
                }

        }
}

void Imprimir_os_elementos_de_toda_a_lista_ponteiro(lista_ponteiro Lista)
{
        no_ponterio *aux;
        aux = Lista.inicio;
        lista aq;

        while( aux->proximo != NULL){
                lista *travesia = aux->lista_ponteiros;
                no *aux2 = travesia->inicio;

                while( aux2->proximo != NULL){
                        printf("%d\n",aux2->valor);
                        aux2 = aux2->proximo;
                }
                printf("%d\n",aux2->valor);



                aux = aux->proximo;
        }
        lista *travesia = aux->lista_ponteiros;
        no *aux2 = travesia->inicio;

        while( aux2->proximo != NULL){
                printf("%d\n",aux2->valor);
                aux2 = aux2->proximo;
        }
        printf("%d\n",aux2->valor);

}