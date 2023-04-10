#include <iostream>
#include <limits>
#include "App.h"
#include "solvers/DijkstraSolver.h"
#include "solvers/KruskalSolver.h"
#include "solvers/PrimSolver.h"
#include "solvers/FloydWarshallSolver.h"
#include "solvers/BellmanFordSolver.h"
#include "solvers/BFSSolver.h"
#include "solvers/DFSSolver.h"

void App::run() {
    while (option != Option::EXIT)  {
        printMenu();
        requestOption();
        executeOption();
    }
    std::cout << "Saindo!!";
}

void App::requestFile(std::ifstream &configFile) {
    std::string fileName;
    while (!configFile.is_open()) {
        std::cout << "Entre com o arquivo de definicao do automato:";
        std::cin >> fileName;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        configFile.open(fileName);

        if (!configFile.is_open())
            std::cout << "[Erro]> Arquivo nao encontrado!\n";
    }
}

void App::requestOption() {
    std::cout << "O que deseja fazer?:";
    int op = 0;
    std::cin >> op;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    option = static_cast<Option>(op);
}

void App::executeOption() {
    if (option == Option::EXIT)
        return;

    if (option == Option::LOAD) {
        std::ifstream file;
        requestFile(file);
        try {
            currentGraph = graphGenerator.createGraph(file);
            hasGraphLoaded = true;
        } catch (const char* error) {
            std::cout << "[Erro]>" << error << '\n';
            hasGraphLoaded = false;
        }
        return;
    }

    if (!hasGraphLoaded) {
        std::cout << "Nenhum grafo carregado!\n";
        return;
    }

    if (option == Option::DRAW) {
        std::cout << "Grafo desenhado no arquivo: !\n";
        return;
    }
    switch (option) {
        case Option::DFS:
            currentSolver = std::make_shared<DFSSolver>();
            break;
        case Option::BFS:
            currentSolver = std::make_shared<BFSSolver>();
            break;
        case Option::DIJKSTRA:
            currentSolver = std::make_shared<DijkstraSolver>();
            break;
        case Option::BELLMANFORD:
            currentSolver = std::make_shared<BellmanFordSolver>();
            break;
        case Option::FLOYDWARSHALL:
            currentSolver = std::make_shared<FloydWarshallSolver>();
            break;
        case Option::KRUSKAL:
            currentSolver = std::make_shared<KruskalSolver>();
            break;
        case Option::PRIM:
            currentSolver = std::make_shared<PrimSolver>();
            break;
    }

    if (currentSolver->validate(currentGraph))
        currentSolver->solve(currentGraph);

    currentSolver.reset();
}

void App::printMenu() {
    std::cout << "\n1-Carregar grafo\n";
    std::cout << "2-Desenhar grafo\n";
    std::cout << "3-Executar busca em profundidade\n";
    std::cout << "4-Executar busca em largura\n";
    std::cout << "5-Executar Dijkstra\n";
    std::cout << "6-Executar Bellman-Ford \n";
    std::cout << "7-Executar Floyd-Warshall\n";
    std::cout << "8-Executar Kruskal\n";
    std::cout << "9-Executar Prim\n";
    std::cout << "10-Sair\n";
}