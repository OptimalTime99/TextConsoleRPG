#include "States/EliasBeck.h"
#include <string>
#include <iostream>

EliasBeck::EliasBeck(std::string Monstername_, int Level)
    : Monster(Monstername_, Level)
{
    Monstername_ = "Elias Beck";
    GenerateStatus(Level);
}

void EliasBeck::GenerateStatus(int Level)
{
    if (MonsterLevel_ == 0)
    {
        return;
    }
    static std::random_device rd;
    static std::mt19937 gen(rd());

    static std::uniform_int_distribution<int> DistHP(Level * MIN_HP, Level * MAX_HP);
    static std::uniform_int_distribution<int> DistATK(Level * MIN_ATK, Level * MAX_ATK);


    this->HP_ = DistHP(gen);
    this->MaxHP_ = this->HP_;
    this->Attack_ = DistATK(gen);
}