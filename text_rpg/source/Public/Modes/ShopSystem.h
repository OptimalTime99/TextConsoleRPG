#pragma once
#include <deque>
#include <cmath>
#include "States/Player.h"
#include "States/Item.h"
#include "States/Inventory.h"
#include "Types/ItemType.h"

class UIManager;
enum class GameMode;

class ShopSystem
{
public:
    ShopSystem()
    {

    }
    ~ShopSystem()
    {

    }

    // 상점 게임모드
    GameMode Shop(Player* p, UIManager* ui);

    //입장 선택
    GameMode EnterChoice(Player* p, UIManager* ui);

    // 구매
    void Buy(Inventory* inven, int catalogindex, UIManager* ui);

    // 판매
    void Sell(Inventory* inven, int invenIndex, UIManager* ui);

    // 카탈로그를 얻어온다
    /*std::deque<Item> GetCatalog();*/

private:
    std::deque<Item> Catalog_;
    static constexpr double SELL_RATE = 0.6;
};