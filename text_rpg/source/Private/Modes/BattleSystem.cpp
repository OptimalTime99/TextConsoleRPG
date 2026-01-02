#include "Modes/BattleSystem.h"
#include "States/Monster.h"
#include "States/Player.h"
#include "Types/GameMode.h"
#include <random>


GameMode BattleSystem::StartBattle(Player* p, UIManager* ui)
{
    bool bIsSomeoneDead = false;
    SpawnMonster(p);

    // ui->PrintBattleStart(p, monster);

    while (true)
    {
        // 턴을 진행하고 몬스터나 플레이어가 사망하면
        // if문에서 반목문 탈출
        if (bIsSomeoneDead = ResolveTurn(p, ui))
        {
            break;
        }
    }

    // 몬스터 사망 시 보상 분배
    if (monster_->isDead())
    {
        // ui->플레이어 승리 그리기();
        ApplyRewards(p, ui);
    }
    // 플레이어 사망시 게임 종료
    else if (p->IsDead())
    {
        // ui->PrintGameOver();
        return GameMode::GAMEOVER_MODE;
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

// 플레이어 행동 결정 <- BattleSystem이
// 아이템 사용 or 공격
// if(공격)
//  플레이어가 공격 -> 몬스터가 데미지 받기
//  몬스터 사망했나?
// if(아이템사용)
//  플레이어 아이템 사용
// 몬스터가 공격 -> 플레이어가 데미지 받기
// 플레이어 사망했나?
bool BattleSystem::ResolveTurn(Player* p, UIManager* ui)
{
    // 플레이어 선공격
    if (DecideTurnAction(ACTION_CHANCE))
    {
        int damage = p->Attack();
        monster_->TakeDamage(damage);
        // ui->데미지 받기그리기(monster_);

        // 몬스터 사망시 함수 종료
        if (monster_->isDead())
        {
            delete monster_;
            return true;
        }
    }
    else
    { // 아이템 사용 파트, 버프 처리 체력 증가 처리 등
        // ItemInfo witchItem = p->UseItem();
        // ui->아이템 사용 그리기(ItemInfo);
    }
    
    // 몬스터 사망시 아래는 수행하지 않음


    int damage = monster_->Attack();
    p->TakeDamage(damage);
    // ui->플레이어 데미지 받기 출력(p);
    if (p->IsDead())
    {
        return true;
    }

    return false;
}

void BattleSystem::ApplyRewards(Player* p, UIManager* ui)
{
    p->GainExp(EXP_REWARD);
    // ui->PrintEXP(EXP_REWARD);
    //if (bool bIsLevelUp = p->TryLevelUp())
    //{
    //    // ui->PrintLevelIP();
    //}
    int golds = GetRandomGold(GOLD_MIN, GOLD_MAX);

    p->GainGold(golds);
    // ui->PrintGainGold(golds);


    TryDropItem(p, ui);
}

void BattleSystem::TryDropItem(Player* p, UIManager* ui)
{
    if (GetRandomBoolean(DROP_CHANCE))
    {
        // 아이템 리스트에서 아이템 받고
        // ui->아이템획득 로그();
        // 플레이어 인벤토리에 추가
    }
}

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
