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
#include "edge.h"


using namespace std;
//Construtor
Edge::Edge(){
    
}
Edge::Edge(const unsigned short int& source, const unsigned short int& destiny, const double& cost){
    this->source = source;
    this->destiny = destiny;
    this->cost = cost;
}
Edge::~Edge(){
    source = 0;
    destiny = 0;
    cost = -1;
}
//Acessores
short int Edge::getSource(){
    return source;
}
short int Edge::getDestiny(){
    return destiny;
}
double Edge::getCost(){
    return cost;
}
//Sobrecarga do operador <
bool Edge::operator < (const Edge& otherEdge) const{
    return (cost < otherEdge.cost);
}
string Edge::to_String(){
    ostringstream streamOut;
    streamOut << setw(2) << "( " << source << ", " << destiny << " ) => " << cost << endl;
    return streamOut.str();
}