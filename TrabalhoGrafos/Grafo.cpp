#include "Grafo.h"
#include "No.h"
#include "No.cpp"
#include <vector>
void Grafo::adicionarNo(int id, float pesoNo)
{
    No no = No();
    no.setId(id);
    listaAdj.push_back(no);
}

void Grafo::removerNo (int id)
{
    std::vector <No>::iterator it;
    std::vector <Aresta>::iterator a;
    int i=0,j=0;
    for(it = listaAdj.begin() ; it != listaAdj.end(); ++it, i++ ){
        if ( it->getId() == id ){
            listaAdj.erase( listaAdj.begin() + i  );
        }
    }
    i =0;
    for(it = listaAdj.begin(); it != listaAdj.end(); ++it,i++){
            j = 0;
        for(std::vector<Aresta>::iterator a = listaAdj[i].listaAresta.begin(); a != listaAdj[i].listaAresta.end() && j < listaAdj[i].listaAresta.size() ;   ++a){
                if(a->getIdNo() == id) {
                    listaAdj[i].listaAresta.erase( listaAdj[i].listaAresta.begin() + j );
                }
                j++;
        }
    }
}

int Grafo::ordemGrafo()
{
    return listaAdj.size();
}

bool Grafo::grafoCompleto()
{
    int n = ordemGrafo();
    int num_Arestas = 0;
    for(int i = 0; i < n; i++) {
        num_Arestas += listaAdj[i].getGrau();
    }
    if(num_Arestas == n*(n-1))
        return true;
    return false;

}

bool Grafo::grafoKRegularidade(int k)
{
    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it) {
                if(it->getGrau()!=k)
                {
                    return false;
                }
    }
    return true;

}

void Grafo::vizinhacaAberta(int id)
{
    int i=0;
    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it, i++) {
         if( it->getId() == id )
         {
            for(std::vector<Aresta>::iterator arest = listaAdj[i].listaAresta.begin(); arest != listaAdj[i].listaAresta.end(); ++arest)
                std::cout << arest->getIdNo() << std::endl;
         }
    }
}

void Grafo::vizinhacaFechada(int id)
{
    int i=0;
    std::cout << id << std::endl;
    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it, i++) {
         if( it->getId() == id )
         {
            for(std::vector<Aresta>::iterator arest = listaAdj[i].listaAresta.begin(); arest != listaAdj[i].listaAresta.end(); ++arest)
                std::cout << arest->getIdNo() << std::endl;
         }
    }

}

/* Nao terminado
bool Grafo::bipartido()
{
    int numNo = listaNos.size();
    int selecionaVert[numNo+1];
    for (int i = 1; i <= numNo; ++i)
        selecionaVert[i] = -1;

    //O loop faz uma busca em largura, e tenta selecionar 2 grupos, provando a bipartilidade.
    for (int i = 1; i <= V; i++)
      if (selecionaVert[i] == -1)
        if (tenta2ColorirGrafo(i, selecionaVert) == false)
           return false;

     return true;

}
*/

void Grafo::sequenciaGraus()
{
    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it) {
            std::cout << it->getGrau() << " ";
    }
}
/*
void Grafo::algoritmoPrim()
{
    int menor = -1;
    int i = 0;
    int cont = 0;

    // cria vetor para armazenar o id dos nós da árvore
    int tam =  listaAdj.size();
    int arvore[tam];

    for(int i=0;i<tam;i++)
        arvore[i]=-1;
    // fim - criação vetor arvore

    while(cont < listaAdj.size()){
        std::vector<No>::iterator it = listaAdj[i];
        menor = it.listaAresta[0].getPesoAresta; //menor peso de aresta ligante
        for(std::vector<Aresta>::iterator arest = listaAdj[i].listaAresta.begin(); arest != listaAdj[i].listaAresta.end(); ++arest){
               bool flag=false;
            if(arest.getPesoAresta<menor){

            for(k=0;k<tam;k++)
            {
                if(arest.GetId ==arvore[k]){
                    flag = true;
                }
            }
            if(flag =false){
                menor=Aresta.getPesoAresta
                arvore[i+1]=arest.idNome;
                break;
            }

        }
        arvore[k+1]=it.listaAresta[0].getID



    i++;
    cont++;
    }
}
*/
void Grafo::imprimiGrafo(){
    int i=0,j=0;

    for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it,i++){
        std::cout << listaAdj[i].getId();
         for(std::vector <Aresta>::iterator arest = listaAdj[i].listaAresta.begin(); arest != listaAdj[i].listaAresta.end(); arest++,j++ ){
            std::cout << " -> " << listaAdj[i].listaAresta[j].getIdNo();
         }
         std::cout << std::endl;
    }


}
