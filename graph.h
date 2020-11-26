/**
*#Universidade Federal de Pelotas#
*#Unidade: CDTEC
*#Curso: Engenharia da Computação
*#Disciplina: Algoritmos e Estruturas de Dados 2
*#Profº: Guilherme
*#Aluno: Maicon de Menezes
*#Projeto: Trabalho 2 - AED II - Grafos & Djsktra
*#Módulo: graph.h -  definições da classe

*@author Maicon de Menezes <mdmoliveira@inf.ufpel.edu.br>
*@co-author Guilherme
*@date 19/10/2020
*@link: http://www.facom.ufu.br/~flavio/ed1/files/C++%20ORIENTADO%20A%20OBJETOS.pdf
*@link: https://www.youtube.com/watch?v=T8hhKaCUWSs
*@link: https://www.youtube.com/watch?v=mudL0b9mRTw
*@link: https://gist.github.com/marcoscastro/38720f71e57e29e5360c
*/
//Bibliotecas
#include <algorithm>
#include <cfloat>
#include <iomanip>
#include <iostream>
#include <math.h>  
#include <set>
#include <sstream>
#include <string> 
#include <vector>


//Vocabulário 
#define opened false
#define closed true 
#define Graph_Size 20
using namespace std;
//Estrutura temporárria para armazenar e reorganizar as arestas do grafo
struct Edge {
  short int source;
  short int destiny;  
  double cost;
};

class Graph{
private:
//Atributos
  static unsigned short int    size;  
  vector<bool>          status;
  vector<string>        tags;
  vector<short int>     predecessors;
  vector<long double>   estimates;
  vector<vector<double>>vertices;
//Métodos Auxiliares para metodos de caminho
  void               estimateDistance     (const unsigned short int&, const unsigned short int& );
  void               dijikstra            (const unsigned int&);  
  //void               joinSets(const short int, const unsigned short int&, const unsigned short int&);
  bool               thereIsOpenedVertice ();    
  unsigned short int nextOpenedVertice    ();
  unsigned short int smallestEstimate     ();
  //short int findSet(const short int , const unsigned short int&); 
  
public:
vector<Edge>              kruskal();
//Métodos construtores
  Graph();
  Graph( const unsigned short int& );
  Graph( string );
//Destrutor
  ~Graph();
//Modificadores
  void makeEdgeBetween ( const unsigned short int&, const unsigned short int&, const double& );
  void setStatus       ( const unsigned short int& );
  void setPredecessor  ( const unsigned short int&, const unsigned short int& );
  void setEstimate     ( const unsigned short int&, const double& );
  void setTag          ( const unsigned short int&, string );
//Metodos de IHM
  //void feed();
  
  /* void sortEdges(std::vector<Edge> &, const bool&); */
//Acessores
  bool                 getStatus      ( const unsigned short int& );
  double               getEdgeCost    ( const unsigned short int&, const unsigned short int&);  
  double               getEstimate    ( const unsigned short int& );
  string               getTag         ( const unsigned short int& );
  unsigned short int   getPredecessor ( const unsigned short int& );
  vector <unsigned short int> getNeighbors   ( const unsigned short int& );
  vector<Edge>         getEdges();
  string               toString();
//Metodos de caminho
  vector<int> findCloserWayBetween(const unsigned short int&, const unsigned short int& );
};