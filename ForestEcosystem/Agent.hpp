#ifndef AGENT_HPP
#define AGENT_HPP

// Imports
#include <string>
#include "Environment.hpp"

enum AgentState { sleeping, working, waiting };

class Agent {

    private:
        AgentState state;
        // Level of sleep (between 0% and 100%)
        int sleep;

    public:
        // Constructors
        Agent();
        Agent(AgentState);
        Agent(AgentState, int);
        // Getters
        AgentState getState();
        int getSleep();
        // Setters
        void setState(AgentState);
        void decreaseSleep(int);
        void increaseSleep(int);
        // Displays
        virtual std::string toString();
        // Do things
        virtual void ActualizeStatus(Environment &);
        virtual void DoSomething(Environment &);

};

#endif