#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED

class Aresta{
    private:
        float pesoAresta;
        int identNo;
    public:
        Aresta();
        ~Aresta();
        Aresta(int iD_No,float pesoA);
        float getPesoAresta();
        int getIdNo();
        int setIdNo(int id);
        void setPesoAresta(float peso);
};

#endif // ARESTA_H_INCLUDED
