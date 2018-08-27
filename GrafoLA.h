
#include <iostream>

using namespace std;


class GrafoLA
{

 private:

    int vert;
    list<int> *listAdj;
    list<int>::iterator it;

 public:

        GrafoLA(int vertices);
        void addAresta(int vert1 , int vert2);
        void excluiAresta(int vert1, int vert2);
        void addVertice();
        void excluiVertice(int v);
        int grauVertice(int v);

};


#endif // GRAFOLA_H_INCLUDED
