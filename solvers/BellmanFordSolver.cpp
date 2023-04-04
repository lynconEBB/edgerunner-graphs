#include "BellmanFordSolver.h"
#include <iostream>
#include <limits>

void BellmanFordSolver::solve(Graph graph) {
    int32_t origin;
    std::cin >> origin;

    std::vector<int32_t> distance(graph.adjList.size(), std::numeric_limits<int32_t>::max());
    std::vector<int32_t> previous(graph.adjList.size(), -1);

    minDistance(graph, origin, distance, previous);

    findNegativeCycle(graph, distance);

    print(graph, origin, distance, previous);
}

bool BellmanFordSolver::validate(Graph graph){
    if(!graph.isOriented) return false;
    return true;
}

void BellmanFordSolver::minDistance(Graph graph, int32_t origin, std::vector<int32_t>& distance, std::vector<int32_t>& previous) {
    distance[origin] = 0;

    for (int32_t i = 1; i < graph.adjList.size(); ++i) {
        for (int32_t u = 0; u < graph.adjList.size(); ++u) {
            for (Edge& edge : graph.adjList[u]) {
                int32_t v = edge.dest;
                int32_t w = edge.weight;
                if (distance[u] != std::numeric_limits<int32_t>::max() && distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                    previous[v] = u;
                }
            }
        }
    }
}

void BellmanFordSolver::findNegativeCycle(Graph graph, std::vector<int32_t>& distance){
    for (int32_t u = 0; u < graph.adjList.size(); ++u) {
        for (Edge& edge : graph.adjList[u]) {
            int32_t v = edge.dest;
            int32_t w = edge.weight;
            if (distance[u] != std::numeric_limits<int32_t>::max() && distance[u] + w < distance[v]) {
                std::cerr << "Grafo possui ciclo de peso negativo" << std::endl;
                return;
            }
        }
    }
}


void BellmanFordSolver::print(Graph graph, int32_t origin, std::vector<int32_t> distance, std::vector<int32_t> previous){
    std::cout << "origem: " << origin << std::endl;
    for (int32_t i = 0; i < graph.adjList.size(); i++) {
        std::cout << "destino: " << i << " distância: ";
        if (distance[i] == std::numeric_limits<int32_t>::max()) {
            std::cout << "--" << " caminho: --" << std::endl;
        } else {
            std::cout << distance[i] << " caminho: ";
            std::vector<int32_t> path;
            int32_t j = i;
            while (j != -1) {
                path.push_back(j);
                j = previous[j];
            }
            for (int32_t k = path.size() - 1; k >= 0; k--) {
                std::cout << path[k];
                if (k != 0) {
                    std::cout << " - ";
                }
            }
            std::cout << std::endl;
        }
    }
}