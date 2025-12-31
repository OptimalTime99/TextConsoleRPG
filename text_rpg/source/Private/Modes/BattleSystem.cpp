#include "Modes/BattleSystem.h"
#include "States/Monster.h"


void BattleSystem::StartBattle(const Player& p, const UIManager& ui)
{
    SpawnMonster();
}

void BattleSystem::SpawnMonster()
{
    monster_ = new Monster();
}

void BattleSystem::SpawnBoss()
{
}

void BattleSystem::ResolveTurn(const Player& p, const UIManager& ui)
{
}

void BattleSystem::ApplyRewards(const Player& p, const UIManager& ui)
{
}

void BattleSystem::TryDropItem(const Player& p, const UIManager& ui)
{
}
