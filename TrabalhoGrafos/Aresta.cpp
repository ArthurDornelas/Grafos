Aresta::Aresta(int id,float peso)
{
    identNo = id;
    pesoAresta = peso;
}

void Aresta::setPesoAresta(float peso)
{
    pesoAresta = peso;
}

float Aresta::getPesoAresta()
{
    return pesoAresta;
}

int Aresta::getIdNo()
{
    return identNo;
}

int Aresta::setIdNo(int id)
{
    identNo = id;
}
