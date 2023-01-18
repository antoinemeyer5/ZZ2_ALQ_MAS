#include "Environment.hpp"

// Getters 
int Environment::GetTreesNumber() {
    return TreesNumber;
}
int Environment::GetPollution() {
    return Pollution;
}
int Environment::GetWoodsNumber() {
    return WoodsNumber;
}

// Constructor
Environment::Environment(int tn, int p, int wn) : TreesNumber(tn), Pollution(p), WoodsNumber(wn) {
    
}

// Displays
std::string Environment::SimpleDisplay() {
    std::string display = "Environment => ";
    display             = display + "Trees: "       + std::to_string(TreesNumber);
    display             = display + "; Pollution: " + std::to_string(Pollution)     + "%";
    display             = display + "; Woods: "     + std::to_string(WoodsNumber)   + "\n";
    return display;
}
std::string Environment::FullDisplay() {
    std::string entitle     = "┌ Environment\n";
    std::string trees       = "| Trees        " + std::to_string(TreesNumber) + "\n";
    std::string pollution   = "| Pollution    " + std::to_string(Pollution)   + "%\n";
    std::string woods       = "| Woods        " + std::to_string(WoodsNumber) + "\n";
    std::string end         = "└\n";
    return entitle + trees + pollution + woods + end;
}

// Increasers
void Environment::IncreaseTreesNumber(int increase) {
    TreesNumber = TreesNumber + increase;
}
void Environment::IncreasePollution(int increase) {
    if (Pollution + increase >= 100) {
        Pollution = 100;
    } else {
        Pollution = Pollution + increase;
    }
}
void Environment::IncreaseWoodsNumber(int increase) {
    WoodsNumber = WoodsNumber + increase;
}

// Decreasers
void Environment::DecreaseTreesNumber(int decrease) {
    if (TreesNumber - decrease <= 0) {
        TreesNumber = 0;
    } else {
        TreesNumber = TreesNumber - decrease;
    }
}
void Environment::DecreasePollution(int decrease) {
    if (Pollution - decrease <= 0) {
        Pollution = 0;
    } else {
        Pollution = Pollution - decrease;
    }
}
void Environment::DecreaseWoodsNumber(int decrease) {
    if (WoodsNumber - decrease <= 0) {
        WoodsNumber = 0;
    } else {
        WoodsNumber = WoodsNumber - decrease;
    }
}