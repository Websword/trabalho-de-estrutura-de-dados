#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"
#include "grafos.h"
#include "lista_encadeada.h"
#include "lista_encadeada_ponteiros.h"

# define BRANCO 0;
# define CINZA 1;
# define PRETO 2;

Grafo criar_o_grafo_vazio(Matrix m){
    Grafo grafo;
    grafo.n = m.data[0];
    m.data[0] = 0;
    grafo.M = &m;
    int *arr1[grafo.n];
    int *arr2[grafo.n];
    int *arr3[grafo.n];

    for(int i=0; i<grafo.n; i++){
        arr1[i]=NULL;
        arr2[i]=-1;
        arr3[i]=BRANCO;
    }

    int valor;
    lista_ponteiro lipon = criacao_da_lista_ponteiro_vazia();
    
    for(int i=0; i<grafo.n; i++){
        lista lisss = criacao_da_lista_vazia();
        lisss = insere_fim_lista(lisss ,i);
        lipon = insere_fim_lista_ponteiro(lipon ,lisss);
    }

    grafo.l = &lipon;
    grafo.pai = arr1;
    grafo.d = arr2;
    grafo.cor = arr3;

    return(grafo);
}


Grafo leitura(char *file_name){
    FILE *arq;
    char cara;
    int copia;
    int tamanho_matriz=0;
    int checar =0;
    int total =0;
    int i;
    int* data;



    arq=fopen(file_name, "r");
    if(!arq){
        printf("\n Nao abriu\n");
        return;
    }
    printf("\n1 - O arquivo estah em: %p\n",arq);
    fscanf(arq,"%c",&cara);


    while (!feof(arq)){
        printf("%c",cara);

        if (cara >= 48 && cara <= 57 ){
            //printf("%c",cara);
            copia = cara;
            //printf("%d",copia-48);
            if (checar == 0 ){
                tamanho_matriz = tamanho_matriz*10 + (copia-48);
                printf("%d",tamanho_matriz);
            }
            else{
                total = total*10 +(copia-48);
            }
        }
        else{
            if (checar == 0 ){
                checar==1;
                data = (int*)malloc(tamanho_matriz * tamanho_matriz * sizeof(int));
            }
            else{
                data[i] = total;
                if (i =0){
                    data[i] = tamanho_matriz;
                }
                i++;
                total = 0;
            }
        }

        
        fscanf(arq,"%c",&cara);
    }
    fclose(arq);
    Matrix mat = create_matrix(*data,tamanho_matriz,tamanho_matriz);
    return(criar_o_grafo_vazio(mat));
}



int num_componentes_conexas(Grafo grafo){
    int n_comp = 0;
    for(int i=0; i<grafo.n; i++){
        if (grafo.pai = NULL){
            n_comp++;
        }
    }
    return(n_comp);
}

Grafo bfs(Grafo grafo, int source){
    grafo.cor[source]=CINZA;
    grafo.d[source]=0;
    lista lis;
    lis = criacao_da_lista_vazia();
    lis = Inserir_um_elemento_em_uma_determinada_posicao(lis, 0, source);
    while (Verificar_se_a_lista_esta_vazia(lis) == 0){
        int u = Obter_o_valor_do_elemento_de_uma_determinada_posicao_na_lista(lis, 0, 0);
        lis = Retirar_um_elemento_em_uma_determinada_posicao(lis, 0);
        int contador = 1;

        int v = Obter_o_valor_do_elemento_de_uma_determinada_ponteiro_na_lista_ponteiro(grafo.l, u, contador);
        while (v != -1){
            if(grafo.cor[v] == 0){
                grafo.cor[v]= CINZA;
                grafo.d[v] = grafo.d[u] + 1;
                grafo.pai[v]  = u;
                lis =insere_fim_lista(lis ,v);
                contador++;
                v = Obter_o_valor_do_elemento_de_uma_determinada_ponteiro_na_lista_ponteiro(grafo.l, u, contador);
            }
        }
        grafo.cor[u]=PRETO;
    }
    printf("d pai");
    for(int i=0; i<grafo.n; i++){
        printf("%d ", grafo.d[i]);
        printf("%d\n", grafo.pai[i]);
    }
    return(grafo);
}

Grafo dfs(Grafo grafo){
    lista falsa_pilha;
    falsa_pilha = criacao_da_lista_vazia();
    for(int u=0; u<grafo.n; u++){
        if (grafo.cor[u]==0){
            grafo.cor[u]==CINZA;
            insere_inicio_lista(falsa_pilha ,u);
            
            while (Verificar_se_a_lista_esta_vazia(falsa_pilha) == 0){
                int contador =1;
                int valor = Obter_o_valor_do_elemento_de_uma_determinada_posicao_na_lista(falsa_pilha, 0, 0);
                int v = Obter_o_valor_do_elemento_de_uma_determinada_ponteiro_na_lista_ponteiro(grafo.l, valor, contador);
                while (v !=-1){
                    if(grafo.cor[v] == 0){
                        grafo.cor[v]= CINZA;
                        grafo.d[v] = grafo.d[u] + 1;
                        grafo.pai[v]  = u;
                        falsa_pilha = insere_inicio_lista(falsa_pilha ,v);
                        break;
                    }
                    contador++;
                    v = Obter_o_valor_do_elemento_de_uma_determinada_ponteiro_na_lista_ponteiro(grafo.l, u, contador);
                }
                if (v==-1){
                    grafo.cor[valor]==PRETO;
                    falsa_pilha = remove_inicio_lista(falsa_pilha);
                }
            }
        }
    }
}

