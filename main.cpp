#include <iostream>
#include "graph.h"
//using namespace std;

int main(){
  Graph grafo(4);
  vector< vector<int> > caminho;
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

  caminho = grafo.findCloserWayBetween(1, 3);

  for(vector<int> linha: caminho){
    for(int coluna: linha){
      cout << coluna << " ";
    }
    cout << "\n";
  }
  

  system("pause");
  return 0;
}