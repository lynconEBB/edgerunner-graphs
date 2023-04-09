#include <iostream>
#include <fstream>
#include "graph/GraphGenerator.h"
#include "solvers/PrimSolver.h"

int main() {
    std::ifstream file("../tests/test2.txt");
    if (!file) {
        std::cout << "Não foi possível abrir o arquivo.";
        return 1;
    }

    GraphGenerator graphGen;
    Graph graph = graphGen.createGraph(file);

    graph.print();
    PrimSolver solver;

    if(solver.validate(graph))
        solver.solve(graph);

    return 0;
}
