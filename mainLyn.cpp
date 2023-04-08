#include <iostream>
#include <fstream>
#include "graph/GraphGenerator.h"
#include "solvers/DFSSolver.h"
#include "solvers/BFSSolver.h"

int main() {
    std::ifstream file("../tests/test2.txt");
    if (!file) {
        std::cout << "Não foi possível abrir o arquivo.";
        return 1;
    }

    GraphGenerator graphGen;
    Graph graph = graphGen.createGraph(file);

    graph.print();

    BFSSolver solver;
    solver.solve(graph);

    return 0;
}
