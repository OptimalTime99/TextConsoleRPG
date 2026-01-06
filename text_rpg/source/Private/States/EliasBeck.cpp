#include "States/EliasBeck.h"
#include "Utils/RandomUtil.h"

EliasBeck::EliasBeck(int Level)
    : Monster(Level)
{
    Name_ = "Elias Beck";
    GenerateStatus(Level);
}

void EliasBeck::GenerateStatus(int Level)
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