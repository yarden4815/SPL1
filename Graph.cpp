#include <vector>
#include "Graph.h"




  Graph::Graph(std::vector<std::vector<int>> matrix) : edges(matrix), infected(getSize(),false),
  carrier(getSize(),false),infectedQueue(){}

  void Graph::carrierToInfected(int nodeInd) {
      infected[nodeInd] = true;
  }

  void Graph::setInfected(int node) {
    infectedQueue.push(node);
}
int Graph::takeInfected() {
    int front = infectedQueue.front();
    infectedQueue.pop();
    return front;
}

   void Graph::infectNode(int nodeInd){
        infected[nodeInd] = true;
    }
    void Graph::addToCarry(int nodeInd) { carrier[nodeInd] = true;}

    bool Graph:: isInfected(int nodeInd){
        return infected[nodeInd];
    }
    bool Graph::isCarrier(int nodeInd) {
       return carrier[nodeInd];
}
   void Graph:: removeEdges(int nodeInd){
        for(int i = 0; i < edges.size(); i++){
            edges[nodeInd][i] = 0;
            edges[i][nodeInd] = 0;
        }
    }
std::vector<bool> Graph::getCarrier() {return carrier;}
    int Graph::getSize() const {return edges.size();}
std::queue<int> Graph::getInfectedQueue() {return infectedQueue;}

    std::vector<std::vector<int>> Graph::getEdges() const {return edges;}

std::vector<bool> Graph::getInfected() {return infected;}

    std::vector<int> Graph::getNeighbours(int node) const {
        std::vector<int> neighbours;
        for(int i=0; i < edges.size(); i++ ){
            if(edges[node][i] == 1)
                neighbours.push_back(i);
        }
        return neighbours;
}

    ;



