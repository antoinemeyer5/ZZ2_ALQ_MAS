#include "Carpenter.hpp"

Carpenter::Carpenter() : Agent()
{

}

void Carpenter::ActualizeStatus(Environment &e)
{
    switch(Agent::getState())
    {
        case sleeping:
            if(e.GetEnvironmentAttributs(wood) > 10 && getSleep() > 60){
                setState(working);
                std::cout << "==> Carpenter go to work\n";
            }else if(getSleep() > 60){
                setState(waiting);
                std::cout << "==> Carpenter waiting now\n";
            }else{
                setState(sleeping);
                std::cout << "==> Carpenter still sleeping\n";
            }
            break;
        case working:
            if(e.GetEnvironmentAttributs(wood) > 10 && getSleep() > 20){
                setState(working);
                std::cout << "==> Carpenter still working\n";
            }else if(getSleep() > 20){
                setState(waiting);
                std::cout << "==> Carpenter wait now\n";
            }else{
                setState(sleeping);
                std::cout << "==> Carpenter sleeping now\n";
            }
            break;
        case waiting:
            if(e.GetEnvironmentAttributs(wood) > 10){
                setState(working);
                std::cout << "==> Carpenter go to work\n";
            }else{
                setState(waiting);
                std::cout << "==> Carpenter is still waiting\n";
            }
            break;
    }
}

void Carpenter::DoSomething(Environment &e)
{
    // actualize status
    ActualizeStatus(e);
    // do action
    switch(Agent::getState())
    {
        case sleeping:
            Agent::increaseSleep(20);
            e.Decrease(5, pollution);
            std::cout << "==> Carpenter sleep, sleep+20 & pollution-5\n";
            break;
        case working:
            e.Decrease(10, wood);
            Agent::decreaseSleep(20);
            e.Increase(10, plank);
            e.Increase(10, pollution);
            std::cout << "==> Carpenter work, wood-10, sleep-20, \033[44mplank+10\033[0m & \033[41mpollution+10\033[0m\n";
            break;
        case waiting:
            Agent::increaseSleep(5);
            e.Decrease(5, pollution);
            std::cout << "==> Carpenter wait, sleep+5 & pollution-5\n";
            break;
    }

}

// Displays
std::string Carpenter::toString()
{
    std::string display = "==> Carpenter ";
    display = display + Agent::toString();
    return display;
}