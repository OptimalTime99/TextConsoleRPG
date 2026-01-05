#include "States/Monster.h"
#include "States/player.h"
#include <string>
#include <iostream>
#include <random>

//Monster::Monster(std::string MonsterName, int Level)
//    : MonsterName_(MonsterName), MonsterLevel_(Level)
//{
//
//}

int Monster::TakeDamage(int dmg)
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
    return dmg;
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

int Monster::Attack()
{
    return Attack_;
}