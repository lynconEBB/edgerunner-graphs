#include "Graph.h"
#include <iostream>

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

void Graph::print() {
    for (int i = 0; i < adjList.size(); i++) {
       std::cout << "Vertice " << i << ":";
       for (Edge edge : adjList[i] ) {
           std::cout << "(" << edge.dest << ", " << edge.weight << ")";
       }
       std::cout << '\n';
    }
}


