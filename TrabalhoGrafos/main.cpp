#include <iostream>
#include "Grafo.h"
#include "Grafo.cpp"
#include "Menu.h"
using namespace std;

int main() {
    /*
    Pra ler Um dígrafo é só chamar essa funćão, com o nome do arquivo como parâmetro
        Grafo* grafo = new Grafo();
        grafo->lerDigrafo("teste.txt");
        grafo->removerNo(1);
        grafo->imprimiGrafo();
    */




    cout<< "teste" << endl;
    Grafo* grafo = new Grafo();
    grafo->adicionarNo(1);
    grafo->adicionarNo(2);
    grafo->adicionarNo(3);
    grafo->adicionarNo(4);
    grafo->adicionarNo(5);
    grafo->adicionarNo(6);
    grafo->adicionarNo(7);
    grafo->imprimiGrafo();
    cout<< endl;


    //if(grafo->estaNoGrafo(1) == true)
      //  cout << "Esta no grafo";
    //else
    //    cout << "Nao Esta";
   // cout << endl;

    grafo->adicionarArestaNos(1,2,7);
    grafo->adicionarArestaNos(1,4,5);
    grafo->adicionarArestaNos(2,4,9);
     grafo->adicionarArestaNos(2,5,7);
      grafo->adicionarArestaNos(3,5,5);
       grafo->adicionarArestaNos(4,5,15);
        grafo->adicionarArestaNos(4,6,6);
         grafo->adicionarArestaNos(5,6,8);
          grafo->adicionarArestaNos(5,7,9);
           grafo->adicionarArestaNos(6,7,11);

    /*
    Pra ler Um dígrafo é só chamar essa funćão, com o nome do arquivo como parâmetro
        Grafo* grafo = new Grafo();
        grafo->lerDigrafo("teste.txt");
        grafo->removerNo(1);
        grafo->imprimiGrafo();
    */



    cout<< "teste" << endl;
    Grafo* grafo = new Grafo();
    grafo->adicionarNo(1);
    grafo->adicionarNo(2);
    grafo->adicionarNo(3);
    grafo->adicionarNo(4);
    grafo->adicionarNo(5);
    grafo->adicionarNo(6);
    grafo->adicionarNo(7);



    grafo->imprimiGrafo();
    cout<< endl;


    //if(grafo->estaNoGrafo(1) == true)
      //  cout << "Esta no grafo";
    //else
    //    cout << "Nao Esta";
   // cout << endl;

    grafo->adicionarArestaNos(1,2,7);
    grafo->adicionarArestaNos(1,4,5);
    grafo->adicionarArestaNos(2,4,9);
    grafo->adicionarArestaNos(2,3,8);
     grafo->adicionarArestaNos(2,5,7);
      grafo->adicionarArestaNos(3,5,5);
       grafo->adicionarArestaNos(4,5,15);
        grafo->adicionarArestaNos(4,6,6);
         grafo->adicionarArestaNos(5,6,8);
          grafo->adicionarArestaNos(5,7,9);
           grafo->adicionarArestaNos(6,7,11);


   // grafo->adicionarArestaNos(2,4,1);

    grafo->imprimiGrafo();
    cout<<endl;

    //grafo->algoritmoPrim();
    grafo->clusterizacaoGuloso();

    //if(grafo->vizinho(1,2) == true)
      //  cout << "Thats It";
    //else
      //  cout << "Oh fuck";

      /*grafo->removeAresta(1,2);
      grafo->imprimiGrafo();
      cout << grafo->retornaGrauNo(1) << endl;
      cout << grafo->retornaGrauNo(2) << endl;
      cout << grafo->retornaGrauNo(3) << endl;
      cout << grafo->retornaGrauNo(4) << endl;
      cout<<endl;
      cout << grafo->ordemGrafo() << endl;
      cout<<endl;
      cout << grafo->ordemGrafo() << endl;
      cout<<endl;
      grafo->vizinhancaAberta(1);
      cout<<endl;
      grafo->sequenciaGraus();
      cout<<endl;
      cout<<endl;
      if(grafo->grafoCompleto() == true)
        cout << "Completo";
      else
        cout << "Nao Completo";
      cout<<endl;
      cout<<endl;
       grafo->adicionarArestaNos(1,2,0);
        grafo->adicionarArestaNos(4,2,5);
         grafo->adicionarArestaNos(4,1,5);
             grafo->adicionarArestaNos(1,3,5);
             grafo->adicionarArestaNos(4,3,5);
      if(grafo->grafoCompleto() == true)
        cout << "Completo";
      else
        cout << "Nao Completo";
      cout<<endl;
      cout<<endl;

    cout << "Teste do menu" << endl;

    Menu* menu = new Menu(grafo);
    menu->inicia();

    */
}
