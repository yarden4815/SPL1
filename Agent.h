#ifndef AGENT_H_
#define AGENT_H_

#include <vector>
#include "Session.h"

class Agent{
public:
    Agent(Session& session);
    
    virtual void act()=0;
};

class ContactTracer: public Agent{
public:
    ContactTracer();
    
    virtual void act(Session& session);
};


class Virus: public Agent{
public:
    Virus(int nodeInd);
    
    virtual void act(Session& session);

    Virus clone();

private:
    const int nodeInd;
};

#endif
