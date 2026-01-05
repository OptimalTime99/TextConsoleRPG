#pragma once

class Player;
class UIManager;
class Monster;
enum class GameMode;

class BattleSystem
{
public:
    //전투를 시작한다
    GameMode StartBattle(Player* p, UIManager* ui);

    // 일반 몬스터를 생성한다.
    void SpawnMonster(Player* p);

    // 보스 몬스터를 생성한다.
    void SpawnBoss(Player* p);

    // 한 턴의 전투를 처리한다.
    bool ResolveTurn(Player* p, UIManager* ui);

    // 경험치와 골드르 지급한다.
    void ApplyRewards(Player* p, UIManager* ui);

    // DROP_CHANCE의 확률로아이템 드랍을 시도한다.
    void TryDropItem(Player* p, UIManager* ui);

    // ACTION_CHANCE의 확률로 플레이어 공격인지 아이템 사용인지 결정
    bool DecideTurnAction(double probability);

    // 확률에 따른 랜덤 부울린 값을 반환
    bool GetRandomBoolean(double probability);

    // 골드 획득량을 결정
    int GetRandomGold(int min, int max);

private:
    Monster* monster_;
    Player* player_;
    static constexpr double ACTION_CHANCE = 0.5;
    static constexpr double DROP_CHANCE = 0.30;
    static constexpr int EXP_REWARD = 50;
    static constexpr int GOLD_MIN = 10;
    static constexpr int GOLD_MAX = 20;
};