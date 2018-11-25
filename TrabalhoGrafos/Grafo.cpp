#include "Grafo.h"
#include "No.h"
#include "No.cpp"
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 9999999;
using namespace std;
#include "Cluster.h"
#include "Cluster.cpp"

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
    for(it = listaAdj.begin() ; it != listaAdj.end(); ++it, i++ )
    {
        if ( it->getId() == id )
        {
            listaAdj.erase( listaAdj.begin() + i  );
        }
    }
    i =0;
    for(it = listaAdj.begin(); it != listaAdj.end(); ++it,i++)
    {
        j = 0;
        for(std::vector<Aresta>::iterator a = listaAdj[i].listaAresta.begin(); a != listaAdj[i].listaAresta.end() && j < listaAdj[i].listaAresta.size() ;   ++a)
        {
            if(a->getIdNo() == id)
            {
                listaAdj[i].listaAresta.erase( listaAdj[i].listaAresta.begin() + j );
            }
            j++;
        }
    }
}

void Grafo::removeAresta(int id1,int id2)
{
    if(estaNoGrafo(id1) && estaNoGrafo(id2))
    {
        if(vizinho(id1,id2))
        {
            for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
            {
                if( it->getId() == id1 )
                    it->removeAresta(id2);
                if( it->getId() == id2)
                    it->removeAresta(id1);
            }
        }

    }
    else
    {
        cout << "Um ou mais NOS nao existem, impossivel remover a ARESTA." << endl;
    }

}

