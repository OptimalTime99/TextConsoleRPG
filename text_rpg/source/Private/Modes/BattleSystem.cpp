#include "Modes/BattleSystem.h"
#include "States/Monster.h"
#include "States/Player.h"
#include "Types/GameMode.h"
#include "UI/UIManager.h"
#include "States/NormalMonster.h"
#include "States/BossMonster.h"
#include "Types/ItemType.h"
#include "Types/StatusType.h"
#include "Modes/LevelSystem.h"
#include <random>


BattleSystem::BattleSystem(Player* p, UIManager* ui, Inventory* inv) 
    : player_(p), uiManager_(ui), Inventory_(inv)
{
    monster_ = nullptr;
    level_ = new LevelSystem();
    playerBuff_ = 0;
}

BattleSystem::~BattleSystem()
{
    delete level_;
}

GameMode BattleSystem::StartBattle()
{
    bool bIsSomeoneDead = false;
    SpawnMonster();

    uiManager_->PrintBattleStart(player_, monster_);

    while (true)
    {
        // 턴을 진행하고 몬스터나 플레이어가 사망하면
        // if문에서 반목문 탈출 -> 전투 종료
        if (bIsSomeoneDead = ResolveTurn())
        {
            break;
        }
    }

    // 전투 종료시 플레이어 버프 초기화
    playerBuff_ = 0;

    // 몬스터 사망 시 보상 분배
    if (monster_->isDead())
    {
        uiManager_->PrintVictory();
        ApplyRewards();
        return GameMode::APPLY_RWARDS;

    }
    // 플레이어 사망시 게임 종료
    else if (player_->IsDead())
    {
        uiManager_->PrintGameOver();
        return GameMode::GAMEOVER_MODE;
    }

    return GameMode::BATTLE_MODE;
}

void BattleSystem::SpawnMonster()
{
    monster_ = new NormalMonster("test", player_->GetLevel());
}

void BattleSystem::SpawnBoss()
{
    monster_ = new BossMonster("Boss_test", player_->GetLevel());
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
        int damage = player_->Attack() + playerBuff_;
        int finalDamage = monster_->TakeDamage(damage);
        uiManager_->PrintMonsterTakeDamage(monster_, finalDamage);

        // 몬스터 사망시 함수 종료
        if (monster_->isDead())
        {
            delete monster_;
            return true;
        }
    }
    else
    { // 아이템 사용 파트, 버프 처리 체력 증가 처리 등
        if (!UseItem()) // 아이템 사용을 실패 하면
        {
            // 아이템 사용 못했으므로 안내하는 로그 출력
            uiManager_->PrintAttackInsteadUseItem();

            int damage = player_->Attack() + playerBuff_;
            int finalDamage = monster_->TakeDamage(damage);
            uiManager_->PrintMonsterTakeDamage(monster_, finalDamage);

            // 몬스터 사망시 함수 종료
            if (monster_->isDead())
            {
                delete monster_;
                return true;
            }
        }
    }
    
    // 몬스터 사망시 아래는 수행하지 않음


    int damage = monster_->Attack() + playerBuff_;
    int finalDamage = player_->TakeDamage(damage);
    uiManager_->PrintPlayerTakeDamage(player_, finalDamage);
    if (player_->IsDead())
    {
        return true;
    }

    return false;
}

bool BattleSystem::UseItem()
{
    // 아이템 사용 파트, 버프 처리 체력 증가 처리 등
    // 어떤 아이템을 사용할지 결정 ->
    // 현재 체력이 최대 체력의 50%이하이고 체력 포션이 있다면 체력 포션 사용
    // 체력이 50%이상이고 공격력 포션이 있으면 공격력 포션 사용
    // 둘 다 없으면 공격
    const Item* whichItem = nullptr;
    
    // 현재 체력이 최대 체력의 50%이하이고 체력 포션이 있다면 체력 포션 사용
    if (((double)player_->GetHP() / player_->GetMaxHP()) < 0.5 && Inventory_->GetItemCount(ItemType::LowHealthPotion) > 0)
    { 
        // 아이템 사용하면 트루 반환
        whichItem = Item::GetData(ItemType::LowHealthPotion);
        int value = whichItem->GetEffect()[StatusType::HP];
        player_->SetHP(player_->GetHP() + value);
        Inventory_->RemoveItem(ItemType::LowHealthPotion, 1);
        uiManager_->PrintUseItem(whichItem);
        return true;
    }
    else if(Inventory_->GetItemCount(ItemType::LowAttackPotion) > 0)
    {
        whichItem = Item::GetData(ItemType::LowAttackPotion);
        int value = whichItem->GetEffect()[StatusType::ATK];
        playerBuff_ += value; // 임시
        Inventory_->RemoveItem(ItemType::LowAttackPotion, 1);
        uiManager_->PrintUseItem(whichItem);
        return true;
    }
    else
    {
        // 아이템 재고가 둘 다 없으면 사용을 못했으므로 거짓반환
        return false;
    }

    return false;
}

void BattleSystem::ApplyRewards()
{
    player_->GainExp(EXP_REWARD);
    int levelCount = level_->LevelUp(player_);
    int golds = GetRandomGold(GOLD_MIN, GOLD_MAX);
    player_->GainGold(golds);

    uiManager_->PrintFixedRewards(EXP_REWARD, levelCount, golds); // 레벨 매개변수 수정 필요


    TryDropItem();
}

void BattleSystem::TryDropItem()
{
    if (GetRandomBoolean(DROP_CHANCE))
    {
        const Item* whichItem = nullptr;

        // 50% 확률로 체력포션과 공격력 증가 포션을 선택
        if (GetRandomBoolean(WHICH_ITEM))
        {
            // 인벤토리에 추가후 UI출력 명령
            whichItem = Item::GetData(ItemType::LowHealthPotion);
            Inventory_->AddItem(whichItem->GetName(), 1);
            uiManager_->PrintItemRewards(whichItem->GetName());
        }
        else
        {
            // 인벤토리에 추가후 UI출력 명령
            whichItem = Item::GetData(ItemType::LowAttackPotion);
            Inventory_->AddItem(whichItem->GetName(), 1);
            uiManager_->PrintItemRewards(whichItem->GetName());
        }

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
