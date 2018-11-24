#include "Cluster.h"
using namespace std
#include <vector>


float Cluster::calculaDintra(int id)
{
    int id_lista = -1;
    float soma = 0;
    int i = 0;
    for(std::vector<No>::iterator no = noCluster.begin(); noCluster.end(); ++no){
        if(no->getId() == id)
            break;
        i++;
    }

    for(std::vector<No>::iterator no = noCluster.end(); noCluster.begin(); --no){


        if(no->getId() != id)
        {
            for (std::vector<Aresta>::iterator aresta = arestasCluster.begin(); aresta != arestasCluster.end(); ++aresta){

                if(aresta->getIdNo == no->getId()){
                    id_lista = no->getId();

                    for (std::vector<Aresta>::iterator arest = aresta; arest->getIdLista() != id ; ++aresta){

                        if(aresta->getIdNo() != no->getId() || aresta->getIdLista() != no->getId()){
                            soma += aresta->getPesoAresta();
                        }

                        else{
                            soma += aresta->getPesoAresta();
                            break;
                        }
                    }

                }
            }
        }

    }



    cout<< soma << endl;



    /*float soma=0;
    for(int i=0;i<arestasCluster.size();i++)
        soma+=noCluster[0].listaAresta[i].getPesoAresta();
    int num =getNnos()-1;
    return soma/num;
    */
}
