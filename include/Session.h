#ifndef SESSION_H_
#define SESSION_H_

#include <vector>
#include <string>
#include "Graph.h"
#include "Tree.h"

class Agent;

enum TreeType{
  Cycle,
  MaxRank,
  Root
};

class Session{
public:
    Session(const std::string& path);
    virtual ~Session();
    void clear();
    
    void simulate();
    void addAgent(const Agent& agent);
    void setGraph(const Graph& graph);
    Graph& getGraph();
    Tree* BFS(int node);
    
    void enqueueInfected(int);
    int dequeueInfected();
    TreeType getTreeType() const;
    int getCurrCycle() const;

    
private:
    Graph g;
    TreeType treeType;
    std::vector<Agent*> agents;
    int currCycle;
};

#endif
