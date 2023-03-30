#include "GraphGenerator.h"
#include <string>
#include <regex>
#include <algorithm>

Graph GraphGenerator::createGraph(std::ifstream &input) {
    bool isOriented = getIsOriented(input);
    int32_t numVertex = getNumVertex(input);
    Graph graph(isOriented, numVertex);
    setEdges(input, graph);
}

bool GraphGenerator::getIsOriented(std::ifstream &input) {
    std::string line;
    std::getline(input, line);
    line.erase(remove_if(line.begin(), line.end(), isspace), line.end());

    std::smatch matches;
    std::regex reg("orientado=([a-z]{3})");
    std::regex_search(line,matches,reg);

    if (matches.size() != 2)
        throw "Erro de formatação!";

    if ("sim" != matches.str(1) || "nao" != matches.str(1))
        throw "Erro de formatação!";

    return "sim" == matches.str(1);
}

int32_t GraphGenerator::getNumVertex(std::ifstream &input) {
    std::string line;
    std::getline(input, line);
    line.erase(remove_if(line.begin(), line.end(), isspace), line.end());

    std::smatch matches;
    std::regex reg("V=([0-9])");
    std::regex_search(line,matches,reg);

    if (matches.size() != 2)
        throw "Erro de formatação!";

    return stoi(matches.str(1));
}

void GraphGenerator::setEdges(std::ifstream& input, Graph& graph){
    std::string line;
    while(std::getline(input, line)){
        line.erase(remove_if(line.begin(), line.end(), isspace), line.end());

        std::smatch matches;
        std::regex reg("\\(([0-9]),([0-9])\\):(-?[0-9])");

        if (matches.size() != 4)
            throw "Erro de formatação!";

        graph.addEdge(
                stoi(matches.str(1)),
                stoi(matches.str(2)),
                stoi(matches.str(3)));
    }
}