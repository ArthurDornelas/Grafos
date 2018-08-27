#include "GrafoMA.h"

GrafoMA::GrafoMA(int v)
{
    n = v;
    mat = new float*[n];

    for(int i = 0; i < n; i++)
        mat[i] = new float[n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j<n; j++)
                mat[i][j] = 0;
    }
}

GrafoMA::~GrafoMA()
{
    for(int i = 0; i < n; i++)
        delete [] mat[i];
    delete [] mat;
}

void GrafoMA::addAresta(int vert1, int vert2)
{
    mat[vert1][vert2] = 1;
    mat[vert2][vert1] = 1;
}

void GrafoMA::addVertice()
{
    float **matriz;
    matriz = new float*[n];

    for(int i = 0; i < n; i++)
        matriz[i] = new float[n];

    for(int i = 0; i < n-1; i++)
        for(int j = 0; j<n-1; j++)
            matriz[i][j] = mat[i][j];

    n=n++;

    mat = new float*[n];

    for(int i = 0; i < n; i++)
        mat[i] = new float[n];

    int i=n-1;

    for(int j = 0; j<n; j++)
        mat[i][j] = 0;

    for(int j = 0; j<n; j++)
        mat[j][i] = 0;

    for(int i = 0; i < n-1; i++)
        for(int j = 0; j<n-1; j++)
            mat[i][j] = matriz[i][j];

}

void GrafoMA::excluiAresta(int vert1, int vert2)
{
    mat[vert1][vert2] = 0;
    mat[vert2][vert1] = 0;
}

void GrafoMA::excluiVertice(int v)
{

        delete mat[v];

}

int GrafoMA::grauVertice(int v)
{
    int grau = 0;

    for(int j = 0; j<n; j++)
    {
        if(mat[v][j] == 1)
            grau++;
    }
    return grau;
}
