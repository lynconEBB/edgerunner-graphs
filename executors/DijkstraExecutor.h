#ifndef GRAPHS_DIJKSTRAEXECUTOR_H
#define GRAPHS_DIJKSTRAEXECUTOR_H
#include "Executor.h"
#include <queue>

class DijkstraExecutor : public Executor{
    using EdgePriorityQueue = std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>>;

public:
    void execute(Graph graph) override;
    bool validate(Graph graph) override;

private:
    void minDistance(Graph graph, int32_t origin, std::vector<int32_t>& distance,
                     std::vector<int32_t>& previous, EdgePriorityQueue& priorityQueue);
    void print(Graph graph, std::vector<int32_t> distance, std::vector<int32_t> previous);
};

#endif
