// Imports
#include <string>

enum EnvironmentAttributs { pollution, trees, wood, plank };

// Describe the environment of the simulation
class Environment {

    private:
        // State of nature (between 0% and 100%)
        int Pollution;
        // Trees => Wood => Plank
        // State of the forest
        int TreesNumber;
        // State of wood stock
        int WoodsNumber;
        // Number of wooden plank (~final score)
        int WoodenPlank;

    public:
        // Getters 
        int GetEnvironmentAttributs(EnvironmentAttributs);
        // Constructor
        Environment(int, int, int, int);
        // Displays
        std::string SimpleDisplay();
        std::string FullDisplay();
        // Setters
        // Increasers
        void Increase(int, EnvironmentAttributs);
        // Decreasers
        void Decrease(int, EnvironmentAttributs);

};