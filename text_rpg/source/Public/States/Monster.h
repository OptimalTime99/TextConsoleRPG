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
    
private:
    std::string MonsterName_;
    int MonsterLevel_;
    int HP_;
    int Attack_;
    bool bisBoss_;
};