#include "Tree.h"
#include "Graph.h"
#include "Session.h"



Tree::Tree(int rootLabel): node(rootLabel),children(std::vector<Tree*>()){}

int Tree::getNode() const {return node;}

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
MaxRankTree::MaxRankTree(int rootLabel) :Tree(rootLabel){}
int MaxRankTree::traceTree() {

}
Tree * MaxRankTree::clone() const {
    return new MaxRankTree(getNode());
}
RootTree::RootTree(int rootLabel) :Tree(rootLabel){}
Tree * RootTree::clone() const {
    return new RootTree(getNode());
}
CycleTree::CycleTree(int rootLabel, int currCycle) : Tree(rootLabel), currCycle(currCycle){}
Tree * CycleTree::clone() const {
    return new CycleTree(getNode(),currCycle);
}



