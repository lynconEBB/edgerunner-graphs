#ifndef GRAPHS_DIJKSTRASOLVER_H
#define GRAPHS_DIJKSTRASOLVER_H
#include "Solver.h"
#include <queue>

class DijkstraSolver : public Solver{
    using EdgePriorityQueue = std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>>;

public:
    void solve(Graph graph) override;
    bool validate(Graph graph) override;

private:
    void minDistance(Graph graph, int32_t origin, std::vector<int32_t>& distance,
                     std::vector<int32_t>& previous, EdgePriorityQueue& priorityQueue);
    void print(Graph graph, std::vector<int32_t> distance, std::vector<int32_t> previous, int32_t origin);
};

#endif
