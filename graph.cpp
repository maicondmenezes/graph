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
#include "graph.h"

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
vector <unsigned short int> Graph::getNeighbors( const unsigned short int& vertice){
  int iNeighbors = 0;
  vector <unsigned short int> neighbors;
  for (int i = 0; i < size; ++i){
    if (vertices[vertice][i] != 0) neighbors.push_back(i);
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

string Graph::toString(){
  ostringstream streamOut;
  int verticeCounter = 0;
  int neighborsCounter = 0;
  for(vector<double> way : vertices) {
    streamOut << setw(15) << getTag(verticeCounter) << "(" << verticeCounter << ") | " << endl;              
    for(double step : way){
      streamOut << setw(17) << getTag(neighborsCounter) << "(" << verticeCounter << ") | "
                << setw(17) << step << " | " << endl;
      ++neighborsCounter;
    }
    ++verticeCounter;
    streamOut << endl;
  }
  return streamOut.str();
}

//Função para comparar e retornar a menor aresta entre duas comparando seus
static bool compareEdge (Edge e, Edge f) { 
 return (e.cost < f.cost);
}

/* void Graph::sortEdges(vector<Edge> bagOfEdges, const bool crescent){
  if(crescent)
    //Ordena em ordem crescente as arestas por custo
    sort(bagOfEdges.begin(), bagOfEdges.end(), compareEdge);
  //Ordena em ordem crescente as arestas por custo
  sort(bagOfEdges.end(), bagOfEdges.begin(), compareEdge);

} */

//Metodos de caminho
//Encontra o subconjunto atual do vertice
short int findSet(vector<short int> subset, short int& vertice){
  if(subset[vertice] == -1) return vertice;
  return findSet(subset, subset[vertice]);
}
//Uni 2 subconjuntos
void joinSets(vector<short int> subset, short int& source, short int& destiny){
  short int sourceSet = findSet(subset, source);
  short int destinySet = findSet(subset, destiny);
  subset[sourceSet] = destinySet;
}
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

//Função que percorre todo grafo e devolve todas as arestes presentes no mesmo
//em forma de vetor
vector<Edge> Graph::getEdges(){
  vector<Edge> bagOfEdges;
  Edge thisEdge;
  for(int i = 0; i < size; ++i) {
    thisEdge.source = i;
    for(int j = 0; j < size; ++j){
      thisEdge.destiny = j;
      thisEdge.cost = getEdgeCost(i, j);
      bagOfEdges.push_back(thisEdge);
    }    
  }
  return bagOfEdges;
}
vector<Edge>  Graph::kruskal(){
  //Vetor que armazenará a arvore minima que será enviada como retorno da função
  vector<Edge> minimalTree;
  //Vetor de arestas para armazenar e reordenar as arestas do grafo
  vector<Edge> bagOfEdges;
  Edge thisEdge;
  bagOfEdges = getEdges();
  sort(bagOfEdges.end(), bagOfEdges.begin(), compareEdge);
  //Conjunto que ira controlar os vertices já inseridos na arvore
  vector<short int> forest (size, -1);
  //Enquanto o conjunto não possuir o mesmo numero de vertices do grafo continua
  //acrescentando o vertice origem das arestas a lista
  /* while( forest.size() < size){
    thisEdge = bagOfEdges.back();
    bagOfEdges.pop_back();
    forest.insert(thisEdge.source);
    minimalTree.push_back(thisEdge);
  } */
  for(Edge thisEdge: bagOfEdges){
    short int sourceSet = thisEdge.source;
    short int destinySet = thisEdge.destiny;
    if(sourceSet !=  destinySet){
      minimalTree.push_back(thisEdge);
      joinSets(forest, sourceSet, destinySet);
    }
  }
  return minimalTree;
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
