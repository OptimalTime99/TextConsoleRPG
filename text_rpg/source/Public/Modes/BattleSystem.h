#pragma once

class Player;
class UIManager;
class Monster;

class BattleSystem
{
public:
    //전투를 시작한다
    bool StartBattle(const Player& p, const UIManager& ui);

    // 일반 몬스터를 생성한다.
    void SpawnMonster(const Player& p);

    // 보스 몬스터를 생성한다.
    void SpawnBoss(const Player& p);

    // 한 턴의 전투를 처리한다.
    bool ResolveTurn(const Player& p, const UIManager& ui) const;

    // 경험치와 골드르 지급한다.
    void ApplyRewards(const Player& p, const UIManager& ui);

    // 아이템 드랍을 시도한다.
    void TryDropItem(const Player& p, const UIManager& ui);

private:
    Monster* monster_;
    static constexpr double DROP_CHANCE = 0.30;
    static constexpr int EXP_REWARD = 50;
    static constexpr int GOLD_MIN = 10;
    static constexpr int GOLD_MAX = 20;
};