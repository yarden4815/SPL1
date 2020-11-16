#ifndef AGENT_H_
#define AGENT_H_

#include <vector>
#include "Session.h"

class Agent{
public:
    Agent();

    virtual ~Agent();

    virtual Agent* clone() const =0;
    virtual void act(Session& session)=0;
};

class ContactTracer: public Agent{
public:
    ContactTracer();
    virtual Agent* clone() const;
    virtual void act(Session& session);
};


class Virus: public Agent{
public:
    Virus(int nodeInd);
    
    virtual void act(Session& session);
    void spreadVirus(Session& session);

    virtual Agent* clone() const;

private:
    const int nodeInd;
};

#endif
