#include "States/KasparKaiser.h"
#include <string>
#include <iostream>

KasparKaiser::KasparKaiser(std::string Monstername_, int Level)
    : Monster(Monstername_, Level)
{
    Monstername_ = "Kaspar Kaiser";
    GenerateStatus(Level);
}

void KasparKaiser::GenerateStatus(int Level)
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