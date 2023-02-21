#include "Agent.hpp"

// Constructors
Agent::Agent(): state(waiting), sleep(100)
{

}
Agent::Agent(AgentState as): state(as), sleep(100)
{

}
Agent::Agent(AgentState as, int s): state(as), sleep(s)
{

}

// Getters
AgentState Agent::getState()
{
    return state;
}
int Agent::getSleep()
{
    return sleep;
}

// Setters
void Agent::setState(AgentState as)
{
    state = as;
}
void Agent::decreaseSleep(int ds)
{
    if(sleep - ds <= 0){
        setState(sleeping);
    }else{
        sleep = sleep - ds;
    }
}
void Agent::increaseSleep(int is)
{
    if(sleep + is > 100) {
        sleep = 100;
    }else{
        sleep = sleep + is;
    }
}

// Displays
std::string Agent::toString()
{
    std::string display = "(Agent) is ";
    switch (state)
    {
    case sleeping:
        display = display + "sleeping";
        break;
    case working:
        display = display + "working";
        break;
    case waiting:
        display = display + "waiting";
        break;
    }
    display = display + " and his sleep is " + std::to_string(sleep) + "%\n";
    return display;
}

// Do things
void Agent::ActualizeStatus(Environment &)
{

}
void Agent::DoSomething(Environment&)
{

}
