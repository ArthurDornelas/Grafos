#include <iostream>
#include "Grafo.h"
#include "Grafo.cpp"

int main() {

    std::cout<< "teste" << std::endl;
    Grafo* grafo = new Grafo();
    grafo->adicionarNo(1,1.2);

    return 0;
}
