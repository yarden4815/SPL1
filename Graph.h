#ifndef GRAPH_H_
#define GRAPH_H_
#include "queue"

#include <vector>

class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);
    int getSize() const;
    std::vector<std::vector<int>> getEdges() const;
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
    std::vector<int> getNeighbours(int node) const;
    void removeEdges(int nodeInd);
    void carrierToInfected(int nodeInd);
    bool isCarrier(int nodeInd);
private:
    std::vector<std::vector<int>> edges;
    std::vector<int> infected;
    std::queue<int> infectedQueue;
    std::vector<int> carrier;
};

#endif
