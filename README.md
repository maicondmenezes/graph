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
![](https://upload.wikimedia.org/wikipedia/commons/4/49/UFPEL-ESCUDO-2013.png) Universidade Federal de Pelotas - UFPel    
_Centro de Desenvolvimento Tecnológico - CDTec    
Engenharia da Computação_

***
#### Disciplina: Algoritmos e Estruturas de Dados 2
#### Projeto: Trabalho 2 - AED II - Grafos & Djsktra
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
  vertice      | matriz de reais longos sem sinal | vertice[size, size]  | Matriz de adjacências dos vértices do grafo e suas respectivas arestas com peso ou custo.
  status      | vetor de booleanos | status[size]  | Vetor para identificar o status de visita de um vertice do grafo seu estados podem ser (aberto = falso, fechado = verdadeiro)
  predecessor | vetor de inteiros curtos | predecessor[size]  | Vetor que identifica o vertice antecessor do vertice em questão no caminho percorrido
  estimate    | vetor de reais longos | estimate[size]  | Vetor que armazena a estimativa de custo do caminho até o vertice em questão
  tag         | vetor de cadeias de caracteres | tag[size]  | Vetor para armazenar um rótulo de significado para cada vértice, atributo opcional

## Métodos:   
### Contrutores e Destrutores

|   Assinatura   | Argumentos    | Descrição                            | Escopo
:---------------|:--------------:|:-------------------------------------|:--------:
  Graph()        | sem argumento | Construtor padrão da classe          | Público
  Graph(**size**)    | inteiro       | Construtói um grafo com **size** nós | Público
  ~Graph()       | sem argumento | Destrutor  padrão da classe          | Público

### Modificadores

|   Assinatura   | Argumentos    | Descrição                            | Escopo
:---------------|:--------------:|:-------------------------------------|:--------:
  makeEdgeBetween(**source**, **destiny**, **cost**) | inteiro, inteiro, real | cria uma aresta de custo **cost** entre o vértice fonte **source** e o vértice destino **destiny** | Público
  setStatus(**vertice**) | inteiro | Atualiza o status de visitação de um **vertice** alternando entre **true** e **false** a cada chamada |  Público
  setPredecessor(**vertice**, **predecessor**) | inteiro, inteiro | Altera o Antecessor **predecessor** do **vertice** |  Público
  setEstimate(**vertice**, **estimate**) | inteiro, real | Altera a estimativa **estimate** de custo total do caminho até o **vertice** |  Público
  setTag(**vertice**, **tag**) | inteiro, string | Adiciona um identificador **tag** ao **vertice** |  Público

### Acessores

|Assinatura|Tipo de Retorno|Argumentos|Descrição|Escopo
:--|:--:|:--:|:--:|:--:
getStatus(**vertice**)|booleano|inteiro|Retorna o status de visitação de um **vertice**|Público
getEdgeCost(**source**, **destiny**)|real|inteiro, inteiro|Retorna o custo de uma aresta com inicio no vertice fonte **source** e destino no vertice **destiny**|Público
getEstimate(**vertice**)|real|inteiro|Retorna a estimativa de custo total do caminho até um **vertice**|Público
getTag(**vertice**)|string|inteiro|Retorna a identificação **tag** de um **vertice**
getPredecessor(**vertice**)|inteiro|inteiro|Retorna o antecessor de um **vertice** em um caminho|Público
getNeighbors(**vertice**)|vetor de inteiros|inteiro|Retorna uma lista com todos vizinhos de um **vertice**
  
### Metodos de caminho
|Assinatura|Tipo de Retorno|Argumentos|Descrição|Escopo
:--|:--:|:--:|:--:|:--:
findCloserWayBetween(**source**, **destiny**)|vetor de inteiros|inteiro, inteiro|Retorna uma lista com o menor caminho entre um vertice fonte **source** e seu destino **destiny**


