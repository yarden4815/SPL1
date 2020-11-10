//
// Created by spl211 on 08/11/2020.
//
#include <vector>
#include <string>
#include "Graph.h"
#include "Session.h"
#include "queue"


Session::Session(const std::string &path) {}

Tree * Session::BFS(int node) {
    Tree* tree = new Tree(node);
    std::queue<int> queue;
    std::vector<std::vector<int>> edges = g.getEdges();
    std::vector<bool> visit(g.getSize(),false);
    queue.push(node);
    visit[node] = true;
    int temp = 0;
    while(!queue.empty()){
        for(int i = 0; i < g.getSize(); i++){
            if(edges[node][i] == 1 & !visit[i]) {

                queue.push(edges[node][i]);
                visit[i] = true;
        }
        }

    }
}

Graph & Session::getGraph() const {
}






