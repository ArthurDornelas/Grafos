#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include <vector>
#include "No.h"
#include "Aresta.h"
#include "Cluster.h"
using namespace std;

class Grafo{
    private:
        std::vector <No> listaAdj;


    public:

        std::vector <No> arvore;
        std::vector <Aresta> arestasArvore;
        std::vector <Aresta> auxArestasArvore;
        std::vector <Cluster> clusters;
        void adicionarArestaNos(int id , int id2,int peso);
        void adicionarNo(int id);
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
        void criaCluster(No no);
        void clusterizacaoGuloso();
        void alocaNosClusters();
        void moveCentroide();
        void separaArestasClusters();
};
#endif // GRAFO_H_INCLUDED
