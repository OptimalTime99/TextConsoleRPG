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
    Player(const std::string name);
    
    ~Player();

    
    // 이름 설정
    void SetName(std::string name);


    // 피해를 받아 체력을 감소시킨다.
    bool TakeDamage(int dmg);

    // 체력이 0 이하인지 판단하여 사망 여부를 판정한다.
    bool IsDead() const;

    // 경험치 획득
    void GainExp(int amount);

    // 골드 획득
    void GainGold(int amount);

    // 레벨업, 스탯증가, 체력회복
    int TryLevelUp();

    
    int Attack();

    int GetAttack();
    
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

    int GetMaxExp();

    void SetMaxExp(const int value);
    
    
    
private:
    std::string Name_;           // get 다 하나씩 추가해두기.
    int Level_;
    int Exp_;
    int Gold_;
    int HP_;
    int MaxHP_;
    int Attack_;
    static constexpr int MAX_EXP = 100;     
};
