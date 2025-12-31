#include "States/Player.h"


Player::Player(int level = 1, int hp = 200, int attack = 30, int exp = 0)
{
    this->Level_ = level;
    this->HP_ = hp;
    this->Attack_ = attack;
    this->Exp_ = exp;
    this->MaxHP_ = hp;
    this->Gold_ = 0;
}

Player::~Player()
{
    std::cout << "gg" << std::endl;
}


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

    // return HP_ <= 0; 챗지피티식
}

bool Player::TakeDamage(int dmg)
{
    HP_ -= dmg;
    if (IsDead())
    {
        return true;
    }
}

void Player::TryLevelUp()
{   
    if (Level_ < 10)
    {
        if (Exp_ >= 100)
        {
            Level_++;
            MaxHP_ += Level_ * 20;
            HP_ = MaxHP_;
            Attack_ += Level_ * 5;
        }
    }
}

void Player::Init(std::string name)
{
    Name_ = name;
}


int Player::GetAttack()
{
    return Attack_;
}

bool Rand()
{
    return rand() % 2 == 0; 
}

void Player::IncreaseHP(int Value)
{
    HP_ += Value;
}

//void Player::ApplyItemEffect(Item item)
//{
//    if (HP_ <= 50) // 언제 쓸지 
//        // 아이템 사용 조건
//        // Item쪽 함수 호출
//    {
//        Itme->ApplyTo(ItemType type); 
//    }
//}

//void Player::DecideBattleAction()
//{
//    if (Rand())
//    {
//        공격함수();
//    }
//    else
//    {
//        find(), ApplyItemEffect(Item item), remove() 
//    }
//}

// 2분의 1확률로 공격 or 아이템 사용
// 아이템 사용이면 아이템 있는지 여부, 조건으로 어떤 아이템을 사용할지
// 아이템적용. 인벤토리에 있는 아이템을 제거

// Invetory->find(); <<  
// if 1번 hp, 2번 atk
// ApplyItemEffect(Item item);
// remove()

