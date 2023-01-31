#include <iostream>
#include <typeinfo>
#include "Environment.hpp"
#include "Lumberjack.hpp"

int main(int, char**) {
    Environment environment(100, 10, 0, 0);
    Lumberjack a;

    // etat bucheron 
    //std::cout << a.toString();
    // etat environnement
    // std::cout << environment.SimpleDisplay();


    // tour de simulation
    for(int i=1; i<12; i++) {
        std::cout << "Start of the round n°" << i << ": ";
        std::cout << environment.SimpleDisplay();
        // bucheron change son statut puis fait quelque chose
        std::cout << a.toString();
        a.DoSomething(environment);
        // etat bucheron 
        // std::cout << a.toString();
        std::cout << "End of the round n°" << i << ": ";
        // etat environnement
        std::cout << environment.SimpleDisplay() << "\n";
    }

    //environment.Increase(200, trees);
    //std::cout << environment.FullDisplay();
    //environment.Decrease(50, pollution);
    //std::cout << environment.FullDisplay();
    return 0;
}