#include "Tree.h"
#include "Graph.h"
#include <vector>



Tree::Tree(int rootLabel): node(rootLabel),children(){}

Tree * Tree::createTree(const Session &session, int rootLabel) {
    Graph graph = session.getGraph();


}
void Tree::addChild(const Tree &child) {
    children.push_back(child);
}



