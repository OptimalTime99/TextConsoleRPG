#include "States/KevinKruger.h"
#include "Utils/RandomUtil.h"

KevinKruger::KevinKruger(int Level)
    : Monster(Level)
{
    Name_ = "Kevin Kruger";
    GenerateStatus(Level);
}

void KevinKruger::GenerateStatus(int Level)
{
    if (MonsterLevel_ == 0)
    {
        return;
    }

    int DistHP = RandomUtil::GetRandomInt(Level * MIN_HP, Level * MAX_HP);
    int DistATK = RandomUtil::GetRandomInt(Level * MIN_ATK, Level * MAX_ATK);


    this->HP_ = DistHP;
    this->MaxHP_ = this->HP_;
    this->Attack_ = DistATK;
}