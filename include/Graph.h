#ifndef GRAPH_H_
#define GRAPH_H_
#include "queue"

#include <vector>

class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix);
    std::queue<int> getInfectedQueue();
    std::vector<bool> getInfected();
    std::vector<bool> getCarrier();
    int getSize() const;
    std::vector<std::vector<int>> getEdges() const;
    void addToCarry(int nodeInd);
    void infectNode(int nodeInd);
    bool isInfected(int nodeInd);
    std::vector<int> getNeighbours(int node) const;
    void removeEdges(int nodeInd);
    void carrierToInfected(int nodeInd);
    bool isCarrier(int nodeInd);
    void setInfected(int node);
    int takeInfected();
private:
    std::vector<std::vector<int>> edges;
    std::vector<bool> infected;
    std::queue<int> infectedQueue;
    std::vector<bool> carrier;
};

#endif
