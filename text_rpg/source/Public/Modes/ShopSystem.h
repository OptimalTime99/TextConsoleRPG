#pragma once
#include <vector>
#include <cmath>
#include "States/Item.h"

class Player;
class UIManager;

class ShopSystem
{
public:
    //입장
    void Enter(Player* p, UIManager* ui);

    // 구매
    void Buy(Player* p, int catalogindex);

    // 판매
    void Sell(Player* p, int invenIndex);

    // 카탈로그를 얻어온다
    void GetCatalog();

private:
    // std::vector<Item> Catalog_;
    static constexpr double SELL_RATE = 0.6;
};