#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "States/Item.h"
#include "States/Inventory.h"
#include <random>

class Player 
{
public:
    Player(int level, int hp, int attack, int exp);
    
    ~Player();
    
    // 이름 설정
    void Init(std::string name);

    // 공격 or 아이템 사용
    void DecideBattleAction();   // enum?

    // 피해를 받아 체력을 감소시킨다.
    bool TakeDamage(int dmg);

    // 체력이 0 이하인지 판단하여 사망 여부를 판정한다.
    bool IsDead() const;

    // 경험치 획득
    void GainExp(int amount);

    // 골드 획득
    void GainGold(int amount);

    // 레벨업, 스탯증가, 체력회복
    void TryLevelUp();

    // 아이템 효과 적용
    /*void ApplyItemEffect(Item item);*/

    // 공격
    int GetAttack();

    // 아이템 사용

    // 랜덤
    bool Rand();

    void IncreaseHP(int Value);
    
    
private:
    /*Item* item;*/
    std::string Name_;
    int Level_;
    int Exp_;
    int Gold_;
    int HP_;
    int MaxHP_;
    int Attack_;
    /*Inventory* Inv_;*/
};