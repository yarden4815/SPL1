#include "Session.h"
#include "Agent.h"
#include <iostream>

Agent::Agent() {}


ContactTracer::ContactTracer() {}
Agent * ContactTracer::clone() const {return new ContactTracer();}
void ContactTracer::act(Session &session) {
    Graph& graph = session.getGraph();
    if (!graph.getInfectedQueue().empty()) {
        std::cout<<"contact tracer act"<<std::endl;
        int start = session.dequeueInfected();
        std::cout<<"before bfs"<<std::endl;
        Tree *path = session.BFS(start);
        std::cout<<"after bfs"<<std::endl;
        int target = path->traceTree();
        std::cout<<"after trace tree"<<std::endl;
        session.getGraph().removeEdges(target);
        delete path;
        std::cout<<"finished contact tracer act"<<std::endl;
    }
}

Virus::Virus(int nodeInd): nodeInd(nodeInd) {

}
Agent * Virus::clone() const {return new Virus(nodeInd);}
void Virus::spreadVirus(Session& session) {
    Graph& graph = session.getGraph();
    std::vector<int> neighbours = graph.getNeighbours(nodeInd);
    int j = 0;
    for(int i = 0 ; i < neighbours.size() && graph.isCarrier(neighbours[i]); i++){
            j++;
    }
    if(j < neighbours.size()) {
        graph.addToCarry(neighbours[j]);
        Agent *newVirus = new Virus(neighbours[j]);
        session.addAgent(*newVirus);
        delete newVirus;
    }
}
void Virus::act(Session &session) {
    Graph& graph = session.getGraph();
/*    if(!graph.isCarrier(nodeInd)) {
        graph.addToCarry(nodeInd);
        spreadVirus(session);
    }*/
    if(!graph.isInfected(nodeInd)) {
        graph.infectNode(nodeInd);
        session.enqueueInfected(nodeInd);
        spreadVirus(session);
    }
    else
        spreadVirus(session);
}





