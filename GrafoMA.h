
#ifndef GRAFOMA_H_INCLUDED
#define GRAFOMA_H_INCLUDED


class GrafoMA
{
    public:
        GrafoMA(int n);
        ~GrafoMA();
        void addAresta(int vert1 , int vert2);
        void excluiAresta(int vert1, int vert2);
        void addVertice();
        void excluiVertice(int v);
        int grauVertice(int v);


    private:
        int n;
        float **mat;

};



#endif // GRAFOMA_H_INCLUDED
