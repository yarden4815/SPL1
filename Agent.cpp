#include "Session.h"
#include "Agent.h"

Agent::Agent(Session &session): session(session) {

}
ContactTracer::ContactTracer(Session& session): session(session) {}

void ContactTracer::act() {}

Virus::Virus(int nodeInd, Session &session): nodeInd(nodeInd), session(session) {}

void Virus::act() {}

Virus Virus::clone() {
}



