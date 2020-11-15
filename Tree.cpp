#include "Tree.h"
#include "Graph.h"
#include "Session.h"
#include <iostream>



Tree::Tree(int rootLabel): node(rootLabel),children(std::vector<Tree*>()){}

int Tree::getNode() const {return node;}
std::vector<Tree *> Tree::getChildren() {return children;}

Tree * Tree::createTree(const Session &session, int rootLabel)  {
   if(session.getTreeType() == MaxRank){
       return new MaxRankTree(rootLabel);
   }
   else if(session.getTreeType() == Cycle) {
       return new CycleTree(rootLabel,session.getCurrCycle());
   }
   else
       return new RootTree(rootLabel);
}

void Tree::addChild(const Tree& child) {
    Tree* clone = child.clone();
    children.push_back(clone);
}

void Tree::addChild(Tree *child) {
    children.push_back(child);
}
MaxRankTree::MaxRankTree(int rootLabel) :Tree(rootLabel){}

int MaxRankTree::traceTree() {

    std::queue<Tree*> queue;
   int maxNode = getNode();
   int maxRank = children.size();
    queue.push(this);
    while(!queue.empty()){
        Tree* temp = queue.front();
        queue.pop();
        std::vector<Tree*> child=temp->getChildren();
        if(child.size() > maxRank) {
            maxRank = child.size();
            maxNode = temp->getNode();

        }
        for(int i = 0; i < child.size(); i++){
             {
                queue.push(child[i]);
            }
        }

    }
    return maxNode;
}
Tree * MaxRankTree::clone() const {
    return new MaxRankTree(getNode());
}

RootTree::RootTree(int rootLabel) :Tree(rootLabel){}

Tree * RootTree::clone() const {
    return new RootTree(getNode());
}
int RootTree::traceTree() {

    return node;
}
CycleTree::CycleTree(int rootLabel, int currCycle) : Tree(rootLabel), currCycle(currCycle){}
Tree * CycleTree::clone() const {
    return new CycleTree(getNode(),currCycle);
}
int CycleTree::traceTree() {

    int tempCycle = currCycle;
    Tree *tempChild = this;
    while (tempCycle > 0 && tempChild->getChildren().size() != 0) {
        tempChild = tempChild->getChildren()[0];
        tempCycle--;
    }
    return tempChild->getNode();
}



