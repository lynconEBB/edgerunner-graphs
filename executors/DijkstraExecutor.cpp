#include "DijkstraExecutor.h"
#include <iostream>
#include <limits>

void DijkstraExecutor::execute(Graph graph) {
     int origin;
    std::cin >> origin;

    std::vector<int> distance(graph.adjList.size(), std::numeric_limits<int>::max());
    std::vector<int> previous(graph.adjList.size(), -1);

    EdgePriorityQueue priorityQueue;

    minDistance(graph, origin, distance, previous, priorityQueue);

    print(graph, distance, previous);
}

bool DijkstraExecutor::validate(Graph graph){
    for (int i = 0; i < graph.adjList.size(); i++) {
        for (Edge edge : graph.adjList[i] ) {
            if(edge.weight < 0) return false;
        }
    }
    return true;
}

void DijkstraExecutor::minDistance(Graph graph, int32_t origin, std::vector<int32_t>& distance,
                                   std::vector<int32_t>& previous, EdgePriorityQueue& priorityQueue){
    distance[origin] = 0;
    priorityQueue.emplace(origin, 0);

    while (!priorityQueue.empty()) {
        int u = priorityQueue.top().dest;
        priorityQueue.pop();
        for (Edge &edge: graph.adjList[u]) {
            if (distance[edge.dest] > distance[u] + edge.weight) {
                distance[edge.dest] = distance[u] + edge.weight;
                previous[edge.dest] = u;
                priorityQueue.push(Edge(edge.dest, distance[edge.dest]));
            }
        }
    }


}

void DijkstraExecutor::print(Graph graph, std::vector<int32_t> distance, std::vector<int32_t> previous){
    for (int i = 0; i < graph.adjList.size(); i++) {
        std::cout << "destino: " << i << " distância: ";
        if (distance[i] == std::numeric_limits<int>::max()) {
            std::cout << "--" << " caminho: --" << std::endl;
        } else {
            std::cout << distance[i] << " caminho: ";
            std::vector<int> path;
            int j = i;
            while (j != -1) {
                path.push_back(j);
                j = previous[j];
            }
            for (int k = path.size() - 1; k >= 0; k--) {
                std::cout << path[k];
                if (k != 0) {
                    std::cout << " - ";
                }
            }
            std::cout << std::endl;
        }
    }
}
