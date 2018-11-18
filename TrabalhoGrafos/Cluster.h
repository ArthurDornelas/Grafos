#ifndef CLUSTER_H_INCLUDED
#define CLUSTER_H_INCLUDED

class Cluster{

private:
    int nNos;
    int idCentroide;
    float d_intra;

public:
    vector <No> noCluster;
    vector <Aresta> arestasCluster;
    vector <float> d_inter;
    float getD_intra(){return d_intra;};
    void setD_intra(float dintra){d_intra = dintra;};
    int getIdCentroide(){return idCentroide;};
    void setIdCentroide(int id){idCentroide = id;};


};

#endif // CLUSTER_H_INCLUDED
