#include <iostream>
#include "GrafoMA.h"
#include "GrafoMA.cpp"
#include "GrafoLA.h"
#include "GrafoLA.cpp"

using namespace std;

int main()
{
    int n;
    int v;

    cout << "Digite qual estrutura quer utilizar: ( 1 - Lista de Adjacencia 2 - Matriz de Adjacencia)" << endl;
    cin >> n;

    cout << "Digite o numero de vetores:";
    cin >> v;

   if(n==2)
   {
        GrafoMA grafo(v);

        grafo.addAresta(0,1);
        grafo.addAresta(1,3);

        cout << grafo.grauVertice(1);

   }

   if(n==1)

   {

        GrafoLA grafo(v);
        grafo.addAresta(0,1);
        grafo.addAresta(1,3);

        cout << grafo.grauVertice(1) << endl;

   }

    return 0;
}
