#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "States/Item.h"
#include "States/Inventory.h"


class Player 
{
public:
    Player(const std::string name);
    
    ~Player();

    
    // 이름 설정
    void SetName(std::string name);


    // 피해를 받아 체력을 감소시킨다.
    int TakeDamage(int dmg);

    // 체력이 0 이하인지 판단하여 사망 여부를 판정한다.
    bool IsDead() const;

    // 경험치 획득
    void GainExp(int amount);

    // 골드 획득
    void GainGold(int amount);


    // 공격력 반환
    int Attack();
    // 데미지 반환
    int GetAttack();
    // 레벨 반환
    int GetLevel();
    // 경험치 반환
    int GetExp();
    // 골드 반환
    int GetGold();
    // 체력 반환
    int GetHP();
    // 최대체력 반환
    int GetMaxHP();
    // 이름 반환
    std::string GetName();
    // 데미지 설정
    void SetAttack(int newAttack);
    // 레벨을 설정
    void SetLevel(int newLevel);
    // 경험치 설정
    void SetExp(int newExp);
    // 골드 설정
    void SetGold(int newGold);
    // 체력 설정
    void SetHP(int newHP);
    // 최대체력 설정
    void SetMaxHP(int newMaxHP);
    // 최대경험치 반환
    int GetMaxExp();

    
    
    
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
