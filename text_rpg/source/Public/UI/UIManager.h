#pragma once
#include "UIHelper.h"
#include "States/Player.h"
#include "States/Monster.h"
#include "Modes/AchievementSystem.h"
#include "Types/ItemType.h"
#include "Windows.h"
#include "conio.h"
#include <iostream>
#include <string>

class UIManager
{
public:
    UIManager(Inventory* inven) : Inventory_(inven)
    {
        UIHelper_ = new UIHelper;
        UIHelper_->SetConsoleSetting();
    }
    ~UIManager()
    {
        delete UIHelper_;
    }

public:
    // 타이틀 화면을 출력하고, 유저의 선택지에 따른 값을 반환.
    bool PrintTitle();

    //게임종료 전에 종료를 유저에게 알리는 화면 출력.
    void PrintOff();

    // 게임오버 화면을 출력하고, 유저의 선택지에 따른 값을 반환.
    bool PrintGameOver();

    // 엔딩화면을 출력.
    void PrintEndingEvent();

    void SetInventory(Inventory* inven);

public:
    // 캐릭터 생성 UI
    std::string PrintCreateCharacter();

    // 플레이어 상태 출력
    void PrintPlayerStatus(Player* player);

    // 몬스터 상태 출력
    void PrintMonsterStatus(Monster* monster);

    // 킬 카운트 출력
    void PrintKillCount(AchievementSystem* achieve);

    void PrintInventory(Inventory* inven);

    // 전투대상 조우시 출력
    void PrintBattleStart(Player* p, Monster* m, AchievementSystem* achieve);

    // 몬스터가 데미지를 받을 때 출력
    void PrintMonsterTakeDamage(Monster* m, int finaldamage);

    // 플레이어가 데미지를 받을 때 출력
    void PrintPlayerTakeDamage(Player* p, int finaldamage);

    // 아이템 사용 시 출력로그
    void PrintUseItem(const Item* item);

    void PrintAttackInsteadUseItem();

    // 승리 시 출력
    void PrintVictory(const std::string& monstername, AchievementSystem* achieve);

    // 일반 보상 획득 출력
    void PrintFixedRewards(int exp_reward, int levelup_count, int gain_golds);

    // 아이템 보상 획득 출력
    void PrintItemRewards(ItemType itemtype);

    // 상점 입장여부 선택 UI
    bool ShopEnterChoice();

    // 상점 출력
    int PrintShop(Player* p);

    // 상점 구매 출력 및 선택
    int PrintShopBuyChoice(int x, int y, const std::deque<Item>& catalog);

    // 상점 판매 출력 및 선택
    int PrintShopSellChoice(int x, int y, Inventory* inven);

    // 구매 혹은 판매액 총 가격 측정
    int CountPrice(int x, int y, const int max, int userchoice, const std::deque<Item>& catalog, bool isPurchase, double SellRate);

    // 상점 로그를 띄우는 함수
    void PrintShoplog(const std::string& shoplog);

private:
    UIHelper* UIHelper_;
    Inventory* Inventory_;
};