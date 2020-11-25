/**
*#Universidade Federal de Pelotas#
*#Unidade: CDTEC
*#Curso: Engenharia da Computação
*#Disciplina: Algoritmos e Estruturas de Dados 2
*#Profº: Guilherme
*#Aluno: Maicon de Menezes
*#Projeto: Trabalho 2 - AED II - Grafos & Djsktra
*#Módulo: graph.cpp - implementação da classe

*@author Maicon de Menezes <mdmoliveira@inf.ufpel.edu.br>
*@orientator Guilherme
*@date 19/10/2020
*@link: http://www.facom.ufu.br/~flavio/ed1/files/C++%20ORIENTADO%20A%20OBJETOS.pdf
*/
//Bibliotecas
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <math.h>  
#include "graph.h"

using namespace std;

//Estrutura temporárria para armazenar e reorganizar as arestas do grafo
struct Edge {
  short int source;
  short int destiny;  
  double cost;
};

//Métodos Construtores
Graph::Graph(){

}
Graph::Graph( const unsigned short int& s ){
  vector<bool>           nStatus(s, opened);
  vector<string>         nTags(s, "");
  vector<short int>      nPredecessors(s, -1);
  vector<long double>    nEstimates(s, LDBL_MAX);
  vector<double>         neigbhors(s, 0);
  vector<vector<double>> nVertices(s, neigbhors);
  size         = s;
  status       = nStatus; 
  tags         = nTags;
  predecessors = nPredecessors;
  estimates    = nEstimates;
  vertices     = nVertices;
  
}
//Destrutores
  Graph::~Graph(){
    size = 0;
  }
//Modificadores
/* Cria uma aresta armazenando um valor diferente de maior que zero ('cost') 
na coluna 'destiny' da linha 'source' da matriz 'vertices' */
void Graph::makeEdgeBetween(const unsigned short int& source, const unsigned short int& destiny, const double& cost){
  vertices[source][destiny] = cost;
}

/* Altera o status atual do vertice, alternando entre os valores booleanos do 
vetor de status */
void Graph::setStatus(const unsigned short int& vertice){
  status[vertice] = !status[vertice];
}

/* Indica o antecessor do vertice em questão atribuindo o valor inteiro 
'predecessor' ao vetor de predecessores no índice 'vertice' */
void Graph::setPredecessor(const unsigned short int& vertice, const unsigned short int& predecessor){
  predecessors[vertice] = predecessor;
}

/* Altera o valor da estimativa de custo do menor caminho para o vertice em 
questão atribuindo o valor real 'estimate' ao vetor 'estimates' no índice 
'vertice', garantindo que o valor é maior que 0*/
void Graph::setEstimate(const unsigned short int& vertice, const double& estimate){
  if (estimate > 0) estimates[vertice] = estimate;
}

/* Adiciona uma etiqueta de identificação no vertice, atribuindo uma string 
'tag' ao vetor 'tags' no índice 'vertice' */
void Graph::setTag(const unsigned short int& vertice, const string tag){
  tags[vertice] = tag;
}

//Acessores

/* Retorna um vetor com todos vizinhos do vértice em questão */
unsigned short int * Graph::getNeighbors( const unsigned short int& vertice){
  int iNeighbors = 0;
  static unsigned short int neighbors[] = {};
  for (int i = 0; i < size; ++i){
    if (vertices[vertice][i] != 0) neighbors[iNeighbors++] = i;
  }
  return neighbors;
}

/* Retorna o custo de uma aresta que inicia no vertice 'source' e termina no 
vertice 'destiny' */
double Graph::getEdgeCost(const unsigned short int& source, const unsigned short int& destiny){
  return vertices[source][destiny];
}

/* Retorna o status atual do vertice em questão */
bool Graph::getStatus(const unsigned short int& vertice){
  return status[vertice];
}

/* Retorna o antecessor do vertice em questão */
unsigned short int Graph::getPredecessor( const unsigned short int& vertice ){
  return predecessors[vertice];
}

/* Retorna a estimativa de custo do vertice em questão */
double Graph::getEstimate( const unsigned short int& vertice ){
  return estimates[vertice];
}

string Graph::getTag( const unsigned short int& vertice ){
  return tags[vertice];
}


void Graph::print(){
  for(vector<double> way : vertices) {    
    for(double step : way){
      cout << setw(5);
      cout << step << " ";
    }
    cout << "\n";
  }
}

//Metodos de caminho

void Graph::estimateDistance( const unsigned short int& source, const unsigned short int& destiny){
  if (estimates[destiny] > estimates[source] + vertices [source][destiny]){
    estimates[destiny] = estimates[source] + vertices [source][destiny];
    predecessors[destiny] = source;
  }
}

bool Graph::thereIsOpenedVertice(){
  for(int i = 0; i < size; ++i){
    if (!status[i]) return closed;    
  }
  return opened;
}

unsigned short int Graph::nextOpenedVertice(){
  for(int i = 0; i < size; ++i){
    if(!status[i]) return i;
  }
  return -1;
}

unsigned short int Graph::smallestEstimate(){
  if(nextOpenedVertice() == -1) return -1;  
  int smaller = nextOpenedVertice(); 
  for(int i = smaller+1; i < size; ++i){
    if (!status[i] && estimates[smaller] > estimates[i]) smaller = i;
  }
  return smaller;
}

void Graph::dijikstra(const unsigned int& source){
  estimates[source] = 0;
  while(thereIsOpenedVertice()){    
    int thisVertice = smallestEstimate();
    setStatus(thisVertice);
    for(int neighbor = 0; neighbor < size; ++neighbor){
     if(getEdgeCost(thisVertice, neighbor) > 0)
       estimateDistance(thisVertice, neighbor);
    }
  }
}


//Função para comparar e retornar a menor aresta entre duas comparando seus
bool Graph::compareEdge (Edge e, Edge f) { return (e.cost < f.cost); }

vector<vector<short int>>  Graph::kruskal(){
  //Matriz que armazenará a arvore minima que será enviada como retorno da função
  vector<vector<short int>> minimalTree;
  //Criando um vetor de arestas para armazenar e reordenar as arestas do grafo
  Edge edges;
  int maxAmountOfEdges = pow(size, 2);
  vector<short int> bagOfEdges(maxAmountOfEdges, edges);
  Edge thisEdge;
  //Armazenando as arestas 
  for(int i = 0; i < size; ++i) {
    thisEdge.source = i;
    for(int j = 0; j < size; ++j){
      thisEdge.destiny = j;
      thisEdge.cost = getEdgeCost(i, j);
      bagOfEdges.push_back(thisEdge);
    }    
  }
  sort(bagOfEdges.end(), bagOfEdges.begin(), compareEdge );
  while(!bagOfEdges.empty()){
    
  }
}



vector<int> Graph::findCloserWayBetween(const unsigned short int& source, const unsigned short int& destiny){
  unsigned short int thisVertice = destiny;
  unsigned short int i = 0;
  vector<int> way;
  dijikstra(source);
//Percorre o caminho do destino até a fonte através 
//do antecessor do vértice atual
  do{
    way.insert(way.begin(), thisVertice);    
    thisVertice = getPredecessor(thisVertice);
  }while(thisVertice != source);
  way.insert(way.begin(), source);
  return way;
}
