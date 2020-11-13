#include "Session.h"
#include "Agent.h"

Agent::Agent() {

}


ContactTracer::ContactTracer() {}
Agent * ContactTracer::clone() const {return new ContactTracer();}
void ContactTracer::act(Session &session) {}

Virus::Virus(int nodeInd): nodeInd(nodeInd) {}
Agent * Virus::clone() const {return new Virus(nodeInd);}
void Virus::act(Session &session) {}





