#include "States/Player.h"
#include <string>

// 생성자 초기화
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


// 획득한 경험치
void Player::GainExp(int amount)
{
    Exp_ += amount;
}
// 획득한 골드
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
// 받는 피해량
int Player::TakeDamage(int dmg)
{   // 데미지가 0보다 작을 때 0으로 유효성검사
    if (dmg < 0)
        dmg = 0;
    HP_ -= dmg;
    // HP가 0보다 작을 때 0으로 유효성검사
    if (HP_ < 0)
        HP_ = 0;
    // 입은 데미지 반환
    return dmg;
}

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
    if (newHP > MaxHP_)
        newHP = MaxHP_;
        
        HP_ = newHP;
    
}

void Player::SetMaxHP(int newMaxHP)
{
    MaxHP_ = newMaxHP;
}
