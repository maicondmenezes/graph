#include <iostream>
#include <iomanip>
#include <algorithm>
#include "graph.h"
using namespace std;

static bool compareEdge (Edge e, Edge f) { 
    return (e.cost < f.cost);
}

int main(){
  Graph grafo(9);
  vector<int> caminho;
  grafo.setTag(0, "a");
  grafo.setTag(1, "b");
  grafo.setTag(2, "c");
  grafo.setTag(3, "d");
  grafo.setTag(4, "e");
  grafo.setTag(5, "f");
  grafo.setTag(6, "g");
  grafo.setTag(7, "h");
  grafo.setTag(8, "i");


  grafo.makeEdgeBetween(0, 1, 4);
  grafo.makeEdgeBetween(0, 7, 8);
  grafo.makeEdgeBetween(1, 0, 4);
  grafo.makeEdgeBetween(1, 2, 8);
  grafo.makeEdgeBetween(1, 7, 11);
  grafo.makeEdgeBetween(2, 1, 8);
  grafo.makeEdgeBetween(2, 3, 7);
  grafo.makeEdgeBetween(2, 5, 4);
  grafo.makeEdgeBetween(2, 8, 2);
  grafo.makeEdgeBetween(3, 2, 7);
  grafo.makeEdgeBetween(3, 4, 9);
  grafo.makeEdgeBetween(3, 5, 14);
  grafo.makeEdgeBetween(4, 3, 9);
  grafo.makeEdgeBetween(4, 5, 10);
  grafo.makeEdgeBetween(5, 2, 4);
  grafo.makeEdgeBetween(5, 3, 14);
  grafo.makeEdgeBetween(5, 4, 10);
  grafo.makeEdgeBetween(5, 6, 2);
  grafo.makeEdgeBetween(6, 5, 2);
  grafo.makeEdgeBetween(6, 7, 1);
  grafo.makeEdgeBetween(6, 8, 6);
  grafo.makeEdgeBetween(7, 0, 8);
  grafo.makeEdgeBetween(7, 1, 11);
  grafo.makeEdgeBetween(7, 6, 1);
  grafo.makeEdgeBetween(7, 8, 7);
  grafo.makeEdgeBetween(8, 2, 2);
  grafo.makeEdgeBetween(8, 6, 6);
  grafo.makeEdgeBetween(8, 7, 7);
  
  vector<Edge> sacoDeArestas;
  sacoDeArestas = grafo.getEdges();
  
  system("clear");
  int contadorDeArestas = 0;
  for(Edge aresta: sacoDeArestas){
    if(grafo.getEdgeCost(aresta.source, aresta.destiny)!=0){
      cout << setw(4) << grafo.getTag(aresta.source)  << "(" << aresta.source  << ") | "
         << setw(4) << grafo.getTag(aresta.destiny) << "(" << aresta.destiny << ") | "
         << setw(4) << aresta.cost    << " Km | "
         << endl;
      ++contadorDeArestas;
    }
        
  }
  cout << contadorDeArestas;
  getchar();
  sacoDeArestas = grafo.kruskal();
   
  for(Edge aresta: sacoDeArestas){
    if(grafo.getEdgeCost(aresta.source, aresta.destiny)!=0){
      cout << setw(4) << grafo.getTag(aresta.source)  << "(" << aresta.source  << ") | "
         << setw(4) << grafo.getTag(aresta.destiny) << "(" << aresta.destiny << ") | "
         << setw(4) << aresta.cost    << " Km | "
         << endl;
    }    
  }
  
  /* grafo.print();

  caminho = grastatic bool                      compareEdge (Edge, Edge);fo.findCloserWayBetween(1, 3);
  

 for(int passo: caminho){
  cout << setw(5);
  cout << passo << " ";
 }
 cout << endl; */
  getchar();  
  system("clear");
  return 0;
}