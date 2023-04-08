#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include <vector>
#include <list>
#include <cstdint>

struct Edge {
public:
    int32_t dest;
    int32_t weight;

    Edge(int32_t inDest, int32_t inWeight) : dest(inDest), weight(inWeight) {}

    friend bool operator> ( const Edge& edge1, const Edge& edge2 ) {
        return edge1.weight > edge2.weight;
    }
};

class Graph {

public:
    std::vector<std::list<Edge>> adjList;

    bool isOriented;

public:
    Graph(): isOriented(false) {}

    Graph(bool inIsOriented, int vertex): adjList(vertex), isOriented(inIsOriented) {}

    void addEdge(int32_t src, int32_t dest, int32_t weight);

    void print();

    std::list<Edge>& operator[](uint32_t vertex) {
        return adjList[vertex];
    }

     std::vector<std::list<Edge>>::iterator begin() {
        return adjList.begin();
    }

    std::vector<std::list<Edge>>::iterator end() {
        return adjList.end();
    }
};

#endif