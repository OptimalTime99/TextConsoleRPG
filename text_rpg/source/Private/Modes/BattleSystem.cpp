#include "Modes/BattleSystem.h"
#include "States/Monster.h"
#include "States/Player.h"
#include "Types/GameMode.h"
#include "UI/UIManager.h"
#include <random>


BattleSystem::BattleSystem(Player* p, Item* item, UIManager* ui) 
    : player_(p), items_(item), uiManager_(ui)
{
    monster_ = nullptr;
}

GameMode BattleSystem::StartBattle()
{
    bool bIsSomeoneDead = false;
    SpawnMonster();

    uiManager_->PrintBattleStart(player_, monster_);

    while (true)
    {
        // 턴을 진행하고 몬스터나 플레이어가 사망하면
        // if문에서 반목문 탈출
        if (bIsSomeoneDead = ResolveTurn())
        {
            break;
        }
    }

    // 몬스터 사망 시 보상 분배
    if (monster_->isDead())
    {
        uiManager_->PrintVictory();
        ApplyRewards();
        return GameMode::APLLY_RWARDS;

    }
    // 플레이어 사망시 게임 종료
    else if (player_->IsDead())
    {
        uiManager_->PrintGameOver();
        return GameMode::GAMEOVER_MODE;
    }
}

void BattleSystem::SpawnMonster()
{
    monster_ = new Monster("test", player_->GetLevel(), false);
}

void BattleSystem::SpawnBoss()
{
    monster_ = new Monster("Boss_test", player_->GetLevel(), true);
}

// 플레이어 행동 결정 <- BattleSystem이
// 아이템 사용 or 공격
// if(공격)
//  플레이어가 공격 -> 몬스터가 데미지 받기
//  몬스터 사망했나?
// if(아이템사용)
//  플레이어 아이템 사용
// 몬스터가 공격 -> 플레이어가 데미지 받기
// 플레이어 사망했나?
bool BattleSystem::ResolveTurn()
{
    // 플레이어 선공격
    if (DecideTurnAction(ACTION_CHANCE))
    {
        int damage = player_->Attack();
        int finalDamage = monster_->TakeDamage(damage);
        uiManager_->PrintMonsterTakeDamage(monster_); // ui에게 finalDamage 넘겨주기

        // 몬스터 사망시 함수 종료
        if (monster_->isDead())
        {
            delete monster_;
            return true;
        }
    }
    else
    { // 아이템 사용 파트, 버프 처리 체력 증가 처리 등
        UseItem();
    }
    
    // 몬스터 사망시 아래는 수행하지 않음


    int damage = monster_->Attack();
    int finalDamage = player_->TakeDamage(damage);
    uiManager_->PrintPlayerTakeDamage(player_); // ui에게 finalDamage 넘겨주기
    if (player_->IsDead())
    {
        return true;
    }

    return false;
}

void BattleSystem::UseItem()
{
    // 아이템 사용 파트, 버프 처리 체력 증가 처리 등
    // 어떤 아이템을 사용할지 결정 ->
    // 현재 체력이 최대 체력의 50%이하이고 체력 포션이 있다면 체력 포션 사용
    // 체력이 50%이상이고 공격력 포션이 있으면 공격력 포션 사용
    // 둘 다 없으면 공격
    //Item* whichItem/* = p->UseItem()*/;
    //if (whichItem != nullptr)
    //{
    //    switch (whichItem->GetType())
    //    {
    //    case ItemType::HealPotion:
    //        player_->SetHP(player_->GetHP() + whichItem.GetValue()); // Set함수에서 MaxHP넘지 않게 유효처리 부탁
    //        uiManager_->PrintUseItem(whichItem);
    //        break;
    //    case ItemType::AtkPotion:
    //        // 해당 전투가 끝나면 다시 원래 공격력으로
    //        player_->SetAttack(p->GetAttack() + whichItem.GetValue());
    //        uiManager_->PrintUseItem(whichItem);
    //        break;
    //    default:
    //        break;
    //    }
    //}
    // uiManager_->아이템 사용 그리기(ItemInfo);
}

void BattleSystem::ApplyRewards()
{
    player_->GainExp(EXP_REWARD);
    /*if (bool bIsLevelUp = p->TryLevelUp())
    {
        
    }*/
    int golds = GetRandomGold(GOLD_MIN, GOLD_MAX);
    player_->GainGold(golds);

    // uiManager_->PrintFixedRewards(EXP_REWARD, level, golds); // 레벨 매개변수 수정 필요


    TryDropItem();
}

void BattleSystem::TryDropItem()
{
    if (GetRandomBoolean(DROP_CHANCE))
    {
        // 아이템 리스트에서 아이템 받고
        // uiManager_->PrintItemRewards();
        // 플레이어 인벤토리에 추가
    }
}


// 유틸리티 클래스화 생각
bool BattleSystem::DecideTurnAction(double probability)
{
    return GetRandomBoolean(ACTION_CHANCE);
}

bool BattleSystem::GetRandomBoolean(double probability)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::bernoulli_distribution dis(probability);

    return dis(gen);
}

int BattleSystem::GetRandomGold(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    static std::uniform_int_distribution<int> dis(min, max);

    return dis(gen);
}
