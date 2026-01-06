#include "States/StefanSommer.h"
#include "Utils/RandomUtil.h"

StefanSommer::StefanSommer(int Level)
    : Monster(Level)
{
    Name_ = "Stefan Sommer";
    GenerateStatus(Level);
}

void StefanSommer::GenerateStatus(int Level)
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