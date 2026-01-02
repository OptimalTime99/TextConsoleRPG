#include "Modes/BattleSystem.h"
#include "States/Monster.h"
#include "States/Player.h"
#include <random>


bool BattleSystem::StartBattle(Player* p, UIManager* ui)
{
    bool IsSomeoneDead = false;

    SpawnMonster(p);
    while (!IsSomeoneDead)
    {
        if (ResolveTurn(p, ui))
        {
            IsSomeoneDead = true;
        }
    }
}

void BattleSystem::SpawnMonster(Player* p)
{
    monster_ = new Monster("test", p->GetLevel(), false);
}

void BattleSystem::SpawnBoss(Player* p)
{
    monster_ = new Monster("Boss_test", p->GetLevel(), true);
}

bool BattleSystem::ResolveTurn(Player* p, UIManager* ui)
{
}

void BattleSystem::ApplyRewards(Player* p, UIManager* ui)
{
}

void BattleSystem::TryDropItem(Player* p, UIManager* ui)
{
}

bool BattleSystem::GetRandom(double probability)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::bernoulli_distribution d(probability);

    return d(gen);
}
