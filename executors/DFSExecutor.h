#ifndef GRAPHS_DFSEXECUTOR_H
#define GRAPHS_DFSEXECUTOR_H
#include "Executor.h"

class DFSExecutor : public Executor{
public:
    void execute(Graph graph) override;
};

#endif
