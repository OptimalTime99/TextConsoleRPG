#pragma once
#include "States/Player.h"

class LevelSystem
{
public:
    // 최대레벨 반환
    int GetMaxLevel();
    // 레벨업
    int LevelUp(Player* p);

private:
    // 최대 레벨
    static constexpr int MAX_LEVEL = 10;
    // 레벨업시 증가할 체력
    static constexpr int HP_PER_LEVEL = 20;
    // 레벨업시 증가할 공격력
    static constexpr int ATTACK_PER_LEVEL = 5;
};