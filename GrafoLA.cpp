#include "GrafoLA.h"

#include <list>



GrafoLA::GrafoLA(int vertices)
{
    vert = vertices;
    listAdj = new list<int>[vert];
}


void GrafoLA::addAresta(int vert1 , int vert2)
{
    listAdj[vert1].push_back(vert2);
    listAdj[vert2].push_back(vert1);
}


void GrafoLA::addVertice()
{
    it = listAdj->end();
    ++it;
    listAdj->insert(it,vert++);
    vert = vert++;
}

void GrafoLA::excluiAresta(int vert1 , int vert2)
{
    listAdj[vert1].remove(vert2);
    listAdj[vert2].remove(vert1);
}

void GrafoLA::excluiVertice(int v)
{
    it = listAdj->begin();
    advance(it,v);
    it = listAdj->erase(it);

}

int GrafoLA::grauVertice(int v)
{
	return listAdj[v].size();
}
