#include "Graph.h"
#include <iostream>

void Graph::addEdge(int32_t src, int32_t dest, int32_t weight) {
    adjList[src].emplace_back(dest, weight);
    if (!isOriented)
        adjList[dest].emplace_back(src,weight);
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


