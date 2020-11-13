#include <vector>
#include "Graph.h"




  Graph::Graph(std::vector<std::vector<int>> matrix) : edges(matrix), infected(std::vector<int>()),carrier(std::vector<int>()),infectedQueue(std::queue<int>()){}

  void Graph::carrierToInfected(int nodeInd) {
      infected.push_back(nodeInd);
  }


   void Graph::infectNode(int nodeInd){
        carrier.push_back(nodeInd);
        infectedQueue.push(nodeInd);
    }

    bool Graph:: isInfected(int nodeInd){
        for (int i = 0; i < infected.size(); ++i){
            if (infected[i] == nodeInd)
                return true;
        }
        return false;
    }
    bool Graph::isCarrier(int nodeInd) {
        for (int i = 0; i < infected.size(); ++i){
            if (carrier[i] == nodeInd)
                return true;
        }
        return false;
}
   void Graph:: removeEdges(int nodeInd){
        for(int i = nodeInd; i < edges.size(); ++i){
            edges[nodeInd][i] = 0;
            edges[i][nodeInd] = 0;
        }
    }
    int Graph::getSize() const {return edges.size();}

    std::vector<std::vector<int>> Graph::getEdges() const {return edges;}

    std::vector<int> Graph::getNeighbours(int node) const {
        std::vector<int> neighbours;
        for(int i=0; i < edges.size(); i++ ){
            if(edges[node][i] == 1)
                neighbours.push_back(i);
        }
        return neighbours;
}

    ;



