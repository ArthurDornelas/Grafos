#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED
#include "No.h"
using namespace std;

class Aresta{
    private:
        float pesoAresta;
        int identNo;
    public:
        Aresta(int idNo,float pesoA){ identNo = idNo; pesoAresta = pesoA; };
        float getPesoAresta(){ return this->pesoAresta; };
        int getIdNo(){ return this->identNo; };
        void setIdNo(int id) {this->identNo = id; };
        void setPesoAresta(float peso){ this->pesoAresta = peso; };
};

#endif // ARESTA_H_INCLUDED
