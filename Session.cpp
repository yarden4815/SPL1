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
    Tree* tree = new Tree(node);
    std::queue<*Tree> queue;
    std::vector<int> neighbours = g.getNeighbours(node);
    std::vector<bool> visited(g.getSize(),false);
    queue.push(tree);
    visited[node] = true;

    while(!queue.empty()){
        Tree* temp = queue.pop();
        for(int i = 0; i < neighbours.size(); i++){
            if(neighbours[i] == 1 && !visit[i]) {
                Tree* child = new Tree(i);
                temp->addChild(child);
                temp = child;
                queue.push(child);
                visited[i] = true;
                neighbours = g.getNeighbours(i);

        }
        }

    }
}






