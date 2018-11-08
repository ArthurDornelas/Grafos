#include <iostream>
#include "GrafoMatriz.h"

int main() {
    std::cout << "--------------------------" << std::endl;
    GrafoMatriz* grafo = new GrafoMatriz();
    grafo->imprimirGrafo();
    for(int i = 0; i < 5; ++i)
        grafo->adicionarVertice();

    grafo->imprimirGrafo();
    grafo->removerVertice();
    grafo->imprimirGrafo();
    grafo->adicionarAresta(0,0);
    grafo->imprimirGrafo();
    grafo->adicionarAresta(4,0);
    grafo->removerAresta(0,0);
    grafo->imprimirGrafo();
    grafo->adicionarVertice();
    grafo->adicionarAresta(4,2);
    grafo->imprimirGrafo();
    grafo->informarGrauDoVertice(4);
    grafo->informarGrauDoVertice(2);
    grafo->informarGrauDoVertice(3);
    grafo->removerAresta(4,2);
    grafo->informarGrauDoVertice(2);
    grafo->informarGrauDoVertice(4);

    return 0;
}