#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED
#include "No.h"
class Aresta{
    private:
        float pesoAresta;
        int identNo;
    public:
        ~Aresta();
        Aresta(int iD_No,float pesoA){ this->identNo = iD_No; this->pesoAresta = pesoA; };
        float getPesoAresta(){ return this->pesoAresta; };
        int getIdNo(){ return this->identNo; };
        int setIdNo(int id) {this->identNo = id; };
        void setPesoAresta(float peso){ this->pesoAresta = peso; };
};

#endif // ARESTA_H_INCLUDED
