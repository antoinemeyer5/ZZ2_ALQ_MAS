#include <iostream>
#include <typeinfo>
#include "Environment.hpp"
#include "Lumberjack.hpp"
#include "Carpenter.hpp"

int main(int, char**) {
    Environment environment(100, 10, 0, 0);

    //Agent* actors[] = { new Lumberjack(), new Carpenter() }; 
    // => 11 round give : 80 trees, 10 woods and 50 planks
    
    Agent* actors[] = { new Lumberjack(), new Carpenter(), new Lumberjack(), new Carpenter() };
    // => 11 round give : 20 trees, 10 woods and 80 planks

    // TODO
    // - tirer au hasard l'ordre dans lequel il travaille (ajout d'aleatoire)
    // - tracer des graphes avec les évolutions des courbes suivant la configuration de départ

    // tour de simulation
    for(int i=1; i<12; i++) {
        std::cout << "\033[4mStart of the round n°" << i << ":\033[0m\n\n";
        std::cout << environment.BarDisplay();
        // pour chaque acteurs
        for(int i=0; i<4; i++) {
            // bucheron change son statut puis fait quelque chose
            //std::cout << actors[i]->toString();
            actors[i]->DoSomething(environment);
        }
        // environnement se regenere un peu
        environment.Increase(10, trees);
        //std::cout << "==> Environment increase \033[42m10 trees\033[0m\n";
        environment.Decrease(5, pollution);
        //std::cout << "==> Environment decrease 5 pollution\n";
        //std::cout << "\n";
    }
    return 0;
}