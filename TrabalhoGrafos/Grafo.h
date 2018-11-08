#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

class Grafo{
    private:
        vector <No> listaAdj;

    public:
        Grafo();
        ~Grafo();
        void adcionarNo(int  id);
        void removerNo(int id);
        int ordemGrafo();
        bool grafoCompleto();



};
#endif // GRAFO_H_INCLUDED
