#ifndef GRAPHS_GRAPHGENERATOR_H
#define GRAPHS_GRAPHGENERATOR_H

#include <fstream>
#include "Graph.h"


class GraphGenerator {
public:
    Graph createGraph(std::ifstream& input);
private:
    bool getIsOriented(std::ifstream& input);
    int32_t getNumVertex(std::ifstream& input);
    void setEdges(std::ifstream& input, Graph& graph);
};

#endif