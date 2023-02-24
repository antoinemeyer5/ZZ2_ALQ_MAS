#include <iostream>
#include <typeinfo>
#include "Environment.hpp"
#include "Lumberjack.hpp"
#include "Carpenter.hpp"

int main(int, char**) {
    Environment environment(100, 10, 0, 0);
    Lumberjack a;
    Carpenter b;

    // TODO
    // - faire une liste d'agents (bucheron, menuisier, etc)
    // - tirer au hasard l'ordre dans lequel il travaille (ajout d'aleatoire)

    // tour de simulation
    for(int i=1; i<12; i++) {
        std::cout << "\033[4mStart of the round n°" << i << ":\033[0m\n";
        std::cout << environment.BarDisplay();
        // bucheron change son statut puis fait quelque chose
        std::cout << a.toString();
        a.DoSomething(environment);
        // menuisier change son status puis fait quelque chose 
        std::cout << b.toString();
        b.DoSomething(environment);
        // environnement se regenere un peu
        environment.Increase(10, trees);
        std::cout << "==> Environment increase \033[42m10 trees\033[0m\n";
        environment.Decrease(5, pollution);
        std::cout << "==> Environment decrease 5 pollution\n";
        std::cout << "\n";
    }
    return 0;
}