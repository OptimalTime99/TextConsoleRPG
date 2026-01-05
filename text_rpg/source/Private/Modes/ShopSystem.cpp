#include "Modes/ShopSystem.h"
#include "States/Player.h"
#include "UI/UIManager.h"
#include <Types/GameMode.h>

GameMode ShopSystem::Shop(Player* p, UIManager* ui)
{
    int choice = ui->PrintShop();
    while (true)
    {
        int choice = ui->PrintShop();
        switch (choice)
        {
        case 1:
            // 구매
            continue;
        case 2:
            // 판매
            continue;
        case 3:
            return GameMode::BATTLE_MODE;
            break;
        }
    }
}

GameMode ShopSystem::EnterChoice(Player* p, UIManager* ui)
{
    bool choice = ui->ShopEnterChoice();
    switch (choice)
    {
    case true:
        return GameMode::SHOP_MODE;
    case false:
        return GameMode::BATTLE_MODE;
    }
}

void ShopSystem::Buy(Inventory* inven, int catalogindex, UIManager* ui)
{
    
}

void ShopSystem::Sell(Inventory* inven, int invenIndex, UIManager* ui)
{

}

//std::deque<Item> ShopSystem::GetCatalog()
//{
//    return Catalog_;
//}