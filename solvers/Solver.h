#ifndef GRAPHS_SOLVER_H
#define GRAPHS_SOLVER_H
#include "../graph/Graph.h"

class Solver {
public:
    virtual void solve(Graph graph) = 0;
    virtual bool validate(Graph graph) = 0;
};

#endif