#include <vector>
#include "Graph.h"dddd


class Graph{
public:
    Graph(std::vector<std::vector<int>> matrix){
        edges = matrix;
    }

    void infectNode(int nodeInd){
        infected.push_back(nodeInd);
    }

    bool isInfected(int nodeInd){
        for (int i = 0; i < infected.size(); ++i){
            if (infected[i] == nodeInd)
                return true;
        }
        return false;
    }
    void removeEdges(int nodeInd){
        for(int i = nodeInd; i < edges.size(); ++i){
            edges[nodeInd][i] = 0;
            edges[i][nodeInd] = 0;
        }
    }

private:
    std::vector<std::vector<int>> edges;
    std::vector<int> infected;
};



