#ifndef GRAPHS_APP_H
#define GRAPHS_APP_H
#include <fstream>
#include "graph/Graph.h"
#include "graph/GraphGenerator.h"
#include <memory>

class Solver;

enum class Option {
    LOAD = 1,
    DRAW = 2,
    DFS = 3,
    BFS = 4,
    DIJKSTRA = 5,
    BELLMANFORD = 6,
    FLOYDWARSHALL = 7,
    KRUSKAL = 8,
    PRIM = 9,
    EXIT = 10
};

class App {
public:
    void run();

private:
    void requestFile(std::ifstream& configFile);
    void requestOption();
    void executeOption();
    void printMenu();

    bool hasGraphLoaded = false;
    Option option;
    std::shared_ptr<Solver> currentSolver;
    Graph currentGraph;
    GraphGenerator graphGenerator;
};

#endif