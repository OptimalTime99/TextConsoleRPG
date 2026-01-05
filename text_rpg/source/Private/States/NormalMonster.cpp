#include "States/NormalMonster.h"
#include <string>
#include <iostream>
#include <random>

NormalMonster::NormalMonster(std::string Monstername_, int Level)
    : Monster(Monstername_, Level)
{
    //Monstername_ = "NormalMonster";
    GenerateStatus(Level);
}

void NormalMonster::GenerateStatus(int Level)
{
    if (MonsterLevel_ == 0)
    {
        return;
    }
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> DistHP(Level * MIN_HP, Level * MAX_HP);
    std::uniform_int_distribution<int> DistATK(Level * MIN_ATK, Level * MAX_ATK);


    this->MaxHP_ = DistHP(gen);
    this->HP_ = MaxHP_;
    this->Attack_ = DistATK(gen);
}



