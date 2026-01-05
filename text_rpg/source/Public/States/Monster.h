#pragma once

#include <string>

class Monster 
{
public:
    
    Monster(std::string Monstername_, int level) 
    {

    }
   
    // 가상 소멸자
    virtual ~Monster() 
    {
    
    }
  
    // 몬스터의 스텟 생성
    virtual void GenerateStatus(int Level_) = 0;
    
    // 데미지를 받는 로직
    int TakeDamage(int dmg);

    // 사망 여부
    bool isDead()const;

    // 최대 HP
    int GetMaxHP();
    
    // 현재 HP
    int GetHP();

    // 공격 
    int GetAttack();
 
    // 몬스터 이름
    std::string GetName();
  
    
    // 몬스터 레벨
    int GetLevel();
  

    int Attack();
  

protected:
    std::string MonsterName_;
    int MonsterLevel_;
    int HP_;
    int MaxHP_;
    int Attack_;

    
    // 상수로 만든 랜덤 스탯용 멤버 변수
    static constexpr int MIN_HP = 20;
    static constexpr int MAX_HP = 30;
    static constexpr int MIN_ATK = 5;
    static constexpr int MAX_ATK = 10;
    static constexpr int MIN_BOSS_HP = 30;
    static constexpr int MAX_BOSS_HP = 45;
    static constexpr int MIN_BOSS_ATK = 8;
    static constexpr int MAX_BOSS_ATK = 15;
};