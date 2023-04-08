#include <iostream>
#include "DFSSolver.h"

enum class Color {
    WHITE,
    GRAY,
    BLACK
};

bool DFSSolver::validate(Graph graph)
{
    return true;
}

void DFSSolver::solve(Graph graph) {
    std::cout << "Insira a origem: ";
    int32_t origin;
    std::cin >> origin;

    currentGraph = graph;

    for (int i = 0; i < currentGraph.adjList.size(); i++) {
        colors.push_back(Color::WHITE);
    }

    for (int i = origin; i < graph.adjList.size(); i++) {
        if (colors[i] == Color::WHITE) {
            visit(i);
        }
    }
    for (int i = 0; i < origin; i++) {
        if (colors[i] == Color::WHITE) {
            visit(i);
        }
    }
    std::cout << "\b\b ";
}

void DFSSolver::visit(uint32_t index) {
    colors[index] = Color::GRAY;
    visits.push_back(index);
    std::cout << index << " - ";
    for(Edge edge : currentGraph.adjList[index]) {
        if (colors[edge.dest] == Color::WHITE) {
            visit(edge.dest);
        }
    }
    colors[index] = Color::BLACK;
}

