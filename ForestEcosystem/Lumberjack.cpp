#include "Lumberjack.hpp"

// Constructors
Lumberjack::Lumberjack() : Agent()
{
}
Lumberjack::Lumberjack(AgentState as) : Agent(as)
{
}
Lumberjack::Lumberjack(AgentState as, int s) : Agent(as, s)
{
}

// Do things
void Lumberjack::ActualizeStatus(Environment &e)
{
    switch (Agent::getState())
    {
    case sleeping:
        if(e.GetEnvironmentAttributs(trees) > 20 && getSleep() > 80){
            // become working
            setState(working);
            std::cout << "==> Lumberjack is working now\n";
        }else if(getSleep() > 80){
            // become waiting
            setState(waiting);
            std::cout << "==> Lumberjack is waiting now\n";
        }else{
            // keep sleeping
            setState(sleeping);
            std::cout << "==> Lumberjack is still sleeping\n";
        }
        break;
    case working:
        if(e.GetEnvironmentAttributs(trees) > 20 && getSleep() > 20){
            // working
            setState(working);
            std::cout << "==> Lumberjack is still working\n";
        }else if(getSleep() > 20){
            // waiting
            setState(waiting);
            std::cout << "==> Lumberjack is waiting now\n";
        }else {
            // sleeping
            setState(sleeping);
            std::cout << "==> Lumberjack is sleeping now\n";
        }
        break;
    case waiting:
        if(e.GetEnvironmentAttributs(trees) > 20){
            // working
            setState(working);
            std::cout << "==> Lumberjack is working now\n";
        }else{
            // waiting
            setState(waiting);
            std::cout << "==> Lumberjack is still waiting\n";
        }
        break;
    }
}
void Lumberjack::DoSomething(Environment &e)
{
    // actualisze status
    ActualizeStatus(e);
    // do a action
    switch (Agent::getState())
    {
    case sleeping:
        // augmente repos
        Agent::increaseSleep(20);
        // diminue pollution
        e.Decrease(5, pollution);
        std::cout << "==> Lumberjack sleep so sleep+20 & pollution-5\n";
        break;
    case working:
        // diminue arbre & repos
        e.Decrease(20, trees);
        Agent::decreaseSleep(20);
        // => augmente bois & pollution
        e.Increase(10, wood);
        e.Increase(15, pollution);
        std::cout << "==> Lumberjack work so sleep-20, trees-20, \033[43mwood+10\033[0m & \033[41mpollution+15\033[0m\n";
        break;
    case waiting:
        // augmente repos
        Agent::increaseSleep(5);
        // diminue pollution
        e.Decrease(5, pollution);
        std::cout << "==> Lumberjack wait so sleep+5 & pollution-5\n";
        break;
    }
}

// Displays
std::string Lumberjack::toString()
{
    std::string display = "==> Lumberjack ";
    display = display + Agent::toString();
    return display;
}
