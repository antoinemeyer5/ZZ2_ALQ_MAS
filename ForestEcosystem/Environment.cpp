#define CATCH_CONFIG_MAIN
#include "catch.hpp"

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
Environment::Environment(int tn, int p, int wn, int wp) : TreesNumber(tn), Pollution(p), WoodsNumber(wn), WoodenPlank(wp)
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
std::string Environment::BarDisplay()
{
    std::string pollu_bar = "\033[41mPollution " + std::to_string(Pollution) + "%\033[0m[";
    for(int i=0; i<100; i++){
        if(i < Pollution){
            if(i < 30){
                // green
                pollu_bar = pollu_bar + "\033[32m";
            }else if(i < 60){
                // yellow
                pollu_bar = pollu_bar + "\033[33m";
            }else{
                // red
                pollu_bar = pollu_bar + "\033[31m";
            }
            pollu_bar = pollu_bar + "-\033[0m";
        }else{
            pollu_bar = pollu_bar + " ";
        }
    }
    pollu_bar = pollu_bar + "]\n";
    std::string tree_bar = "\033[42mTrees " + std::to_string(TreesNumber) + "\033[0m\n";
    std::string wood_bar = "└>\033[43mWoods " + std::to_string(WoodsNumber) + "\033[0m\n";
    std::string plank_bar = "  └>\033[44mPlanks " + std::to_string(WoodenPlank) + "\033[0m\n";
    return pollu_bar + tree_bar + wood_bar + plank_bar;
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
        //std::cout << "==> Environment increase trees\n";
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
            //std::cout << "==> Environment have 0 pollution!\n";
        }
        else
        {
            Pollution = Pollution - decrease;
            //std::cout << "==> Environment decrease " + std::to_string(decrease) + " pollution\n";
        }
        break;
    case trees:
        if (TreesNumber - decrease <= 0)
        {
            TreesNumber = 0;
            //std::cout << "==> Environment have 0 tree...\n";
        }
        else
        {
            TreesNumber = TreesNumber - decrease;
            //std::cout << "==> Environment decrease " + std::to_string(decrease) + " trees\n";
        }
        break;
    case wood:
        if (WoodsNumber - decrease <= 0)
        {
            WoodsNumber = 0;
            //std::cout << "==> Environment have 0 wood...\n";
        }
        else
        {
            WoodsNumber = WoodsNumber - decrease;
            //std::cout << "==> Environment decrease " + std::to_string(decrease) + " woods\n";
        }
        break;
    case plank:
        break;
    }
}