void Grafo::adicionarArestaNos(int id, int id2,int peso)
{

    if(estaNoGrafo(id) == true)
    {

        if(estaNoGrafo(id2) == true)
        {

            for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
            {

                if(id != id2)
                {
                    if(it->getId() == id)
                    {
                        it->adicionaAresta(id2,peso,id);
                    }

                    if(it->getId() == id2)
                    {
                        it->adicionaAresta(id,peso,id2);
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
    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
        if( it->getId() == i )
        {
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

    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
        if( it->getId() == id )
        {
            return it->getGrau();
        }
    }
    cout << "Nao existe esse NO no Grafo."<<endl;

}

bool Grafo::vizinho(int id1, int id2)
{
    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
        if(it->getId() == id1 )
        {
            return it->eVizinho(id2);
        }
        if(it->getId() == id2 )
        {
            return it->eVizinho(id1);
        }
    }
    return false;
}

bool Grafo::grafoCompleto()
{
    int n = ordemGrafo();
    int num_Arestas = 0;
    for(int i = 0; i < n; i++)
    {
        num_Arestas += listaAdj[i].getGrau();
    }
    if(num_Arestas == n*(n-1))
        return true;
    return false;

}

bool Grafo::grafoKRegularidade(int k)
{
    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
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
    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it, i++)
    {
        if( it->getId() == id )
        {
            if(it->listaAresta.size() >= 1)
            {
                for(std::vector<Aresta>::iterator arest = listaAdj[i].listaAresta.begin(); arest != listaAdj[i].listaAresta.end(); ++arest)
                    std::cout << arest->getIdNo() << std::endl;
                break;
            }
            else
            {
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
    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it, i++)
    {
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
    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
        std::cout << "No " << it->getId() << " - " << it->getGrau() << "  ";
    }
}


void Grafo::algoritmoPrim()
{
    int posListaAdj = 0;
    int cont = 0;
    arvore.push_back(listaAdj[0]);

    while(arvore.size() != listaAdj.size())
    {

        int menor = INF;
        int idNo = -1;
        int arestaMenor = -1;
        int posNoArvoreMenor = -1; //posicao que está o nó que contem a menor aresta

        //for que roda os nós que já estão na árvore
        int posArvore = 0; // posicao atual da arvore
        for(std::vector<No>::iterator arv = arvore.begin(); arv != arvore.end(); ++arv)
        {

            //loop para ver qual a menor aresta
            int contAresta = 0; //posicao atual da aresta
            for(std::vector<Aresta>::iterator arest = arvore[posArvore].listaAresta.begin(); arest != arvore[posArvore].listaAresta.end(); ++arest)
            {
                // Verifica se é um ciclo ou não
                bool ciclo = false;
                if(arvore.size() > 0)
                {
                    for(std::vector<No>::iterator noArv = arvore.begin(); noArv != arvore.end(); ++noArv)
                    {

                        if(arest->getIdNo() == noArv->getId())
                        {
                            ciclo = true;
                            break;
                        }
                    }
                }
                // Se nao for ciclo, entra neste IF, se for ele apenas troca para a proxima aresta
                if (ciclo == false)
                {

                    if(arest->getPesoAresta() < menor)
                    {
                        menor = arest->getPesoAresta(); //recebe o peso da aresta
                        arestaMenor = contAresta;
                        posNoArvoreMenor = posArvore;
                    }
                }
                contAresta++;
            }
            posArvore++;
        }

        idNo = arvore[posNoArvoreMenor].listaAresta[arestaMenor].getIdNo();
        int i = 0;
        for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
        {
            if(idNo == it->getId())
            {
                posListaAdj = i;
                arvore.push_back(listaAdj[i]);
                arestasArvore.push_back(arvore[posNoArvoreMenor].listaAresta[arestaMenor]);
                break;
            }
            i++;
        }
        cont++;
    }

    for (std::vector<No>::iterator no = arvore.begin(); no != arvore.end(); ++no)
    {
        cout << no->getId() << "  ";
    }
    cout << endl;

    for (std::vector<Aresta>::iterator aresta = arestasArvore.begin(); aresta != arestasArvore.end(); ++aresta)
    {
        cout << aresta->getIdLista() << " -> " << aresta->getIdNo() << "  ";
    }
    cout<<endl;
}

void Grafo::imprimiGrafo()
{
    for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
    {
        int j=0;
        std::cout << it->getId();
        for(std::vector <Aresta>::iterator arest = it->listaAresta.begin(); arest != it->listaAresta.end(); arest++,j++)
        {
            std::cout << " -> " << it->listaAresta[j].getIdNo();
        }
        std::cout << std::endl;
    }
}

void Grafo::criaCluster(No no)
{
    cout<<"Entrou criaCluster"<<endl;
    Cluster c = Cluster();
    c.setIdCentroide(no.getId());
    c.noCluster.push_back(no);
    clusters.push_back(c);
    c.nNos++;
}

void Grafo::clusterizacaoGuloso()
{
    algoritmoPrim(); //roda algoritmo de Prim para se ter a arvore geradora minima.

    //Inicializa dois nós como os primeiros centroides, fazendo k=2 (esses dois nós tem que se ligar no agoritmo de Prim,
    //para que se possa deletar uma aresta e formar duas arvores, ou seja, dois clusters.

    std::vector<No>::iterator arv = arvore.begin();//Seleciona-se o primeiro Nó da árvore
    int i = 0;
    cout<<"Selecionando 1 no arvore"<<endl;
    while(arv->getGrau() <= 1)//Verifica se o Nó não é de grau 1.
    {
        cout<<"Entrou while"<<endl;
        i++;
        ++arv;//se for muda para o proximo.
    }


    for(std::vector<No>::iterator noArv = (arv+1) ; noArv != arvore.end(); ++noArv) //Agora seleciona qual Nó da arvore se liga ao primeiro Nó escolhido.
    {
        bool flag = false;
        cout<<"selecionou o no "<<noArv->getId()<<endl;
        cout<<"entrou vetor noArv"<<endl;
        if(noArv->getGrau() > 1)
        {
            cout<<"Grau maior que 1"<<endl;
            int arestaAtual = 0;
            for(std::vector<Aresta>::iterator arest = arestasArvore.begin(); arest != arestasArvore.end(); ++arest)
            {
                cout<<"Entrou for aresta"<<endl;
                cout<<"Grau No arv "<<arv->getId()<<endl;
                if(arest->getIdLista() == arv->getId() && arest->getIdNo() == noArv->getId())
                {
                    cout<<"entrou if tirar aresta"<<endl;
                    criaCluster(*arv);
                    criaCluster(*noArv);
                    cout<<"copia auxAresta"<<endl;
                    auxArestasArvore = arestasArvore;
                    auxArestasArvore.erase(auxArestasArvore.begin() + arestaAtual);
                    for (std::vector<Aresta>::iterator aresta = auxArestasArvore.begin(); aresta != auxArestasArvore.end(); ++aresta)
                    {
                        cout << aresta->getIdLista() << " -> " << aresta->getIdNo() << "  ";
                    }
                    cout<<endl;
                    alocaNosClusters();
                    cout<<endl;
                    separaArestasClusters();
                    flag = true;
                    break;
                }
                arestaAtual++;
            }
        }
        if(flag==true)
            break;
    }

}



void Grafo::alocaNosClusters()
{

    int j=0,i=0,k=0, l, m;
    for(std::vector<Cluster>::iterator clust = clusters.begin(); clust != clusters.end(); ++clust)
    {

        j = 0;

        for(std::vector<No>::iterator no = clusters[i].noCluster.begin(); j < clusters[i].noCluster.size(); ++no)
        {

            bool flag = false;
            l=0;
            int lAtual=0;
            k=0;
            while(k <= auxArestasArvore.size())
            {

                if(clusters[i].noCluster[j].getId() == auxArestasArvore[k].getIdLista() /*|| clusters[i].noCluster[j].getId() == auxArestasArvore[k].getIdNo()*/)
                {

                    m=0;
                    if(l<1)
                    {
                        for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
                        {

                            if(it->getId() != clusters[i].noCluster[j].getId())
                            {

                                if(it->getId() == auxArestasArvore[k].getIdLista() || it->getId() == auxArestasArvore[k].getIdNo())
                                {
                                    clusters[i].noCluster.push_back(*it);
                                    flag == true;
                                    k++;
                                    lAtual = m;
                                    l++;
                                    break;
                                }
                            }
                            m++;
                        }
                    }
                    else
                    {

                        for(std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it)
                        {

                            if(m > lAtual)
                            {
                                if(it->getId() != clusters[i].noCluster[j].getId())
                                {
                                    if(it->getId() == auxArestasArvore[k].getIdLista() || it->getId() == auxArestasArvore[k].getIdNo())
                                    {
                                        clusters[i].noCluster.push_back(*it);
                                        flag == true;
                                        k++;
                                        lAtual = m;
                                        l++;
                                        break;
                                    }
                                }
                            }

                            m++;
                        }

                    }
                }

                k++;
            }
            j++;
        }
        i++;
    }


    for(std::vector<Cluster>::iterator clus = clusters.begin(); clus != clusters.end(); ++clus)
    {
        cout<<"imprimi"<<endl;
        for(std::vector<No>::iterator it = clus->noCluster.begin(); it != clus->noCluster.end(); ++it)
        {
            cout<<it->getId()<< "  ";
        }
        cout<<endl;
    }

    calculaDInter(4);
}

void Grafo::moveCentroide(int indexClust)
{
    int centroideId = clusters[indexClust].getIdCentroide();
    float menorSoma = -1;
    int dIntra = -1;
     //cout<<"Antigo Centroide " << centroideId << endl;

    for(int i=0 ; i < clusters[indexClust].noCluster.size() ; i++){
        if(clusters[indexClust].noCluster[i].getId() == centroideId)
            menorSoma =  clusters[indexClust].calculaDintra(clusters[indexClust].noCluster[i].getId());
    }

    for(int i=0 ; i < clusters[indexClust].noCluster.size() ; i++){
       dIntra = clusters[indexClust].calculaDintra(clusters[indexClust].noCluster[i].getId());
       if(dIntra < menorSoma){
          menorSoma = dIntra;
          centroideId = clusters[indexClust].noCluster[i].getId();
       }
    }

    //cout<<"Novo Centroide " << centroideId << endl;

}

void Grafo::separaArestasClusters()
{
    int i=0, j=0, k=0;

    for(std::vector<Cluster>::iterator clust = clusters.begin(); clust != clusters.end(); ++clust)
    {
        j=0;
        for(std::vector<Aresta>::iterator aresta = auxArestasArvore.begin(); aresta != auxArestasArvore.end(); ++aresta)
        {
            j=0;
            for(std::vector<No>::iterator no = clusters[i].noCluster.begin(); j < clusters[i].noCluster.size(); ++no)
            {

                if(aresta->getIdNo() == clusters[i].noCluster[j].getId() || aresta->getIdLista() == clusters[i].noCluster[j].getId())
                {
                    clusters[i].arestasCluster.push_back(*aresta);
                    break;
                }
                j++;
            }

        }
        i++;
    }



    i=0;
    for(std::vector<Cluster>::iterator clust = clusters.begin(); clust != clusters.end(); ++clust)
    {
        for (std::vector<Aresta>::iterator aresta = clusters[i].arestasCluster.begin(); aresta != clusters[i].arestasCluster.end(); ++aresta)
        {
            cout << aresta->getIdLista() << " -> " << aresta->getIdNo() << "  ";
        }
        cout<<endl;
        i++;
    }

    moveCentroide(0);

}

void Grafo::calculaDInter(int idNo){

    int k=0; // posicao do idNo no vetor Arvore
    for(int i=0;i<arvore.size();i++){
        if(arvore[i].getId()==idNo){
            k=i;
         break;
        }
    }
    int a = -1;
    int id_lista = -1;
    bool flag = false;
    float soma = 0;
    int idCentroide= -1;
    int i = 0; // posicao no vetor clusters
    for(std::vector<Cluster>::iterator clust = clusters.begin(); clust != clusters.end(); ++clust){
        idCentroide = clust->getIdCentroide();
        soma=0;

        ///////////////////////////////////////// Verifica posicao do Centroide na Arvore
        int c=0; // posicao do centroide no vetor Arvore
        for(int i=0;i<arvore.size();i++){
            if(arvore[i].getId()==idCentroide){
                c=i;
            break;
            }
        }
        //////////////////////////////////////////

        ///////////////////////////////////////// Roda as arestas da Arvore

        if(k < c){ // Verifica se a posicao do No esta antes ou depois do Centroide no vector Arvore

                a = 0; //posicao atual da aresta no vector
                for (std::vector<Aresta>::iterator aresta = arestasArvore.begin(); aresta != arestasArvore.end(); ++aresta){
                    //cout << "Entra vetor 1 Aresta" << endl;
                    if(aresta->getIdNo() == idCentroide){
                        id_lista = idCentroide;
                        //cout << "aresta get idNo" << aresta->getIdNo() <<endl;

                        for (std::vector<Aresta>::iterator arest = aresta; arest->getIdNo() != idNo || a >=0 ; --arest){
                            //cout << "aresta 2 get idNo" << arest->getIdNo() <<endl;
                            //cout << "id lista " << id_lista <<endl;
                            if(arest->getIdLista() != idNo && arest->getIdNo() == id_lista){
                                // cout << "entra no If" <<endl;
                                soma += arest->getPesoAresta();
                                id_lista = arest->getIdLista();
                            }

                            else if(arest->getIdLista() == idNo && arest->getIdNo() == id_lista){
                            //  cout << "entra no Else If" <<endl;
                                soma += arest->getPesoAresta();
                            //  cout << "Soma: " << soma <<endl;
                                flag = true;
                                break;
                            }
                            else if(arest->getIdLista() != idNo && arest->getIdNo() == idNo){
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

        else if(k == c) {
                cout << "entrou no else if"<<endl;
                soma = 0;
        }

        else {

            a = 0;
            for (std::vector<Aresta>::iterator aresta = arestasArvore.begin(); aresta != arestasArvore.end(); ++aresta){
                // cout << "Entra vetor 1 Aresta" << endl;
                if(aresta->getIdNo() == idNo){
                    id_lista = aresta->getIdNo();
                   // cout << "aresta get idNo" << aresta->getIdNo() <<endl;

                    for (std::vector<Aresta>::iterator arest = aresta; arest->getIdNo() != idCentroide || a >=0 ; --arest){
                       // cout << "aresta 2 get idNo " << arest->getIdNo() <<endl;
                       // cout << "aresta 2 get idLista " << arest->getIdLista() <<endl;
                       // cout << "id lista " << id_lista <<endl;
                        if(arest->getIdLista() != idCentroide && arest->getIdNo() == id_lista && idCentroide != arest->getIdNo()){
                          //  cout << "entra no If" <<endl;
                            soma += arest->getPesoAresta();
                            id_lista = arest->getIdLista();
                        }
                        //else if(arest->getIdLista() != noCluster[j].getId() && arest->getIdNo() == id_lista){
                          //  cout << "entra no Else If 1" <<endl;
                          //  soma += arest->getPesoAresta();
                          //  id_lista = arest->getIdLista();
                        //}

                         else if(arest->getIdLista() != idCentroide && arest->getIdLista() == id_lista && idCentroide == arest->getIdNo()){
                          //  cout << "entra no Else If 2" <<endl;
                            soma += arest->getPesoAresta();
                          //  cout << "Soma: " << soma <<endl;
                            flag = true;
                            break;
                        }

                        else if(arest->getIdLista() == idCentroide && arest->getIdLista() == id_lista){
                          //  cout << "entra no Else If 3" <<endl;
                            soma += arest->getPesoAresta();
                         //   cout << "Soma: " << soma <<endl;
                            flag = true;
                            break;
                        }

                        else if(arest->getIdLista() == idCentroide && arest->getIdNo() == id_lista){
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
        //////////////////////////////////////////////////////////////////
        cout<<soma<<endl;
       arvore[i].dInter.push_back(soma);
    }

    for(int j = 0; j<arvore[i].dInter.size() ; j++){
            cout << "Cluster 1 -- dInter = " << arvore[i].dInter[j]<<endl;

    }

}



/*void Grafo::lerDigrafo(string caminho)
{
    ifstream arquivo;
    int id_no_1, id_no_2;
    float peso_aresta;
    arquivo.open(caminho);
    if (arquivo.is_open())
    {
        while(arquivo >> id_no_1 >> id_no_2 >> peso_aresta)
        {

            if( !this->estaNoGrafo(id_no_1) )
            {
                this->adicionarNo(id_no_1);
            }
            if( !this->estaNoGrafo(id_no_2) )
            {
                this->adicionarNo(id_no_2);
            }
            this->adicionarArestaNos(id_no_1, id_no_2, peso_aresta);

        }
    }
}
*/
