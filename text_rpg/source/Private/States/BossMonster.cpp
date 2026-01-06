#include "States/BossMonster.h"
#include <string>
#include <iostream>



BossMonster::BossMonster(int Level)
    : Monster(Level)
{
    Name_ = "BossMonster";
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

    static std::uniform_int_distribution<int> DistHP(Level * MIN_BOSS_HP, Level * MAX_BOSS_HP);
    static std::uniform_int_distribution<int> DistATK(Level * MIN_BOSS_ATK, Level * MAX_BOSS_ATK);


    this->HP_ = DistHP(gen);
    this->MaxHP_ = this->HP_;
    this->Attack_ = DistATK(gen);
}
