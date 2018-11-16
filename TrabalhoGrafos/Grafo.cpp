#include "Grafo.h"
#include "No.h"
#include "No.cpp"
#include <vector>
#define INF 99999;
using namespace std;

void Grafo::adicionarNo(int id)
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

void Grafo::removeAresta(int id1,int id2)
{
    if(estaNoGrafo(id1) && estaNoGrafo(id2)){
        if(vizinho(id1,id2)){
        for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it) {
             if( it->getId() == id1 )
                    it->removeAresta(id2);
             if( it->getId() == id2)
                    it->removeAresta(id1);
        }
           }

    } else {
         cout << "Um ou mais NOS nao existem, impossivel remover a ARESTA." << endl;
    }

}

void Grafo::adicionarArestaNos(int id , int id2,int peso)
{

     if(estaNoGrafo(id) == true){

        if(estaNoGrafo(id2) == true){

           for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it){

              if(id != id2)  {
                    if(it->getId() == id){
                        it->adicionaAresta(id2,peso);
                    }

                    if(it->getId() == id2){
                        it->adicionaAresta(id,peso);
                    }
              }
           }
        }
        else
            cout << "Os vertices nao existem.";
     }

     else
        cout << "Os vertices nao existem.";


}


bool Grafo::estaNoGrafo(int i)
{
    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it) {
        if( it->getId() == i ){
            return true;
        }
    }
    return false;
}

int Grafo::ordemGrafo()
{
    return listaAdj.size();
}

int Grafo::retornaGrauNo(int id)
{

    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it) {
        if( it->getId() == id ){
            return it->getGrau();
        }
    }
    cout << "Nao existe esse NO no Grafo."<<endl;

}

bool Grafo::vizinho(int id1, int id2)
{
    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it){
        if(it->getId() == id1 ){
            return it->eVizinho(id2);
        }
        if(it->getId() == id2 ){
            return it->eVizinho(id1);
        }
    }
    return false;
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

void Grafo::vizinhancaAberta(int id)
{
    int i=0;
    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it, i++) {
         if( it->getId() == id )
         {
            if(it->listaAresta.size() >= 1){
                for(std::vector<Aresta>::iterator arest = listaAdj[i].listaAresta.begin(); arest != listaAdj[i].listaAresta.end(); ++arest)
                std::cout << arest->getIdNo() << std::endl;
                break;
            }
            else {
                cout << "Vizinhanca aberta sem nos" << endl;
                break;
            }
         }
    }
}

void Grafo::vizinhancaFechada(int id)
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
            std::cout << "No " << it->getId() << " - " << it->getGrau() << "  ";
    }
}


void Grafo::algoritmoPrim()
{
    int posListaAdj = 0;
    int cont = 0;
    std::vector <No> arvore;
    arvore.push_back(listaAdj[0]);

    while(cont < listaAdj.size()){
        int menor = INF;
        int idNo = -1;
        int arestaMenor = -1;
        //loop para ver qual a menor aresta
        int contAresta = 0;
        for(std::vector<Aresta>::iterator arest = listaAdj[posListaAdj].listaAresta.begin(); arest != listaAdj[posListaAdj].listaAresta.end(); ++arest){
            bool flag=false;
            if(arest->getPesoAresta() <= menor){

                for (std::vector<No>::iterator arv = arvore.begin(); arv != arvore.end(); ++arv)  // verifica se o id do No ja esta na arvore
                {
                    if(arest->getIdNo() == arv->getId())
                        flag = true;
                }
                if(flag == false){
                    menor = arest->getPesoAresta(); //recebe o peso da aresta
                    arestaMenor = contAresta;
                }

            }
            contAresta++;

        }
        idNo = listaAdj[posListaAdj].listaAresta[arestaMenor].getIdNo();
        int i = 0;
        for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it){
               if(idNo == it->getId()){
                    posListaAdj = i;
                    arvore.push_back(listaAdj[i]);
                    break;
               }
                i++;
        }
    cont++;
    }

    for (std::vector<No>::iterator no = arvore.begin(); no != arvore.end(); ++no){
           cout << no->getId() << "  ";
   }
}


void Grafo::imprimiGrafo()
{


    for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it){
        int j=0;
        std::cout << it->getId();
         for(std::vector <Aresta>::iterator arest = it->listaAresta.begin(); arest != it->listaAresta.end(); arest++,j++){
            std::cout << " -> " << it->listaAresta[j].getIdNo();
         }
         std::cout << std::endl;
    }


}
