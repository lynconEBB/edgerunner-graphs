#ifndef GRAPHS_KRUSKALSOLVER_H
#define GRAPHS_KRUSKALSOLVER_H

#include "Solver.h"
#include <set>

struct KruskalEdge {
public:
    int32_t src;
    int32_t dst;
    int32_t weight;
    mutable bool inSpammingTree;

    KruskalEdge(int32_t src, int32_t dst, int32_t weight) : src(src), dst(dst), weight(weight), inSpammingTree(false) {}

    bool operator<(const KruskalEdge& other) const {
        return weight < other.weight;
    }
};

class KruskalSolver: public Solver
{
public:
    void solve(Graph graph) override;
    bool validate(Graph graph) override;

private:
    void joinSets(uint32_t set1, uint32_t set2);
    void outputResult();

private:
    std::multiset<KruskalEdge> sortedEdges;
    std::vector<uint32_t> sets;
    int32_t finalWeight = 0;

};

#endif