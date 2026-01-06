#pragma once

#include "States/Monster.h"

class BossMonster : public Monster
{
public:
    BossMonster(int Level);

    void GenerateStatus(int Level) override;


    static constexpr int MIN_HP = 30;
    static constexpr int MAX_HP = 45;
    static constexpr int MIN_ATK = 8;
    static constexpr int MAX_ATK = 15;
};