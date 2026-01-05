#include "Modes/LevelSystem.h"

int LevelSystem::LevelUp(Player* p)
{   // 레벨업을 몇번 했는지 세주는 용도
    int count = 0;
    // 현재 레벨
    int Level = p->GetLevel();
    // 최대체력
    int MaxHP = p->GetMaxHP();
    // 현재 경험치
    int Exp = p->GetExp();
    // 최대 경험치
    int MaxExp = p->GetMaxExp();
    // 현재 공격력
    int Attack = p->Attack();
    // 최대경험치보다 크거나 같을 시
    while (Exp >= MaxExp)
    {   // 레벨이 최대레벨보다 작을 때
        if (Level < MAX_LEVEL)
        {   
            Level++;
            p->SetLevel(Level);
            // 레벨업시 체력 증가
            p->SetMaxHP(MaxHP + HP_PER_LEVEL);
            // 현재 체력을 최대만큼 회복
            p->SetHP(MaxHP);
            // 레벨업시 공격력 증가    
            p->SetAttack(Attack + ATTACK_PER_LEVEL);
            // 레벨업 후 남은 경험치
            p->SetExp(Exp - MaxExp);
            //몇번 레벨업했는지
            count++;
        }
        else
        {
            break;
        }
    }
    return count;
}

int LevelSystem::GetMaxLevel()
{
    return MAX_LEVEL;
}