#ifndef GRAPHS_BELLMANFORDSOLVER_H
#define GRAPHS_BELLMANFORDSOLVER_H
#include "Solver.h"

class BellmanFordSolver : public Solver{
public:
    void solve(Graph graph) override;
    bool validate(Graph graph) override;

private:
    void minDistance(Graph graph, int32_t origin, std::vector<int32_t>& distance, std::vector<int32_t>& previous);
    void findNegativeCycle(Graph graph, std::vector<int32_t>& distance);
    void print(Graph graph, int32_t origin, std::vector<int32_t> distance, std::vector<int32_t> previous);

};


#endif
