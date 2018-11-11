#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
#include <vector>
#include "No.h"

class Grafo{
    private:
        std::vector <No> listaAdj;

    public:
        Grafo();
        ~Grafo();
        void adicionarNo(int  id);
        void removerNo(int id);
        int ordemGrafo();
        bool grafoCompleto();
        bool grafoKRegularidade(int k);
        void vizinhacaAberta(int id);
        void vizinhacaFechada(int id);
        void sequenciaGraus();

};
#endif // GRAFO_H_INCLUDED
