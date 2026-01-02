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
    if (IsAttack(ACTION_CHANCE))
    {
        int damage = p->Attack();
        // ui->공격 그리기();
        monster_->TakeDamage(damage);
        // ui->데미지 받기그리기();

        // 몬스터 사망시 함수 종료
        if (monster_->isDead())
        {
            return true;
        }
    }
    else
    {
        p->UseItem();
        // ui->아이템 사용 그리기();
    }
    
    // 몬스터 사망시 아래는 수행하지 않음
    int damage = monster_->Attack();
    p->TakeDamage(damage);
    if (p->IsDead())
    {
        return true;
    }

    return false;
}

void BattleSystem::ApplyRewards(Player* p, UIManager* ui)
{
}

void BattleSystem::TryDropItem(Player* p, UIManager* ui)
{
}

bool BattleSystem::IsAttack(double probability)
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
