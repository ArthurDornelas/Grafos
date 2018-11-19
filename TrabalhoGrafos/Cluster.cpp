int Cluster::calculaDintra()
{
    float soma=0;
    for(int i=0;i<arestasCluster.size();i++)
        soma+=noCluster[0].listaAresta[i].getPesoAresta();
    int num =getNnos()-1;
    return soma/num;
}
