#include "States/Player.h"


Player::Player(const std::string name) : Name_(name)
{
    this->Level_ = 1;
    this->HP_ = 200;
    this->Attack_ = 30;
    this->Exp_ = 0;
    this->MaxHP_ = 200;
    this->Gold_ = 0;

}

Player::~Player() {}



void Player::GainExp(int amount)
{
    Exp_ += amount;
}

void Player::GainGold(int amount)
{
    Gold_ += amount;
}

bool Player::IsDead() const
{
    if (HP_ <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Player::TakeDamage(int dmg)
{
    if (dmg < 0)
        dmg = 0;
    HP_ -= dmg;

    if (HP_ < 0)
        HP_ = 0;

    return dmg;
}

//int Player::TryLevelUp()  //레벨업시 true 
//{
//    int count = 0;
//
//    while (Exp_ >= MAX_EXP)      // 10 ㅡ> 상수화 if (Level_ < MAX_LEVEL) 
//    {
//
//        if (Level_ < MAX_LEVEL) // 100 ㅡ> 상수화
//        {
//
//            Level_++;
//            MaxHP_ += LEVEL * HP_PER_LEVEL;  // 20 ㅡ> 상수화
//            HP_ = MaxHP_;
//            Attack_ += LEVEL * ATTACK_PER_LEVEL;  // 5 ㅡ> 상수화       // 원종님한테 전달
//            Exp_ -= MAX_EXP;
//
//            count++;
//        }
//        else
//        {
//            break;
//        }
//    }
//    return count;
//}

void Player::SetName(std::string name)
{
    Name_ = name;
}



int Player::Attack()
{
    return Attack_;
}

int Player::GetAttack()
{
    return Attack_;
}

int Player::GetLevel()
{
    return Level_;
}

int Player::GetExp()
{
    return Exp_;
}

int Player::GetGold()
{
    return Gold_;
}

int Player::GetHP()
{
    return HP_;
}

int Player::GetMaxHP()
{
    return MaxHP_;
}

std::string Player::GetName()
{
    return Name_;
}

int Player::GetMaxExp()
{
    return MAX_EXP;
}

void Player::SetAttack(int newAttack)
{
    Attack_ = newAttack;
}

void Player::SetLevel(int newLevel)
{
    Level_ = newLevel;
}

void Player::SetExp(int newExp)
{
    Exp_ = newExp;
}

void Player::SetGold(int newGold)
{
    Gold_ = newGold;
}

void Player::SetHP(int newHP)
{
    if (newHP < MaxHP_)
    {
        HP_ = newHP;
    }
}

void Player::SetMaxHP(int newMaxHP)
{
    MaxHP_ = newMaxHP;
}

