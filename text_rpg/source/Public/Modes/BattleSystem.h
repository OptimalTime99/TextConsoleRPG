#pragma once

class Player;
class UIManager;

class BattleSystem
{
public:
    void StartBattle(Player* p, UIManager* ui);
    void SpawnMonster();
    void SpawnBoss();
    void ResolveTurn(Player* p, UIManager* ui);
    void ApplyRewards(Player* p, UIManager* ui);
    void TryDropItem(Player* p, UIManager* ui);

private:
    static constexpr double DROP_CHANCE = 0.30;
    static constexpr int EXP_REWARD = 50;
    static constexpr int GOLD_MIN = 10;
    static constexpr int GOLD_MAX = 20;
};