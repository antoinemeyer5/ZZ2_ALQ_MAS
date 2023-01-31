#ifndef LUMBERJACK_HPP
#define LUMBERJACK_HPP

#include "Agent.hpp"
#include <iostream>

class Lumberjack : public Agent {

    private:

    public:
        // Constructors
        Lumberjack();
        Lumberjack(AgentState);
        Lumberjack(AgentState, int);

        void ActualizeStatus(Environment &);
        void DoSomething(Environment &);
        // Displays
        std::string toString();

};

#endif