#pragma once

class Player;
class UIManager;
class Monster;

class BattleSystem
{
public:
    //전투를 시작한다
    bool StartBattle(Player* p, UIManager* ui);

    // 일반 몬스터를 생성한다.
    void SpawnMonster(Player* p);

    // 보스 몬스터를 생성한다.
    void SpawnBoss(Player* p);

    // 한 턴의 전투를 처리한다.
    bool ResolveTurn(Player* p, UIManager* ui);

    // 경험치와 골드르 지급한다.
    void ApplyRewards(Player* p, UIManager* ui);

    // 아이템 드랍을 시도한다.
    void TryDropItem(Player* p, UIManager* ui);

    // 랜덤 난수 얻기
    bool GetRandom(double probability);

private:
    Monster* monster_;
    static constexpr double ACTION_CHANCE = 0.5;
    static constexpr double DROP_CHANCE = 0.30;
    static constexpr int EXP_REWARD = 50;
    static constexpr int GOLD_MIN = 10;
    static constexpr int GOLD_MAX = 20;
};