#include "Modes/ShopSystem.h"
#include "Types/GameMode.h"

enum class Itemtype;

void ShopSystem::Shop(Inventory* inven, Player* p, UIManager* ui)
{
    while (true)
    {
        int choice = ui->PrintShop(p);
        switch (choice)
        {
        case 1:
            Buy(inven, p, ui);
            ui->PrintPlayerStatus(p);
            break;
        case 2:
            Sell(inven, p, ui);
            ui->PrintPlayerStatus(p);
            break;
        case 3:
            return;
        }
    }
}

bool ShopSystem::EnterChoice(Player* p, UIManager* ui)
{
    bool choice = ui->ShopEnterChoice();
    return choice;
}

void ShopSystem::Buy(Inventory* inven, Player* p, UIManager* ui)
{
    int Shop_x = 39;
    int Shop_y = 3;
    int Choice_x = 128;
    int Choice_y = 29;
    int userchoice = ui->PrintShopBuyChoice(Shop_x, Shop_y, Catalog_);
    int itemcount = ui->CountPurchasePrice(Choice_x, Choice_y, 99, userchoice, Catalog_);
    int totalprice = itemcount * Catalog_[userchoice-1].GetPrice();
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

    ItemType userchoice = ui->PrintShopSellChoice(Shop_x, Shop_y, inven);
    int itemcount = ui->CountSellPrice(Choice_x, Choice_y, inven->GetItemCount(userchoice), userchoice, Catalog_, SELL_RATE);
    int totalprice = itemcount * (Item::GetData(userchoice)->GetPrice()) * SELL_RATE;
    std::string purchaselog;

    p->SetGold(p->GetGold() + totalprice);
    inven->RemoveItem(userchoice, itemcount);
    purchaselog = Item::ItemTypeToString(userchoice) + " " + std::to_string(itemcount) + " 판매완료               ";
    ui->PrintShoplog(purchaselog);
}


//std::deque<Item> ShopSystem::GetCatalog()
//{
//    return Catalog_;
//}