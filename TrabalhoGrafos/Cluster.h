#ifndef CLUSTER_H_INCLUDED
#define CLUSTER_H_INCLUDED
#include "No.h"
#include "Aresta.h"
#include "Grafo.h"

class Cluster{

private:

    int idCentroide;
    float d_intra;

public:
    int nNos = 0;
    vector <No> noCluster;
    vector <Aresta> arestasCluster;
    vector <float> d_inter;
    float getD_intra(){return d_intra;};
    void setD_intra(float dintra){d_intra = dintra;};
    int getIdCentroide(){return idCentroide;};
    void setIdCentroide(int id){idCentroide = id;};
    int calculaDintra();

};

#endif // CLUSTER_H_INCLUDED
