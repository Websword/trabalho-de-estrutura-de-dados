#ifndef GRAFOS_H_INCLUDED
#define GRAFOS_H_INCLUDED
#include "matrix.h"
#include "lista_encadeada.h"

typedef struct 
{
        int n;
        Matrix *M;
        int *l;
        int *pai;
        int *d;
        int *cor;
        
} Grafo;

Matrix leitura();
Grafo criar_o_grafo_vazio(Matrix m);
Grafo bfs(Grafo grafo, int source);
Grafo dfs(Grafo grafo);



#endif // GRAFOS_H_INCLUDED