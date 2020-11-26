/**
*#Universidade Federal de Pelotas#
*#Unidade: CDTEC
*#Curso: Engenharia da Computação
*#Disciplina: Algoritmos e Estruturas de Dados 2
*#Profº: Guilherme
*#Aluno: Maicon de Menezes
*#Projeto: Trabalho 3 - AED II - Grafos & Kruskal
*#Módulo: edge.h -  definições da classe que representa uma aresta não direcionada

*@author Maicon de Menezes <mdmoliveira@inf.ufpel.edu.br>
*@co-author Guilherme
*@date 26/11/2020
*@link: http://www.facom.ufu.br/~flavio/ed1/files/C++%20ORIENTADO%20A%20OBJETOS.pdf
*@link: https://gist.github.com/marcoscastro/38720f71e57e29e5360c
*@link: https://www.youtube.com/watch?v=T8hhKaCUWSs
*@link: https://www.youtube.com/watch?v=mudL0b9mRTw
*@link: https://www.youtube.com/watch?v=fziFDaQ1S5I
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

using namespace std;
//Estrutura temporárria para armazenar e reorganizar as arestas do grafo
class Edge {
  //atributos
  short int source;
  short int destiny;  
  double cost;
  
  public:
  //Construtor
  Edge();
  Edge(const unsigned short int&, const unsigned short int&, const double&);
  ~Edge();
  //Acessores
  short int getSource();
  short int getDestiny();
  double getCost();  
  string to_String();
  //Sobrecarga do operador <
  bool operator < (const Edge& ) const;
};