#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);
    int getSize() const;
    std::vector<std::vector<int>> getEdges() const;
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
    std::vector<int> getNeighbours(int node) const;
private:
    std::vector<std::vector<int>> edges;
    std::vector<int> infected;
};

#endif
