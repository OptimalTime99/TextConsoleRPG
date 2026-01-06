#include "Modes/ShopSystem.h"
#include "States/Player.h"
#include "UI/UIManager.h"
#include <Types/GameMode.h>

GameMode ShopSystem::Shop(Player* p, UIManager* ui)
{
    return GameMode();
}

GameMode ShopSystem::EnterChoice(Player* p, UIManager* ui)
{
    return GameMode();
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