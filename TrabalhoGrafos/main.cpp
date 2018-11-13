#include <iostream>
#include "Grafo.h"
#include "Grafo.cpp"
using namespace std;

int main() {

    cout<< "teste" << endl;
    Grafo* grafo = new Grafo();
    grafo->adicionarNo(1,0);
    grafo->adicionarNo(2,0);
    grafo->adicionarNo(3,0);
    grafo->adicionarNo(4,0);
    grafo->imprimiGrafo();

    if(grafo->estaNoGrafo(1) == true)
        cout << "Esta no grafo";
    else
        cout << "Nao Esta";
    cout << endl;

    grafo->adicionarArestaNos(1,2,5);
    grafo->adicionarArestaNos(2,3,5);

    grafo->imprimiGrafo();

    //if(grafo->vizinho(1,2) == true)
      //  cout << "Thats It";
    //else
      //  cout << "Oh fuck";

    return 0;
}
