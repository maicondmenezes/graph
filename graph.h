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
*@orientator Guilherme
*@date 19/10/2020
*@link: http://www.facom.ufu.br/~flavio/ed1/files/C++%20ORIENTADO%20A%20OBJETOS.pdf
*/
//Bibliotecas
#include <iostream>
#include <string>
#include <cfloat>
#include <vector>

//Vocabulário 
#define false  0
#define opened false
#define true 1
#define closed true 
#define Graph_Size 20
using namespace std;

class Graph{
private:
//Atributos
  unsigned short int    size;  
  vector<bool>          status;
  vector<string>        tags;
  vector<short int>     predecessors;
  vector<long double>   estimates;
  vector<vector<double>>vertices;
//Métodos Auxiliares para metodos de caminho
  void               estimateDistance     (const unsigned short int&, const unsigned short int& );
  void               dijikstra            (const unsigned int&);
  bool               thereIsOpenedVertice ();
  unsigned short int nextOpenedVertice    ();
  unsigned short int smallestEstimate     ();

public:
//Métodos construtores
  Graph();
  Graph( const unsigned short int& );
//Destrutor
  ~Graph();
//Modificadores
  void makeEdgeBetween ( const unsigned short int&, const unsigned short int&, const double& );
  void setStatus       ( const unsigned short int& );
  void setPredecessor  ( const unsigned short int&, const unsigned short int& );
  void setEstimate     ( const unsigned short int&, const double& );
  void setTag          ( const unsigned short int&, string );
//Metodos de IHM
  void feedGraph  ();
  void printGraph ();
//Acessores
  bool                 getStatus      ( const unsigned short int& );
  double               getEdgeCost    ( const unsigned short int&, const unsigned short int&);  
  double               getEstimate    ( const unsigned short int& );
  string               getTag         ( const unsigned short int& );
  unsigned short int   getPredecessor ( const unsigned short int& );
  unsigned short int * getNeighbors   ( const unsigned short int& );
  
//Metodos de caminho
  vector<vector<int>>findCloserWayBetween(const unsigned short int&, const unsigned short int& );
};
