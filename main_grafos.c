#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"
#include "grafos.h"
#include "lista_encadeada.h"

int main(){
    char * texto;
    Grafo g;
    g = leitura("pcv4.txt");
    print_matrix(g.M);
    return(0);
}