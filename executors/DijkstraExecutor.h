#ifndef GRAPHS_DIJKSTRAEXECUTOR_H
#define GRAPHS_DIJKSTRAEXECUTOR_H
#include "Executor.h"

class DijkstraExecutor : public Executor{
public:
    void execute(Graph graph) override;
};


#endif
