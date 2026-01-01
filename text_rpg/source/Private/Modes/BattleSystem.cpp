#include "Modes/BattleSystem.h"
#include "States/Monster.h"


//bool BattleSystem::StartBattle(const Player& p, const UIManager& ui)
//{
//    bool IsSomeoneDead = false;
//
//    SpawnMonster(p);
//    while (!IsSomeoneDead)
//    {
//        if (ResolveTurn(p, ui))
//        {
//            IsSomeoneDead = true;
//        }
//    }
//}

void BattleSystem::SpawnMonster(const Player& p)
{
    //monster_ = new Monster("test", p.GetLevel(), false);
}

void BattleSystem::SpawnBoss(const Player& p)
{
    //monster_ = new Monster("Boss_test", p.GetLevel(), true);
}

//bool BattleSystem::ResolveTurn(const Player& p, const UIManager& ui) const
//{
//    bool IsSomoneDead = false;
//    //p.DecideBattleAction();
//    
//
//}

void BattleSystem::ApplyRewards(const Player& p, const UIManager& ui)
{
}

void BattleSystem::TryDropItem(const Player& p, const UIManager& ui)
{
}
