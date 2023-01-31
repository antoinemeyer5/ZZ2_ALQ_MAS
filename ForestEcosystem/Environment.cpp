#include "Environment.hpp"

// Getters
int Environment::GetEnvironmentAttributs(EnvironmentAttributs ea)
{
    int response = -1;
    switch(ea)
    {
    case pollution:
        response = Pollution;
        break;
    case trees:
        response = TreesNumber;
        break;
    case wood:
        response = WoodsNumber;
        break;
    case plank:
        response = WoodenPlank;
        break;
    }
    return response;
}

// Constructor
Environment::Environment(int tn, int p, int wn, int wp) : Pollution(p), TreesNumber(tn), WoodsNumber(wn), WoodenPlank(wp)
{
}

// Displays
std::string Environment::SimpleDisplay()
{
    std::string display = "(Environment) ";
    display = display + "Pollution: " + std::to_string(Pollution) + "%";
    display = display + "; Trees: " + std::to_string(TreesNumber);
    display = display + "; Woods: " + std::to_string(WoodsNumber);
    display = display + "; Planks: " + std::to_string(WoodenPlank) + "\n";
    return display;
}
std::string Environment::FullDisplay()
{
    std::string entitle = "┌ Environment\n";
    std::string pollution = "| Pollution    " + std::to_string(Pollution) + "%\n";
    std::string trees = "| Trees        " + std::to_string(TreesNumber) + "\n";
    std::string woods = "| Woods        " + std::to_string(WoodsNumber) + "\n";
    std::string planks = "| Planks       " + std::to_string(WoodenPlank) + "\n";
    std::string end = "└\n";
    return entitle + pollution + trees + woods + planks + end;
}

// Increasers
void Environment::Increase(int increase, EnvironmentAttributs valueName)
{
    switch (valueName)
    {
    case pollution:
        if (Pollution + increase >= 100)
        {
            Pollution = 100;
        }
        else
        {
            Pollution = Pollution + increase;
        }
        break;
    case trees:
        TreesNumber = TreesNumber + increase;
        break;
    case wood:
        WoodsNumber = WoodsNumber + increase;
        break;
    case plank:
        WoodenPlank = WoodenPlank + increase;
        break;
    }
}

// Decreasers
void Environment::Decrease(int decrease, EnvironmentAttributs ea)
{
    switch (ea)
    {
    case pollution:
        if (Pollution - decrease <= 0)
        {
            Pollution = 0;
        }
        else
        {
            Pollution = Pollution - decrease;
        }
        break;
    case trees:
        if (TreesNumber - decrease <= 0)
        {
            TreesNumber = 0;
        }
        else
        {
            TreesNumber = TreesNumber - decrease;
        }
        break;
    case wood:
        if (WoodsNumber - decrease <= 0)
        {
            WoodsNumber = 0;
        }
        else
        {
            WoodsNumber = WoodsNumber - decrease;
        }
        break;
    case plank:
        break;
    }
}