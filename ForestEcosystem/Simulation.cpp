#include <iostream>
#include "Environment/Environment.hpp"

int main(int, char**) {
    Environment environment(100, 10, 0);
    std::cout << environment.FullDisplay();
    environment.IncreaseTreesNumber(200);
    std::cout << environment.FullDisplay();
    environment.DecreasePollution(50);
    std::cout << environment.FullDisplay();
    return 0;
}