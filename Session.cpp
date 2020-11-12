//
// Created by spl211 on 08/11/2020.
//
#include <vector>
#include <string>
#include <fstream>
#include "Graph.h"
#include "Session.h"
#include "Tree.h"
#include "queue"
#include "json.hpp"



Session::Session(const std::string &path) {
    std:: ifstream file(path);
    nlohmann:: json j;
    file >> j;
    g=Graph(j["graph"]);
    for(int i = 0; i < j["agents"].size(); i++){
        if(j["agents"][i][0] == "V")


    }

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
                Tree* child = Tree::createTree(*this,neighbours[i]);
                temp->addChild(*child);
                queue.push(child);
                visited[i] = true;
        }
        }

    }
    return tree;
}

Graph & Session::getGraph() const {
}






