#include <iostream>
#include <fstream>
#include "graph/GraphGenerator.h"
#include "graph/Graph.h"
#include "solvers/FloydWarshallSolver.h"

int main() {
    std::ifstream file("../tests/test1.txt");
    if (!file) {
        std::cout << "Não foi possível abrir o arquivo.";
        return 1;
    }

    GraphGenerator graphGen;
    Graph graph = graphGen.createGraph(file);
    graph.print();

    //DijkstraSolver dj;
    //dj.solve(graph);

    //BellmanFordSolver bf;
    //bf.solve(graph);

    FloydWarshallSolver fw;
    fw.solve(graph);

    return 0;
}