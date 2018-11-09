No::No(int ident, int grauNo)
{
    id = ident;
    grau = grauNo;
    vector <Aresta> listaAresta;
}

No::~No()
{

}

void No::setGrau(int grauNo)
{
    grau = g;
}

int No::getGrau()
{
    return grau;
}

void No::setId(int ident)
{
    id = ident;
}

int No::getId() ()
{
    return iD;
}

float No::getAresta(int i){
    return listaAresta[i].getIdNo();
}

void No::adicionaAresta(int ident, float pesoAresta){
    Aresta aresta =  Aresta(ident,pesoAresta);
    if(ident == id)
        grau += 2;
    else
        grau += 1;
    listaAresta.push_back(aresta);
}

void No::removeAresta(int ident)
{
    if(ident == id)
        grau -= 2;
    else
        grau -= 1;
}

