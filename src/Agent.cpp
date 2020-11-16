#include "../include/Session.h"
#include "../include/Agent.h"
#include <iostream>

Agent::Agent() {}

Agent::~Agent() {
}


ContactTracer::ContactTracer() {}
Agent * ContactTracer::clone() const {return new ContactTracer();}
void ContactTracer::act(Session &session) {
    Graph& graph = session.getGraph();
    if (!graph.getInfectedQueue().empty()) {
        int start = session.dequeueInfected();
        Tree *path = session.BFS(start);
        int target = path->traceTree();
        session.getGraph().removeEdges(target);
        delete path;
    }
}

Virus::Virus(int nodeInd): nodeInd(nodeInd) {}

Agent * Virus::clone() const {return new Virus(nodeInd);}
void Virus::spreadVirus(Session& session) {
    Graph& graph = session.getGraph();
    std::vector<int> neighbours = graph.getNeighbours(nodeInd);
    int j = 0;
    for(int i = 0 ; i < (int)neighbours.size() && graph.isCarrier(neighbours[i]); i++){
            j++;
    }
    if(j < (int)neighbours.size()) {
        graph.addToCarry(neighbours[j]);
        Agent *newVirus = new Virus(neighbours[j]);
        session.addAgent(*newVirus);
        delete newVirus;
    }
}
void Virus::act(Session &session) {
    Graph& graph = session.getGraph();
    if(!graph.isInfected(nodeInd)) {
        graph.infectNode(nodeInd);
        session.enqueueInfected(nodeInd);
        spreadVirus(session);
    }
    else
        spreadVirus(session);
}






