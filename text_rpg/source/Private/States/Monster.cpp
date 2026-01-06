#include "States/Monster.h"
#include <string>


Monster::Monster( int Level) 
    : Name_(Name_),MonsterLevel_(Level),HP_(0),MaxHP_(0),Attack_(0)
{

}

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
    return Name_;
}

int Monster::GetLevel()
{
    return MonsterLevel_;
}

int Monster::Attack()
{
    return Attack_;
}