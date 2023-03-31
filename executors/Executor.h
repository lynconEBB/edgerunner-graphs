#ifndef GRAPHS_EXECUTOR_H
#define GRAPHS_EXECUTOR_H
#include "../graph/Graph.h"

class Executor {
public:
    virtual void execute(Graph graph) = 0;
    virtual bool validate(Graph graph) = 0;
};

#endif