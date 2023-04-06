#include "FloydWarshallSolver.h"
#include <iostream>
#include <limits>
#include <iomanip>

void FloydWarshallSolver::solve(Graph graph) {
    Matrix distance(graph.adjList.size(), std::vector<int32_t>(graph.adjList.size(), std::numeric_limits<int32_t>::max()));
    Matrix next(graph.adjList.size(), std::vector<int32_t>(graph.adjList.size(), -1));

    inicializeMatrix(graph, distance, next);    

    minDistance(graph.adjList.size(), distance, next);

    printMatrix(graph.adjList.size(), distance);
    printPath(graph.adjList.size(), next);
}

bool FloydWarshallSolver::validate(Graph graph){

    return true;
}

void FloydWarshallSolver::inicializeMatrix(Graph graph, Matrix& distance, Matrix& next){
    for (int32_t i = 0; i < graph.adjList.size(); i++) {
        for (Edge edge : graph.adjList[i]) {
            distance[i][edge.dest] = edge.weight;
            next[i][edge.dest] = edge.dest;
        }
        distance[i][i] = 0;
        next[i][i] = i;
    }
}

void FloydWarshallSolver::minDistance(int32_t size, Matrix& distance, Matrix& next){
    for (int32_t k = 0; k < size; k++) {
        for (int32_t i = 0; i < size; i++) {
            for (int32_t j = 0; j < size; j++) {
                if (distance[i][k] != std::numeric_limits<int32_t>::max() && distance[k][j] != std::numeric_limits<int32_t>::max()) {
                    if (distance[i][j] > distance[i][k] + distance[k][j]) {
                        distance[i][j] = distance[i][k] + distance[k][j];
                        next[i][j] = next[i][k];
                    }
                }
            }
        }
    }
}

void FloydWarshallSolver::printMatrix(int32_t size, Matrix distance){
    std::cout << std::endl << "     ";
    for (int32_t i = 0; i < size; i++) {
        std::cout << std::setw(4) << i << " ";
    }

    std::cout << std::endl;
    for (int32_t i = 0; i < size; i++) {
        std::cout << std::setw(4) << i << " ";
        for (int32_t j = 0; j < size; j++) {
            if (distance[i][j] == std::numeric_limits<int32_t>::max()) {
                std::cout << "  -- ";
            } else {
                std::cout << std::setw(4) << distance[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

void FloydWarshallSolver::printPath(int32_t size, Matrix next){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << "caminho de " << i << " para " << j << ": ";
            if (i == j) {
                std::cout << i;
            } else if (next[i][j] == -1) {
                std::cout << "---";
            } else {
                std::cout << i << " - ";
                int k = next[i][j];
                while (k != j) {
                    std::cout << k << " - ";
                    k = next[k][j];
                }
                std::cout << j;
            }
            std::cout << std::endl;
        }
    }
}