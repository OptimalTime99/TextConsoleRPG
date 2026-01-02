#pragma once

#include <string>

class Monster 
{
public:

    // 몬스터 생성자
    Monster(std::string MonsterName,int Level,bool bidBoos);

    // 몬스터의 스텟 생성
    void GenerateNomal(int Level);
    
    // 보스 몬스터의 스텟 생성
    void GenerateBoss(int Level);
    
    // 데미지를 받는 로직
    void TakeDamage(int dmg);

    // 사망 여부
    bool isDead()const;

    // 최대 HP
    int GetMaxHP();
    
    // 현재 HP
    int GetHP();

    // 공격 
    int GetAttack();

    // 몬스터 이름
    std::string GetMonsterName();
    
    // 몬스터 레벨
    int GetLevel();

private:
    std::string MonsterName_;
    int MonsterLevel_;
    int HP_;
    int MaxHP_;
    int Attack_;
    bool bisBoss_;
    
    // 상수로 만든 랜덤 스탯용 멤버 변수
    const int MIN_HP = 20;
    const int MAX_HP = 30;
    const int MIN_ATK = 5;
    const int MAX_ATK = 10;
    const int BOSS_MIN_HP = 30;
    const int BOSS_MAX_HP = 45;
    const int MIN_BOSS_ATK = 8;
    const int MAX_BOSS_ATK = 15;
};