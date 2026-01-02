#include "States/Player.h"


Player::Player()
{
    this->Level_ = 1;
    this->HP_ = 200;
    this->Attack_ = 30;
    this->Exp_ = 0;
    this->MaxHP_ = 200;
    this->Gold_ = 0;
    this->Name_ = "";
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

bool Player::TakeDamage(int dmg)
{
    if (dmg < 0)
        dmg = 0;
    HP_ -= dmg;
    if (IsDead())
    {
        return true;
    }
}

bool Player::TryLevelUp()  //레벨업시 true 
{   
    if (Level_ < MAX_LEVEL)      // 10 ㅡ> 상수화
    {
        if (Exp_ >= MAX_EXP) // 100 ㅡ> 상수화
        {
            Level_++;
            MaxHP_ += LEVEL * HP_PER_LEVEL;  // 20 ㅡ> 상수화
            HP_ = MaxHP_;
            Attack_ += LEVEL * ATTACK_PER_LEVEL;  // 5 ㅡ> 상수화
            if (Exp_ > 100) // 한번 더 
            {
                Exp_ -= MAX_EXP;
                TryLevelUp();
            }
            else
            {
                Exp_ = 0;
            }
            return true;    
        }
    }
}

void Player::SetName(std::string name)
{
    Name_ = name;
}


int Player::Attack()
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
    HP_ = newHP;
}

void Player::SetMaxHP(int newMaxHP)
{
    MaxHP_ = newMaxHP;
}



//Item Player::UseItem()       // 후에 다시 
//{
//    if (Inv_->IsEmpty() != true)   // Empty == 비어있을 때 true를 반환함
//    {
//        if (HP_ < MaxHP_ / HALF)
//        // 힐포션 조회 후 있으면      GetItem(?) 
//         // 사용 ㅡ> 적용 ㅡ> 사용한 아이템 삭제 
//         // HP_ += HPPOTION;        TakeItem();
//          
//        else 
//        // 공업포션 조회 후 있으면  GetItem(?) 
//         // 사용 ㅡ> 적용 ㅡ> 사용한 아이템 삭제 
//         // Attack_ += ATTACKPOTION;    TakeItem(); 
//        반환형 
//    }
//}
//정보전달 >> 
// 어떤 물약을 사용할 지     GetItem 반환
// 사용한 물약의 남은 개수   TakeItem 반환 
//스탯안건들고
//반환형으로
//
//item.h 에 있는 enum 이해필요
//erase 도 이해필요
//vector 이해필요
//


    


