#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

// Imports
#include <string>
#include <iostream>

enum EnvironmentAttributs { pollution, trees, wood, plank };

// Describe the environment of the simulation
class Environment {

    private:
        // Trees => Wood => Plank
        // State of the forest
        int TreesNumber;
        // State of nature (between 0% and 100%)
        int Pollution;
        // State of wood stock
        int WoodsNumber;
        // Number of wooden plank (~final score)
        int WoodenPlank;

    public:
        // Getters / Sensors
        int GetEnvironmentAttributs(EnvironmentAttributs);
        // Constructor
        Environment(int, int, int, int);
        // Displays
        std::string SimpleDisplay();
        std::string FullDisplay();
        std::string BarDisplay();
        // Setters / Actuators
        // concatenation de ces methodes non ?
        // Increasers
        void Increase(int, EnvironmentAttributs);
        // Decreasers
        void Decrease(int, EnvironmentAttributs);

};

#endif