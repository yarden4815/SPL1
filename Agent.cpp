#include "Session.h"
#include "Agent.h"

Agent::Agent() {

}


ContactTracer::ContactTracer() {}

void ContactTracer::act(Session &session) {

}

Virus::Virus(int nodeInd): nodeInd(nodeInd) {}

void Virus::act(Session &session) {}

Virus Virus::clone() {
}



