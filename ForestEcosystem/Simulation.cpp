#include <iostream>
#include "Environment.hpp"

int main(int, char**) {
    Environment environment(100, 10, 0, 0);
    std::cout << environment.FullDisplay();
    environment.Increase(200, trees);
    std::cout << environment.FullDisplay();
    environment.Decrease(50, pollution);
    std::cout << environment.FullDisplay();
    return 0;
}