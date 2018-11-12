#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include <vector>
#include "No.h"
#include "Aresta.h"

class Grafo{
    private:
        std::vector <No> listaAdj;

    public:

        void adicionarNo(int id, float pesoNo);
        void removerNo(int id);
        int ordemGrafo();
        bool grafoCompleto();
        bool grafoKRegularidade(int k);
        void vizinhacaAberta(int id);
        void vizinhacaFechada(int id);
        void sequenciaGraus();
        void imprimiGrafo();
        void algoritmoPrim();
};
#endif // GRAFO_H_INCLUDED
