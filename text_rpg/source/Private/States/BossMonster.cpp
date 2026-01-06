#include "States/BossMonster.h"
#include <random>

BossMonster::BossMonster(int Level)
    : Monster(Level)
{
    Name_ = "Alles fur Einen";
    GenerateStatus(Level);
}

void BossMonster::GenerateStatus(int Level)
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