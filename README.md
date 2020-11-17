---
instituição: Universidade Federal de Pelotas
unidade: CDTEC
curso: Engenharia da Computação
disciplina: Programação Orientada a Objetos
layout: post
projeto: Trabalho 2 - AED II - Grafos & Djsktra
módulo: README.md
author: Maicon de Menezes
professor: Guilherme
data: 19/10/2020
tag:
  - equacoes
  - LaTeX
mathjax: true
---
t1 | t2
--------|------
![](https://upload.wikimedia.org/wikipedia/commons/4/49/UFPEL-ESCUDO-2013.png){width=200px} | _Universidade Federal de Pelotas - UFPel    
Centro de Desenvolvimento Tecnológico - CDTec    
Engenharia da Computação_

***
#### Disciplina: Algoritmos e Estruturas de Dados 2
#### Projeto: Trabalho 2 - AED II - Grafos & Djsktra
#### Módulo: README.md
#### Autor: Maicon de Menezes
#### Professor: Guilherme
#### Pelotas, 19 de Outubro de 2020
***

# Grafos & Djsktra

### Esta é especificação de um modelo de grafo implementado utilizando matriz de adjacências, o objeito do exercício é desenvolver o algoritmo de Djsktra para busca do menor caminho. A matrix de adjacências armazena em seus elementos vértices vizinhos e o custo do caminho entre eles.    


## Classe: Graph    

### Atributos:    
  Nome         |Tipo                                |Definição                            |Descrição
  :------------|:-----------------------------------:|:-----------------------------------:|-----------
  size         | inteiro curto sem sinal  | $$ {size \in \mathbb{N} \| 0 \| < size <=20 } $$ | Representa a ordem da matrix quadrada (tamanho do grafo) utilizada para representar o grafo, com no máximo 20 vertices como especifica o problema proposto
  vertice      | matriz de inteiros longos sem sinal | vertice[size, size]  | Matriz de adjacências dos vértices do grafo e suas respectivas arestas com peso ou custo.
  status      | vetor de booleanos | status[size]  | Vetor para identificar o status de visita de um vertice do grafo seu estados podem ser (aberto = falso, fechado = verdadeiro)
  predecessor | vetor de inteiros curtos sem sinal | predecessor[size]  | Vetor que identifica o vertice antecessor do vertice em questão no caminho percorrido
  estimate    | vetor de inteiros longos sem sinal | estimate[size]  | Vetor que armazena a estimativa de custo do caminho até o vertice em questão
  tag         | vetor de cadeias de caracteres | tag[size]  | Vetor para armazenar um rótulo de significado para cada vértice, atributo opcional

### Métodos:    

Assinatura | Argumentos | Descrição
:--------------|:-----------------:|:------
constructor( size ) | size - inteiro curto | Constroí uma instância de grafo com _**size**_ vertices
makeEdge(source, destiny, cost) | source - inteiro curto; destiny - inteiro curto; cost - inteiro longo | Cria uma aresta entre o vértice _**source**_ e o vertice _**destiny**_ com o peso _**cost**_
setStatus(vertice) | vertice - inteiro curto | Alterna entre os status do vertice _**aberto**_(false) e _**fechado**_(true), onde cada chamada troca o valor atual do vertice
setPredecessor(vertice, predecessor) | vertice - inteiro curto; predecessor - inteiro curto | Altera o _**predecessor**_ do _**vertice**_ em questão
setEstimate(vertice, estimate) | vertice - inteiro curto; estimate - inteiro longo | Altera a estimativa (_**estimate**_) de custo do caminho até o _**vertice**_ em questão
setTag(vertice, tag) | vertice - inteiro curto; tag - cadeia de caracteres | Altera a etiqueta de identificação de um vertice
findWayBetween(source, destiny) | source - inteiro curto; destiny - inteiro curto | Procura pelo menor caminho entre o vertice origem (_**source**_) e o vertice destino (_**destiny**_)
