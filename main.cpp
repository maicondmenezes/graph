#include <iostream>
#include <iomanip>
#include <algorithm>
#include "graph.h"
using namespace std;

static bool compareEdge (Edge e, Edge f) { 
    return (e.cost < f.cost);
}

int main(){
  Graph grafo(4);
  vector<int> caminho;
  grafo.setTag(0, "pelotas");
  grafo.setTag(1, "rio grande");
  grafo.setTag(2, "sao lourenco");
  grafo.setTag(3, "cangucu");

  grafo.makeEdgeBetween(0, 1, 3);
  grafo.makeEdgeBetween(0, 2, 8);
  grafo.makeEdgeBetween(0, 3, 10);
  grafo.makeEdgeBetween(1, 0, 3);
  grafo.makeEdgeBetween(1, 2, 5);
  grafo.makeEdgeBetween(2, 0, 8);
  grafo.makeEdgeBetween(3, 0, 10);
  vector<Edge> sacoDeArestas;
  sacoDeArestas = grafo.getEdges();
  
  system("clear");
  
  for(Edge aresta: sacoDeArestas){
    
    cout << setw(20) << grafo.getTag(aresta.source)  << "(" << aresta.source  << ") | "
         << setw(20) << grafo.getTag(aresta.destiny) << "(" << aresta.destiny << ") | "
         << setw(4) << aresta.cost    << " Km | "
         << endl;
  }
  
  //Ordena em ordem crescente as arestas por custo
  sort(sacoDeArestas.begin(), sacoDeArestas.end(), compareEdge);
  getchar();
  for(Edge aresta: sacoDeArestas){
    
    cout << setw(20) << grafo.getTag(aresta.source)  << "(" << aresta.source  << ") | "
         << setw(20) << grafo.getTag(aresta.destiny) << "(" << aresta.destiny << ") | "
         << setw(4) << aresta.cost    << " Km | "
         << endl;
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