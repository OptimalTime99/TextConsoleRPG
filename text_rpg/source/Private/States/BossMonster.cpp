#include "States/BossMonster.h"
#include "Utils/RandomUtil.h"

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

    int DistHP = RandomUtil::GetRandomInt(Level * MIN_HP, Level * MAX_HP);
    int DistATK = RandomUtil::GetRandomInt(Level * MIN_ATK, Level * MAX_ATK);


    this->HP_ = DistHP;
    this->MaxHP_ = this->HP_;
    this->Attack_ = DistATK;
}
