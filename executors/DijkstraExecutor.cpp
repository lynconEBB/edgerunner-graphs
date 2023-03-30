#include "DijkstraExecutor.h"
#include <iostream>
#include <limits>
#include <queue>

void DijkstraExecutor::execute(Graph graph) {
    int origin;
    std::cin >> origin;
    int n = graph.adjList.size();
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    std::vector<int> prev(n, -1);
    dist[origin] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push(std::make_pair(0, origin));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto& edge : graph.adjList[u]) {
            int v = edge.dest;
            int w = edge.weight;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                prev[v] = u;
                pq.push(std::make_pair(dist[v], v));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << "destino: " << i << " dist.: ";
        if (dist[i] == std::numeric_limits<int>::max()) {
            std::cout << "--" << " caminho: --" << std::endl;
        } else {
            std::cout << dist[i] << " caminho: ";
            std::vector<int> path;
            int j = i;
            while (j != -1) {
                path.push_back(j);
                j = prev[j];
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
