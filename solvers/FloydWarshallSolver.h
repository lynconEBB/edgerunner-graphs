#ifndef GRAPHS_FLOYDWARSHALL_H
#define GRAPHS_FLOYDWARSHALL_H
#include "Solver.h"
#include <vector>


class FloydWarshallSolver : public Solver{
    using Matrix = std::vector<std::vector<int32_t>>;

public:
    void solve(Graph graph) override;
    bool validate(Graph graph) override;

private:
    void inicializeMatrix(Graph graph, Matrix& distance, Matrix& next);
    void minDistance(int32_t size, Matrix& distance, Matrix& next);
    void printMatrix(int32_t size, Matrix distance);
    void printPath(int32_t size, Matrix next);

};


#endif
