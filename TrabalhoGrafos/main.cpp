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

      grafo->removeAresta(1,2);
      grafo->imprimiGrafo();
      cout << grafo->retornaGrauNo(1) << endl;
      cout << grafo->retornaGrauNo(2) << endl;
      cout << grafo->retornaGrauNo(3) << endl;
      cout << grafo->retornaGrauNo(4) << endl;
      cout<<endl;
      cout << grafo->ordemGrafo() << endl;
      grafo->adicionarNo(1,0);
      cout<<endl;
      cout << grafo->ordemGrafo() << endl;
      cout<<endl;
      grafo->vizinhancaAberta(1);
      cout<<endl;

    return 0;
}
