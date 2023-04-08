#include <iostream>
#include "BFSSolver.h"

enum class Color {
    WHITE,
    GRAY,
    BLACK
};

void BFSSolver::solve(Graph graph) {
    std::cout << "Insira a origem: ";
    int32_t origin;
    std::cin >> origin;

    currentGraph = graph;
    for (int i = 0; i < graph.adjList.size(); i++) {
        colors.push_back(Color::WHITE);
    }
    colors[origin] = Color::GRAY;
    grayVertex.push(origin);

    while (!grayVertex.empty()) {
        exploreVertice(grayVertex.front());
        grayVertex.pop();
    }
    std::cout << "\b\b \n";
}

void BFSSolver::exploreVertice(uint32_t vertice) {
    std::cout << vertice << " - ";
    for (Edge edge : currentGraph[vertice]) {
        if (colors[edge.dest] == Color::WHITE) {
            colors[edge.dest] = Color::GRAY;
            grayVertex.push(edge.dest);
        }
    }
    colors[vertice] = Color::BLACK;
}

bool BFSSolver::validate(Graph graph) {
    return false;
}