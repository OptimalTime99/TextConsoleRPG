#include "States/Monster.h"
#include "States/player.h"
#include <string>
#include <iostream>
#include <random>

Monster::Monster(std::string MonsterName,int Level,bool bisBoss) 
    : MonsterName_(MonsterName), MonsterLevel_(Level), bisBoss_(bisBoss)
{
    if (bisBoss)
    {
        GenerateBoss(MonsterLevel_);
    }
    else
    {
        GenerateNomal(MonsterLevel_);
    }
}

void Monster::GenerateNomal(int Level_)
{
    bisBoss_ = false;
    MonsterLevel_ = Level_;
    if (MonsterLevel_ == 0)
    {
        return;
    }
    
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> DistHP(Level_ * MIN_HP, Level_ * MAX_HP);
    std::uniform_int_distribution<int> DistATK(Level_ * MIN_ATK, Level_ * MAX_ATK);

    this->HP_ = DistHP(gen);
    this->Attack_ = DistATK(gen);
}

void Monster::GenerateBoss(int Level_)
{
    bisBoss_ = true;
    MonsterLevel_ = Level_ + 5;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> DistHP(Level_ * BOSS_MIN_HP, Level_ * BOSS_MAX_HP);
    std::uniform_int_distribution<int> DistATK(Level_ * MIN_BOSS_ATK, Level_ * MAX_BOSS_ATK);

    this->HP_ = DistHP(gen);
    this->Attack_ = DistATK(gen);

}

void Monster::TakeDamage(int dmg)
{
    if (dmg < 0)
    {
        dmg = 0;
    }

    HP_ -= dmg;

    if (HP_ < 0)
    {
        HP_ = 0;
    }

}

bool Monster::isDead() const
{
    return HP_ <= 0;
}

int Monster::GetMaxHP()
{
    return MaxHP_;
}

int Monster::GetHP()
{
    return HP_;
}

int Monster::GetAttack()
{
    return Attack_;
}

std::string Monster::GetName()
{
    return MonsterName_;
}

int Monster::GetLevel()
{
    return MonsterLevel_;
}