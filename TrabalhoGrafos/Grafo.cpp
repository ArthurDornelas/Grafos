#include <vector>


void Grafo::adcionarNo(int id, float pesoNo)
{
    No no = No();                               //adicionamos o no ao vetor dos vertices
    no.setId(id);
    listaAdj.push_back(no);
}

void Grafo::removerNo (int id)
{
    vector <No>::iterator it;                   //Nessa funcao percorremos o a lista de nos no primeiro for ate achar o valor, e depois apagar ele
    vector <Aresta>::iterator a;                //Nos dois proximos for queremos apagar a ligacao que o no deletado tinha com os outros , fazemos isso verificando se
                                                //com o if se existe ligacao e pagamos
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
                if(a->getIDNo() == id) {
                    listaAdj[i].listaAresta.erase( listaAdj[i].listaAresta.begin() + j );
                }
                j++;
        }
    }
}

int Grafo::ordemGrafo()
{
    return listaAdj.size();                 //a ordem do grafo E a quantidade de nos, entao vai ser o tamanho da lista desses.
}

bool Grafo::grafoCompleto()
{
    int n = ordemGrafo();                       //para verificar se o grafo E completo precisamos percorrer o vetor de arestas verificando o
    int num_Arestas = 0;                             //grau de cada no e verificar com o if se a soma de arestas da n*(n-1)
    for(int i = 0; i < n; i++) {
        num_Arestas += listaAdj[i].getGrau();
    }
    if(num_arestas == n*(n-1))
        return true;
    return false;

}

bool Grafo::grafoKRegularidade(int k)
{
    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it) { //para um grafo de k regularidade os nos precisam ter o mesmo grau K
                if(it->getGrau()!=k)                                                       // percorremos o vetor de nos verificando se algum nao tem K como grau
                                                                                            //e retornar verdadeiro ou falso caso nao tenha
                {
                    return false;
                }
    }
    return true;

}

void Grafo::vizinhacaAberta(int id)
{                                                                       //Para demonstrar a vizinhacaAberta so precisamos mostrar os nos que tem ligacao
    int i=0;                                                            // com o no principal, fazemos isso percorrendo o vetor de arestas do no desejado
    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it, i++) {
         if( it->getId() == id )
         {
            for(std::vector<Aresta>::iterator arest = listaAdj[i].listaAresta.begin(); arest != listaAdj[i].listaAresta.end(); ++a)
                cout << arest->getIdNo() << endl;
         }
    }
}

void Grafo::vizinhacaFechada(int id)
{
    int i=0;
    cout << id << endl;                                         //Para demonstrar a vizinhacaFechada so precisamos mostrar os nos que tem ligacao
    int i=0;                                                            // com o no principal, fazemos isso percorrendo o vetor de arestas do no desejado
                                                                    //e acrescentar  o no principal
    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it, i++) {
         if( it->getId() == id )
         {
            for(std::vector<Aresta>::iterator arest = listaAdj[i].listaAresta.begin(); arest != listaAdj[i].listaAresta.end(); ++a)
                cout << arest->getIdNo() << endl;
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
    for (std::vector<No>::iterator it = listaAdj.begin(); it != listaAdj.end(); ++it) { //percorremos o vetor dos vertices e exibimos o grau deles
            cout << it->getGrau() << " ";
    }
}


