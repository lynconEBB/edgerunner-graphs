#ifndef GRAPHS_PRIMSOLVER_H
#define GRAPHS_PRIMSOLVER_H

#include "Solver.h"
#include <utility>
#include <vector>
#include <queue>
#include <limits>
#include <string>

struct PrimVertice {
public:
    int32_t num;
    std::list<Edge> edges;
    int32_t key;
    int32_t prev;
    bool inQueue;

    PrimVertice(int32_t num, const std::list<Edge>& edges) :
            num(num), edges(edges),
            key(std::numeric_limits<int32_t>::max()), prev(-1), inQueue(true) {}

    PrimVertice(int32_t num, const std::list<Edge>& edges, int32_t key) :
            num(num), edges(edges),
            key(key), prev(-1), inQueue(true) {}

};

std::ostream& operator<<(std::ostream& os, const PrimVertice& vertice);

struct ComparePrimVerticePointer {
    bool operator()(const PrimVertice* v1, const PrimVertice* v2) const {
        return v1->key > v2->key;
    }
};

class PrimSolver : public Solver {

public:
    void solve(Graph graph) override;
    bool validate(Graph graph) override;

private:
    void outputResult();
    int32_t getTotalWeight();

private:
    const static std::string DEFAULT_OUT_FILE;
    std::deque<PrimVertice> vertices;
    std::priority_queue<PrimVertice*, std::vector<PrimVertice*>, ComparePrimVerticePointer> queue;
};

#endif