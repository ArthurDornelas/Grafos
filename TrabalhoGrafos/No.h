#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED
#include <vector>
#include "Aresta.h"
class No{

private:
    int id;
    int grau;

public:
    std::vector <Aresta> listaAresta;
    No();
    No(int id, int grau);
    ~No();
    int getId();
    int getGrau();
    void setId(int id);
    void setGrau(int g);
    void adicionaAresta(int id,float pesoA,bool arco);
    void adicionaAresta(int id,float pesoA);
    void removeAresta(int id);
    float getAresta(int index);

};

#endif // NO_H_INCLUDED
