#include "Tree.h"
#include "Graph.h"



Tree::Tree(int rootLabel): node(rootLabel),children(){}

int Tree::getNode() const {return node;}

Tree * Tree::createTree(const Session &session, int rootLabel) {
    Graph graph = session.getGraph();


}
void Tree::addChild(const Tree &child) {

}



