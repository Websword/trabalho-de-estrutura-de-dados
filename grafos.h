#ifndef GRAFOS_H_INCLUDED
#define GRAFOS_H_INCLUDED
#include "matrix.h"
#include "lista_encadeada.h"
#include "lista_encadeada_ponteiros.h"

typedef struct 
{
        int n;
        Matrix *M;
        lista_ponteiro *l;
        int *pai;
        int *d;
        int *cor;
        
} Grafo;

Grafo leitura(char *file_name);
Grafo criar_o_grafo_vazio(Matrix m);
int num_componentes_conexas(Grafo grafo);
Grafo bfs(Grafo grafo, int source);
Grafo dfs(Grafo grafo);



#endif // GRAFOS_H_INCLUDED