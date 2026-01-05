#include "Modes/LevelSystem.h"

int LevelSystem::LevelUp(Player* p)
{
    int count = 0;
    int Level = p->GetLevel();
    int MaxHP = p->GetMaxHP();
    int Exp = p->GetExp();
    int MaxExp = p->GetMaxExp();
    int Attack = p->Attack();

    while (Exp >= MaxExp)
    {
        if (Level < MAX_LEVEL)
        {
            Level++;
            p->SetLevel(Level);
            p->SetMaxHP(MaxHP + ONE * HP_PER_LEVEL);
            p->SetHP(MaxHP);
            p->SetAttack(Attack + ONE * ATTACK_PER_LEVEL);
            p->SetExp(Exp - MaxExp);

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