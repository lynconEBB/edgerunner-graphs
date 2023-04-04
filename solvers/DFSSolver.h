#ifndef GRAPHS_DFSSOLVER_H
#define GRAPHS_DFSSOLVER_H
#include "Solver.h"

class DFSSolver : public Solver{
public:
    void solve(Graph graph) override;
    bool validate(Graph graph) override;
};

#endif
