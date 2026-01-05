#pragma once
#include "States/Player.h"

class LevelSystem
{
public:

    int GetMaxLevel();
    
    int LevelUp(Player* p);

private:
    static constexpr int MAX_LEVEL = 10;
    static constexpr int HP_PER_LEVEL = 20;
    static constexpr int ATTACK_PER_LEVEL = 5;
};