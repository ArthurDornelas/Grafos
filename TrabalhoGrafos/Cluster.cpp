#include "Cluster.h"
using namespace std;
#include <vector>
#include "Aresta.h"

float Cluster::calculaDintra(int id)
{
    //cout << "Calcula d intra" << endl;
    bool flag = false;
    int id_lista = -1;
    float soma = 0;
    int i = 0, j=0, a = -1;
    for(std::vector<No>::iterator noId = noCluster.begin(); noId != noCluster.end(); ++noId){
        if(noId->getId() == id)
            break;
        i++;
    }
    //cout << i << endl;


    for(int j = (noCluster.size() - 1) ; j>=0 ; j--){

      flag = false;
      //cout << "Entra vetor No" << endl;
      //cout << noCluster[j].getId() << endl;
      //cout << j << endl;
      id_lista = -1;
      if(i < j)  {

         if(noCluster[j].getId() != id)
         {
             a = 0;
            for (std::vector<Aresta>::iterator aresta = arestasCluster.begin(); aresta != arestasCluster.end(); ++aresta){
                //cout << "Entra vetor 1 Aresta" << endl;
                if(aresta->getIdNo() == noCluster[j].getId()){
                    id_lista = noCluster[j].getId();
                    //cout << "aresta get idNo" << aresta->getIdNo() <<endl;

                    for (std::vector<Aresta>::iterator arest = aresta; arest->getIdNo() != id || a >=0 ; --arest){
                        //cout << "aresta 2 get idNo" << arest->getIdNo() <<endl;
                        //cout << "id lista " << id_lista <<endl;
                        if(arest->getIdLista() != id && arest->getIdNo() == id_lista){
                           // cout << "entra no If" <<endl;
                            soma += arest->getPesoAresta();
                            id_lista = arest->getIdLista();
                        }

                        else if(arest->getIdLista() == id && arest->getIdNo() == id_lista){
                          //  cout << "entra no Else If" <<endl;
                            soma += arest->getPesoAresta();
                          //  cout << "Soma: " << soma <<endl;
                            flag = true;
                            break;
                        }
                        else if(arest->getIdLista() != id && arest->getIdNo() == id){
                          //  cout << "entra no Else If 2" <<endl;
                            soma += arest->getPesoAresta();
                          //  cout << "Soma: " << soma <<endl;
                            flag = true;
                            break;
                        }
                       // cout << "Soma: " << soma <<endl;
                        a--;
                    }
                }
                if(flag == true)
                    break;
                a++;
            }
         }
      }

      else
      {
          if(noCluster[j].getId() != id)
          {
              a = 0;
            for (std::vector<Aresta>::iterator aresta = arestasCluster.begin(); aresta != arestasCluster.end(); ++aresta){
                // cout << "Entra vetor 1 Aresta" << endl;
                if(aresta->getIdNo() == id){
                    id_lista = aresta->getIdNo();
                   // cout << "aresta get idNo" << aresta->getIdNo() <<endl;

                    for (std::vector<Aresta>::iterator arest = aresta; arest->getIdNo() != noCluster[j].getId() || a >=0 ; --arest){
                       // cout << "aresta 2 get idNo " << arest->getIdNo() <<endl;
                       // cout << "aresta 2 get idLista " << arest->getIdLista() <<endl;
                       // cout << "id lista " << id_lista <<endl;
                        if(arest->getIdLista() != noCluster[j].getId() && arest->getIdNo() == id_lista && noCluster[j].getId() != arest->getIdNo()){
                          //  cout << "entra no If" <<endl;
                            soma += arest->getPesoAresta();
                            id_lista = arest->getIdLista();
                        }
                        //else if(arest->getIdLista() != noCluster[j].getId() && arest->getIdNo() == id_lista){
                          //  cout << "entra no Else If 1" <<endl;
                          //  soma += arest->getPesoAresta();
                          //  id_lista = arest->getIdLista();
                        //}

                         else if(arest->getIdLista() != noCluster[j].getId() && arest->getIdLista() == id_lista && noCluster[j].getId() == arest->getIdNo()){
                          //  cout << "entra no Else If 2" <<endl;
                            soma += arest->getPesoAresta();
                          //  cout << "Soma: " << soma <<endl;
                            flag = true;
                            break;
                        }

                        else if(arest->getIdLista() == noCluster[j].getId() && arest->getIdLista() == id_lista){
                          //  cout << "entra no Else If 3" <<endl;
                            soma += arest->getPesoAresta();
                         //   cout << "Soma: " << soma <<endl;
                            flag = true;
                            break;
                        }

                        else if(arest->getIdLista() == noCluster[j].getId() && arest->getIdNo() == id_lista){
                          //  cout << "entra no Else If 4" <<endl;
                            soma += arest->getPesoAresta();
                         //   cout << "Soma: " << soma <<endl;
                            flag = true;
                            break;
                        }
                       // cout << "Soma: " << soma <<endl;
                        a--;
                    }
                }
                a++;
            }
          }
      }


    }

return soma;

}
