#include "States/MoritzMundt.h"
#include <string>
#include <iostream>

MoritzMundt::MoritzMundt(int Level)
    : Monster(Level)
{
    Name_ = "Moritz Mundt";
    GenerateStatus(Level);
}

void MoritzMundt::GenerateStatus(int Level)
{
    if (MonsterLevel_ == 0)
    {
        return;
    }
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> DistHP(Level * MIN_HP, Level * MAX_HP);
    std::uniform_int_distribution<int> DistATK(Level * MIN_ATK, Level * MAX_ATK);


    this->HP_ = DistHP(gen);
    this->MaxHP_ = this->HP_;
    this->Attack_ = DistATK(gen);
}