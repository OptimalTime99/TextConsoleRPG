#pragma once

class LevelSystem;
class Player;
class UIManager;
class Monster;
enum class GameMode;
class Item;
class Inventory;
class AchievementSystem;

class BattleSystem
{
public:
    // 생성자
    BattleSystem(Player* p, UIManager* ui, Inventory* inv, AchievementSystem* achv);

    ~BattleSystem();

    //전투를 시작한다
    GameMode StartBattle();

    // 일반 몬스터를 생성한다.
    void SpawnMonster(bool isBoss);

    // 한 턴의 전투를 처리를 처리하고 몬스터나 플레이어의 사망 여부 반환
    bool ResolveTurn();

    bool UseItem();

    // 경험치와 골드르 지급한다.
    void ApplyRewards();

    // DROP_CHANCE의 확률로아이템 드랍을 시도한다.
    void TryDropItem();

    // ACTION_CHANCE의 확률로 플레이어 공격인지 아이템 사용인지 결정
    bool DecideTurnAction(double probability);

private:
    LevelSystem* level_; // battle시스템이 메모리 관리
    AchievementSystem* Achieve_; // gamemanager 메모리 관리
    Player* player_; // gamemanager가 메모리 관리
    Monster* monster_; // battle시스템이 메모리 관리
    Inventory* Inventory_; // gamemanager가 메모리 관리
    UIManager* uiManager_; // gamemanager가 메모리 관리

    int playerBuff_;
    static constexpr double ACTION_CHANCE = 0.5;
    static constexpr double WHICH_ITEM = 0.5;
    static constexpr double DROP_CHANCE = 0.30;
    static constexpr int EXP_REWARD = 50;
    static constexpr int GOLD_MIN = 10;
    static constexpr int GOLD_MAX = 20;
};