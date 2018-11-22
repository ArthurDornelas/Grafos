#include "Cluster.h"
using namespace std
#include <vector>


float Cluster::calculaDintra(int idNo)
{
    float soma = 0;
    int i = 0;
    for(std::vector<No>::iterator no = noCluster.begin(); noCluster.end(); ++no){
        if(no->getId() == idNo)
            break;
        i++;
    }

    for(std::vector<No>::iterator no = noCluster.begin(); noCluster.end(); ++no){

        if(no->getId() != idNo)
        {
            for (std::vector<Aresta>::iterator aresta = arestasCluster.begin(); aresta != arestasCluster.end(); ++aresta)

                if(aresta->getIdNo() != no->getId() || aresta->getIdLista() != no->getId()){
                        soma += aresta->getPesoAresta();
                }

                else{
                    soma += aresta->getPesoAresta();
                    break;
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
