#include <vector>
#include "Graph.h"




  Graph::  Graph(std::vector<std::vector<int>> matrix) : edges(matrix){}

   void Graph::infectNode(int nodeInd){
        infected.push_back(nodeInd);
    }

    bool Graph:: isInfected(int nodeInd){
        for (int i = 0; i < infected.size(); ++i){
            if (infected[i] == nodeInd)
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
    ;



