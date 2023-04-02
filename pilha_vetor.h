#ifndef PILHA_VETOR_H_INCLUDED
#define PILHA_VETOR_H_INCLUDED


typedef struct 
{
        int *dados; 
        int topo;
        
} pilha;

pilha criacao_da_pilha_vazia();
int Indicar_se_a_pilha_esta_vazia(pilha Pilha);
int Indicar_se_a_pilha_esta_cheia(pilha Pilha);
pilha  Inserir_no_topo_da_pilha(pilha Pilha, int num);
pilha  Remover_do_topo_da_pilha(pilha Pilha);
int  Ler_o_topo_da_pilha(pilha Pilha);
int  Retornar_o_tamanho_da_pilha(pilha Pilha);


#endif // PILHA_VETOR_H_INCLUDED