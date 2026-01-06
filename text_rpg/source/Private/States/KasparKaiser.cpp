#include "States/KasparKaiser.h"
#include "Utils/RandomUtil.h"

KasparKaiser::KasparKaiser(int Level)
    : Monster(Level)
{
    Name_ = "Kaspar Kaiser";
    GenerateStatus(Level);
}

void KasparKaiser::GenerateStatus(int Level)
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