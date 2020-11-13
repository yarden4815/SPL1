//
// Created by spl211 on 08/11/2020.
//
#include <vector>
#include <string>
#include <fstream>
#include "Graph.h"
#include "Session.h"
#include "Tree.h"
#include "Agent.h"
#include "queue"
#include "json.hpp"
#include "string"



Session::Session(const std::string &path) : g(std::vector<std::vector<int>>()),treeType(),agents(),currCycle(0) {
    std:: ifstream file(path);
    nlohmann:: json j;
    file >> j;
    g = Graph(j["graph"]);
    std::string tType = (std:: string)j["tree"];
    for(int i = 0; i < j["agents"].size(); i++) {
        if (j["agents"][i][0] == "V")
            agents.push_back(new Virus(j["agents"][i][1]));
        else
            agents.push_back(new ContactTracer());
    }
    if(tType == "M")
        treeType = MaxRank;
    else if(tType == "C")
        treeType = Cycle;
    else
        treeType = Root;



    }



Tree * Session::BFS(int node) {
    Tree* tree = Tree::createTree(*this,node);
    std::queue<Tree*> queue;
    std::vector<int> neighbours;
    std::vector<bool> visited(g.getSize(),false);
    queue.push(tree);
    visited[node] = true;

    while(!queue.empty()){
        Tree* temp = queue.front();
        queue.pop();
        neighbours = g.getNeighbours(temp->getNode());
        for(int i = 0; i < neighbours.size(); i++){
            if(!visited[neighbours[i]]) {
                Tree *child = Tree::createTree(*this, neighbours[i]);
                temp->addChild(*child);
                queue.push(child);
                visited[i] = true;
            }
        }

    }
    return tree;
}
int Session::getCurrCycle() const {return currCycle;}
Graph Session::getGraph() const  {return g;}
void Session::setGraph(const Graph &graph) {
    g=graph;
}





