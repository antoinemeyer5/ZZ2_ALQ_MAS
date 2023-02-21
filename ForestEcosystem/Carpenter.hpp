#ifndef CARPENTER_HPP
#define CARPENTER_HPP

#include "Agent.hpp"

class Carpenter : public Agent {

    public:
        // Constructors
        Carpenter();
        // Actions
        void ActualizeStatus(Environment &);
        void DoSomething(Environment &);
        // Displays
        std::string toString();

};

#endif