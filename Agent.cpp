#include "Session.h"
#include "Agent.h"

Agent::Agent() {

}


ContactTracer::ContactTracer() {}
Agent * ContactTracer::clone() const {return new ContactTracer();}
void ContactTracer::act(Session &session) {}

Virus::Virus(int nodeInd): nodeInd(nodeInd) {}
Agent * Virus::clone() const {return new Virus(nodeInd);}
void Virus::spreadVirus(Session& session) {
    int i = 0;
    Graph graph = session.getGraph();
    std::vector<int> neighbours = graph.getNeighbours(nodeInd);
    for(int i = 0 ; i < neighbours.size() && graph.isCarrier(neighbours[i]); i++){}
    if(i < neighbours.size()) {
        session.enqueueInfected(neighbours[i]);
        Agent *newVirus = new Virus(neighbours[i]);
        session.addAgent(*newVirus);
        delete newVirus;
    }
}
void Virus::act(Session &session) {
    Graph graph = session.getGraph();
    if(!graph.isCarrier(nodeInd)) {
        session.enqueueInfected(nodeInd);
        spreadVirus(session);
    }
    else {
        graph.carrierToInfected(nodeInd);
        spreadVirus(session);
    }








}





