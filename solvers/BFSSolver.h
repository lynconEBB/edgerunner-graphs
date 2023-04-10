#ifndef GRAPHS_BFSSOLVER_H
#define GRAPHS_BFSSOLVER_H
#include "Solver.h"
#include <vector>
#include <queue>

enum class Color;

class BFSSolver: public Solver {

public:
    void solve(Graph graph) override;
    bool validate(Graph graph) override;

private:
    Graph currentGraph;
    std::queue<uint32_t> grayVertex;
    std::vector<Color> colors;

    void exploreVertice(uint32_t vertice);
};

#endif