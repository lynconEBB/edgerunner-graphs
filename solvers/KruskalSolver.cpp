#include "KruskalSolver.h"
#include <ostream>
#include <iostream>
#include <queue>
#include "gvc.h"
#include <cgraph.h>
#include <string>

std::ostream& operator<<(std::ostream& os, const KruskalEdge& edge) {
    os << "(" << edge.src << ", " << edge.dst << ")";
    return os;
}

void KruskalSolver::solve(Graph graph) {
    for (int i = 0; i < graph.adjList.size(); i++){
        sets.push_back(i);
        for (Edge edge : graph[i]) {
            if (edge.dest >= i)
                sortedEdges.insert({i, edge.dest, edge.weight});
        }
    }

    for (const KruskalEdge& edge : sortedEdges) {
        if (sets[edge.src] != sets[edge.dst]) {
            finalWeight += edge.weight;
            edge.inSpammingTree = true;
            joinSets(sets[edge.src], sets[edge.dst]);
        }
    }

    outputResult();
}

void KruskalSolver::outputResult() {

    std::cout << "peso total: " << finalWeight << '\n';
    std::cout << "arestas: ";

    Agraph_t* g = agopen("G", Agundirected, nullptr);
    agsafeset(g, "label", "Kruskal Spamming Tree", "");
    agsafeset(g, "fontname", "Arial", "");

    for (const KruskalEdge& edge : sortedEdges) {


        char* nodeName1 = const_cast<char*>(std::to_string(edge.src).c_str());
        Agnode_t* n1 =  agnode(g, nodeName1, TRUE);
        char* nodeName2 = const_cast<char*>(std::to_string(edge.dst).c_str());
        Agnode_t* n2 = agnode(g, nodeName2, TRUE);

        Agedge_t* e = agedge(g,n1,n2,"", TRUE);
        char* weightStr = const_cast<char*>(std::to_string(edge.weight).c_str());
        agsafeset(e, "label", weightStr,"");
        if (edge.inSpammingTree) {
            std::cout << edge << ",";
            agsafeset(e, "color", "red", "");
            agsafeset(e, "fontcolor", "red","");
        }
    }
    std::cout << "\b ";

    GVC_t* gvc = gvContext();
    gvLayout(gvc, g, "dot");
    gvRenderFilename(gvc, g, "png", "kruskalResult.png");
    agclose(g);
    gvFreeContext(gvc);
}

void KruskalSolver::joinSets(uint32_t set1, uint32_t set2) {
    for (uint32_t& set : sets) {
        if (set == set1)
            set = set2;
    }
}

bool KruskalSolver::validate(Graph graph) {
    if (graph.isOriented)
        return false;

    std::vector<bool> visited;
    std::queue<int32_t> nextVertex;

    visited.reserve(graph.adjList.size());
    for (int i = 0; i < graph.adjList.size(); i++) {
        visited.push_back(false);
    }
    nextVertex.push(0);

    while (!nextVertex.empty()) {
        visited[nextVertex.front()] = true;
        for (Edge edge : graph[nextVertex.front()]) {
            if (!visited[edge.dest])
                nextVertex.push(edge.dest);
        }
        nextVertex.pop();
    }

    for (bool wasVisited : visited) {
        if (!wasVisited)
            return false;
    }

    return true;
}