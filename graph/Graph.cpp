#include "Graph.h"
#include <iostream>

// Adiciona uma aresta ao grafo.
// Pré-condição: Vertices de origem e destino, e o peso que da aresta.
// Pós-condição: A aresta é adicionada ao grafo.
void Graph::addEdge(int32_t src, int32_t dest, int32_t weight) {
    // Adiciona aresta src -> dest e ordena a lista
    adjList[src].emplace_back(dest, weight);
    adjList[src].sort([](Edge edge1, Edge edge2) {
        return edge1.dest < edge2.dest;
    });

    // Adiciona aresta dest -> sre e ordena a lista caso seja grafo não orientado
    if (!isOriented) {
        adjList[dest].emplace_back(src,weight);
        adjList[dest].sort([](Edge edge1, Edge edge2) {
            return edge1.dest < edge2.dest;
        });
    }
}

// Imprime na tela os dados referentes ao grafo.
// Pré-condição: nenhuma.
// Pós-condição: os dados do grafo são impressos na tela.
void Graph::print() {
    for (int i = 0; i < adjList.size(); i++) {
       std::cout << "Vertice " << i << ":";
       for (Edge edge : adjList[i] ) {
           std::cout << "(" << edge.dest << ", " << edge.weight << ")";
       }
       std::cout << '\n';
    }
}


