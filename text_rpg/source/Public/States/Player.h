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
    Player();
    
    ~Player();

    
    // 이름 설정
    void Init(std::string name);


    // 피해를 받아 체력을 감소시킨다.
    bool TakeDamage(int dmg);

    // 체력이 0 이하인지 판단하여 사망 여부를 판정한다.
    bool IsDead() const;

    // 경험치 획득
    void GainExp(int amount);

    // 골드 획득
    void GainGold(int amount);

    // 레벨업, 스탯증가, 체력회복
    bool TryLevelUp();

    // 아이템 효과 적용
    void UseItem();        //UseItem 
    
    
    int Attack();
    
    int GetLevel();
    
    int GetExp();
    
    int GetGold();
    
    int GetHP();
    
    int GetMaxHP();
    
    std::string GetName();
    
    void SetAttack(int newAttack);

    void SetLevel(int newLevel);

    void SetExp(int newExp);

    void SetGold(int newGold);

    void SetHP(int newHP);

    void SetMaxHP(int newMaxHP);

    
    
    
private:
    Item* item;
    std::string Name_;           // get 다 하나씩 추가해두기.
    int Level_;
    int Exp_;
    int Gold_;
    int HP_;
    int MaxHP_;
    int Attack_;
    Inventory* Inv_;
    static constexpr int HP_PER_LEVEL = 20;
    static constexpr int ATTACK_PER_LEVEL = 5;
    static constexpr int MAX_LEVEL = 10;
    static constexpr int MAX_EXP = 100;
    static constexpr int LEVEL = 1;
    static constexpr int HALF = 2;
};