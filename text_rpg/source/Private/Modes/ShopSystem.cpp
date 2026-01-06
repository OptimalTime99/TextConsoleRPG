#include "Modes/ShopSystem.h"
#include "Types/GameMode.h"

enum class Itemtype;

GameMode ShopSystem::Shop(Inventory* inven, Player* p, UIManager* ui)
{
    while (true)
    {
        int choice = ui->PrintShop(p);
        switch (choice)
        {
        case 1:
            Buy(inven, p, ui);
            ui->PrintPlayerStatus(p);
            continue;
        case 2:
            Sell(inven, p, ui);
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

void ShopSystem::Buy(Inventory* inven, Player* p, UIManager* ui)
{
    int Shop_x = 39;
    int Shop_y = 3;
    int Choice_x = 128;
    int Choice_y = 29;
    int userchoice = ui->PrintShopBuyChoice(Shop_x, Shop_y, Catalog_);
    int totalprice = ui->CountPrice(Choice_x, Choice_y, 99, userchoice, Catalog_, true, SELL_RATE);
    int itemcount = totalprice / Catalog_[userchoice-1].GetPrice();
    std::string purchaselog;

    switch (userchoice)
    {
    case 1:
        if (p->GetGold() < totalprice)
        {
            purchaselog = "잔액이 부족합니다.";
            ui->PrintShoplog(purchaselog);
        }
        else
        {
            p->SetGold(p->GetGold() - totalprice);
            inven->AddItem(Catalog_[userchoice - 1].GetName(), itemcount);
            purchaselog = Item::ItemTypeToString(Catalog_[userchoice-1].GetName()) + " " + std::to_string(itemcount) + " 구매완료              ";
            ui->PrintShoplog(purchaselog);
        }
        break;
    case 2:
        if (p->GetGold() < totalprice)
        {
            purchaselog = "잔액이 부족합니다.";
            ui->PrintShoplog(purchaselog);
        }
        else
        {
            p->SetGold(p->GetGold() - totalprice);
            inven->AddItem(Catalog_[userchoice - 1].GetName(), itemcount);
            purchaselog = Item::ItemTypeToString(Catalog_[userchoice-1].GetName()) + " " + std::to_string(itemcount) + " 구매완료              ";
            ui->PrintShoplog(purchaselog);
        }
        break;
    }
}

void ShopSystem::Sell(Inventory* inven, Player* p, UIManager* ui)
{
    int Shop_x = 39;
    int Shop_y = 3;
    int Choice_x = 128;
    int Choice_y = 29;

    int userchoice = ui->PrintShopSellChoice(Shop_x, Shop_y, inven);
    int totalprice = ui->CountPrice(Choice_x, Choice_y, inven->GetItemCount(Catalog_[userchoice-1].GetName()), userchoice, Catalog_, false, SELL_RATE);
    int itemcount = totalprice / Catalog_[userchoice - 1].GetPrice();
    std::string purchaselog;

    switch (userchoice)
    {
    case 1:
        p->SetGold(p->GetGold() + totalprice);
        /*inven->RemoveItem(0, itemcount);*/
        purchaselog = Item::ItemTypeToString(Catalog_[userchoice - 1].GetName()) + " " + std::to_string(itemcount) + " 구매완료              ";
        ui->PrintShoplog(purchaselog);
        break;
    case 2:
        p->SetGold(p->GetGold() + totalprice);
        /*inven->RemoveItem(0, itemcount);*/
        purchaselog = Item::ItemTypeToString(Catalog_[userchoice - 1].GetName()) + " " + std::to_string(itemcount) + " 구매완료              ";
        ui->PrintShoplog(purchaselog);
        break;
    }
}

//std::deque<Item> ShopSystem::GetCatalog()
//{
//    return Catalog_;
//}