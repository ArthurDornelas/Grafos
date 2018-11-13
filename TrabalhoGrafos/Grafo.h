#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include <vector>
#include "No.h"
#include "Aresta.h"
using namespace std;

class Grafo{
    private:
        std::vector <No> listaAdj;

    public:

        void adicionarArestaNos(int id , int id2,int peso);
        void adicionarNo(int id, float pesoNo);
        void removerNo(int id);
        void removeAresta(int id1, int id2);
        void adicionaAresta(int id1,int id2, float peso);
        bool estaNoGrafo(int index);
        int ordemGrafo();
        int retornaGrauNo(int id);
        bool vizinho(int id1, int id2);
        bool grafoCompleto();
        bool grafoKRegularidade(int k);
        void vizinhancaAberta(int id);
        void vizinhancaFechada(int id);
        void sequenciaGraus();
        void imprimiGrafo();
        void algoritmoPrim();
};
#endif // GRAFO_H_INCLUDED
