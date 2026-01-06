#include "States/HugoJauch.h"
#include "Utils/RandomUtil.h"

HugoJauch::HugoJauch(int Level)
    : Monster(Level)
{
    Name_ = "Hugo Jauch";
    GenerateStatus(Level);
}

void HugoJauch::GenerateStatus(int Level)
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