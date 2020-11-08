#include "Session.h"

class Agent{
public:
    Agent(Session& session): session(session){
    }

    virtual void act() = 0;


private:
    Session& session;
};

class ContactTracer: public Agent{
public:
    ContactTracer();

    virtual void act(){

    }
};


