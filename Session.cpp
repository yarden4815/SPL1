//
// Created by spl211 on 08/11/2020.
//
#include <vector>
#include <string>
#include "Graph.h"
#include "Session.h"
#include "Tree.h"
#include "queue"


Session::Session(const std::string &path) {}

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






