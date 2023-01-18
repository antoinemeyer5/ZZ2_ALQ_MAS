// Imports
#include <string>

// Describe the environment of the simulation
class Environment {

    public:
        // Getters 
        int GetTreesNumber();
        int GetPollution();
        int GetWoodsNumber();
        // Constructor
        Environment(int, int, int);
        // Displays
        std::string SimpleDisplay();
        std::string FullDisplay();
        // Increasers
        void IncreaseTreesNumber(int);
        void IncreasePollution(int);
        void IncreaseWoodsNumber(int);
        // Decreasers
        void DecreaseTreesNumber(int);
        void DecreasePollution(int);
        void DecreaseWoodsNumber(int);

    private:
        // State of the forest
        int TreesNumber;
        // State of nature (between 0% and 100%)
        int Pollution;
        // State of wood stock
        int WoodsNumber;

};