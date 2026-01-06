#include "UI/UIManager.h"
#include "Types/StatusType.h"

class Player;

bool UIManager::PrintTitle()
{
    int x = 23;
    int y = 12;
    UIHelper_->PrintFile(x, y, "asset/Title.txt", 4);
    UIHelper_->Draw(x + 50, y + 11, "S T A R T");
    UIHelper_->Draw(x + 50, y + 13, "E X I T");

    int userselect = UIHelper_->UserSelection(x + 48, y + 11, 2);
    if (userselect == 1)
    {
        return true;
    }
    if (userselect == 2)
    {
        return false;
    }
}

void UIManager::PrintOff()
{
    std::cout << "게임을 종료합니다." << std::endl;
}

bool UIManager::PrintGameOver()
{
    int x = 34;
    int y = 12;
    system("cls");
    UIHelper_->Clearlog();
    UIHelper_->PrintFile(x, y, "asset/GameOver.txt", 4);
    UIHelper_->Draw(x+42, y+11, "RESTART");
    UIHelper_->Draw(x+42, y+13, "E X I T");

    int userselect = UIHelper_->UserSelection(x + 40, y + 11, 2);
    if (userselect == 1)
    {
        return true;
    }
    if (userselect == 2)
    {
        return false;
    }
}

void UIManager::PrintEndingEvent()
{
    int x = 34;
    int y = 12;
    system("cls");
    UIHelper_->PrintFile(x, y, "asset/EndingEvent.txt", 10);
    UIHelper_->gotoxy(0, 45);
}

void UIManager::SetInventory(Inventory* inven)
{
    Inventory_ = inven;
}

std::string UIManager::PrintCreateCharacter()
{
    int x = 60;
    int y = 18;

    system("cls");

    UIHelper_->gotoxy(x, y);
    UIHelper_->textcolor(3);
    std::cout << "스토리를 시작하려면 ENTER를 누르세요." << std::endl;
    UIHelper_->textcolor(0);
    UIHelper_->gotoxy(x, y + 1);
    system("pause");
    system("cls");
    Sleep(1000);

    //UIHelper_->gotoxy(x - 30, y - 8);
    //UIHelper_->PrintLine("2549년", 11, 25);
    //UIHelper_->gotoxy(x - 30, y - 6);
    //UIHelper_->PrintLine("문명의 발전은 인류를 더 먼 곳까지 데리고 갔지만", 11, 25);
    //UIHelper_->gotoxy(x - 30, y - 4);
    //UIHelper_->PrintLine("나아간 거리만큼 거대해진 욕심으로", 11, 25);
    //UIHelper_->gotoxy(x - 30, y - 2);
    //UIHelper_->PrintLine("끊임없이 전쟁이 이어졌다.", 11, 25);
    //Sleep(1000);

    //UIHelper_->gotoxy(x - 30, y + 2);
    //UIHelper_->PrintLine("전쟁이 길어지면서 많은 자원과 인력을 소모하는 전장보다", 11, 25);
    //UIHelper_->gotoxy(x - 30, y + 4);
    //UIHelper_->PrintLine("상대의 주요 인물을 암살하는 임무가 전쟁의 승패를 좌우하게 된다.", 11, 25);
    //Sleep(1000);

    system("cls");

    UIHelper_->PrintFile(x - 14, y - 16, "asset/Assassin.txt", 15);
    while (true)
    {
        UIHelper_->gotoxy(x + 9, y + 6);
        UIHelper_->PrintLine("요원 이름 입력", 15, 30);
        UIHelper_->gotoxy(x + 9, y + 8);
        std::string Inputname;
        getline(std::cin, Inputname);

        std::string bantext = " ";
        std::string replacement = "";

        size_t pos = 0;
        while ((pos = Inputname.find(bantext, pos)) != std::string::npos)
        {
            Inputname.replace(pos, bantext.length(), replacement);
            pos += replacement.length();
        }

        if (Inputname.empty())
        {
            Inputname.clear();
            UIHelper_->gotoxy(x + 2, y + 10);
            UIHelper_->PrintLine("올바른 이름을 다시 입력해주세요", 3, 15);
            Sleep(700);
            UIHelper_->gotoxy(x + 2, y + 10);
            UIHelper_->PrintLine("올바른 이름을 다시 입력해주세요", 0, 15);
            continue;
        }
        if (Inputname.length() > 10)
        {
            Inputname.clear();
            UIHelper_->gotoxy(x + 2, y + 8);
            UIHelper_->PrintLine("                                   ", 3, 3);
            UIHelper_->gotoxy(x + 7, y + 10);
            UIHelper_->PrintLine("이름이 너무 깁니다.", 3, 15);
            Sleep(700);
            UIHelper_->gotoxy(x + 7, y + 10);
            UIHelper_->PrintLine("이름이 너무 깁니다.", 0, 15);
            continue;
        }

        UIHelper_->gotoxy(x + 6, y + 10);
        UIHelper_->PrintLine("요원 정보 탐색 중...", 2, 25);
        Sleep(1000);
        UIHelper_->gotoxy(x + 5, y + 10);
        UIHelper_->PrintLine("요원 정보 불러오는 중...", 4, 25);
        Sleep(1000);
        UIHelper_->gotoxy(x + 5, y + 10);
        UIHelper_->PrintLine("작전 지역으로 이동 중...", 14, 25);
        Sleep(1500);
        system("cls");

        return Inputname;
    }
}

void UIManager::PrintPlayerStatus(Player* player)
{
    int x = 2;
    int y = 2;

    UIHelper_->textcolor(15);
    UIHelper_->Draw(x, y, "요원명 :");
    UIHelper_->gotoxy(x + 9, y);
    std::cout << player->GetName();

    UIHelper_->Draw(x, y + 2, "LEVEL :");
    UIHelper_->gotoxy(x + 8, y + 2);
    std::cout << player->GetLevel();

    UIHelper_->Draw(x, y + 4, "HP");
    UIHelper_->Draw(x + 5, y + 4, "[");
    UIHelper_->Draw(x + 16, y + 4, "]");
    UIHelper_->DrawBar(x + 6, y + 4, 10, player->GetHP(), player->GetMaxHP(), 12);
    UIHelper_->gotoxy(x + 18, y + 4);
    std::cout << player->GetHP() << " / " << player->GetMaxHP() << "  ";

    UIHelper_->Draw(x, y + 5, "Exp");
    UIHelper_->Draw(x + 5, y + 5, "[");
    UIHelper_->Draw(x + 16, y + 5, "]");
    UIHelper_->DrawBar(x + 6, y + 5, 10, player->GetExp(), player->GetMaxExp(), 2);
    UIHelper_->gotoxy(x + 18, y + 5);
    std::cout << player->GetExp() << " / " << player->GetMaxExp() << "  ";

    UIHelper_->Draw(x, y + 6, "공격력 : ");
    UIHelper_->gotoxy(x + 9, y + 6);
    std::cout << player->Attack() << "  ";

    UIHelper_->Draw(x, y + 8, "Gold : ");
    UIHelper_->gotoxy(x + 7, y + 8);
    std::cout << player->GetGold() << "  ";

    UIHelper_->Draw(x, y + 25, "[킬 카운트]");

    UIHelper_->gotoxy(0, 45);
}

void UIManager::PrintMonsterStatus(Monster* monster)
{
    int x = 126;
    int y = 2;
    UIHelper_->textcolor(15);
    UIHelper_->Draw(x, y, "타겟 :");
    UIHelper_->gotoxy(x + 7, y);
    std::cout << monster->GetName() << "     ";

    UIHelper_->Draw(x, y + 2, "HP");
    UIHelper_->Draw(x + 5, y + 2, "[");
    UIHelper_->Draw(x + 16, y + 2, "]");
    UIHelper_->DrawBar(x+6, y+2, 10, monster->GetHP(), monster->GetMaxHP(), 12);
    UIHelper_->gotoxy(x + 18, y + 2);
    std::cout << monster->GetHP() << " / " << monster->GetMaxHP() << "   ";

    UIHelper_->Draw(x, y + 4, "공격력 : ");
    UIHelper_->gotoxy(x + 9, y + 4);
    std::cout << monster->GetAttack() << "  ";

    UIHelper_->gotoxy(0, 45);

}

void UIManager::PrintKillCount(AchievementSystem* achieve)
{
    int x = 2;
    int y = 29;
    int dy = 0;
    UIHelper_->textcolor(15);

    std::map<std::string, int> KillCount =achieve->GetAllKillCount();

    for (std::map<std::string, int>::iterator itr = KillCount.begin(); itr != KillCount.end(); itr++)
    {
        UIHelper_->gotoxy(x, y + dy);
        std::cout << itr->first << " : " << itr->second << "          ";
        dy++;
    }

    UIHelper_->gotoxy(0, 30);
}

void UIManager::PrintInventory(Inventory* inven)
{
    int x = 2;
    int y = 2;
    for (size_t i = y + 10; i < inven->GetInventory().size(); i++)
    {
        for (const auto& item : inven->GetInventory())
        {
            UIHelper_->gotoxy(x + 7, i);
            std::cout << Item::ItemTypeToString(item.first) << " : " << item.second;
        }
    }
}

void UIManager::PrintBattleStart(Player* p, Monster* m, AchievementSystem* achieve)
{
    PrintPlayerStatus(p);
    PrintMonsterStatus(m);
    PrintKillCount(achieve);

    UIHelper_->PrintUIBox();
    UIHelper_->Draw(37, 26, "<작전 현황표>");

    UIHelper_->ConsoleClear(36, 1, 123, 24);
    UIHelper_->PrintFile(39, 10, "asset/FindTarget.txt", 12);
    std::string TargetLog = "--------------[목표발견]--------------                                       ";
    UIHelper_->PushLog(TargetLog, 15);
    UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
    TargetLog = p->GetName() + "이(가) 목표물 " + m->GetName() + "을(를) 발견했다.                              ";
    UIHelper_->PushLog(TargetLog, 4);
    UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
    UIHelper_->textcolor(15);
    Sleep(1000);
    UIHelper_->ConsoleClear(36, 1, 123, 24);

    UIHelper_->PrintFile(40, 9, "asset/ManWithGun.txt", 15);

    if (m->GetLevel() <= 3)
    {
        UIHelper_->PrintFile(90, 4, "asset/Target1.txt", 15);
    }
    else if (m->GetLevel() <= 6)
    {
        UIHelper_->PrintFile(90, 4, "asset/Target2.txt", 15);
    }
    else if (m->GetLevel() <= 9)
    {
        UIHelper_->PrintFile(90, 4, "asset/Target3.txt", 15);
    }
    else
    {

    }
}

void UIManager::PrintMonsterTakeDamage(Monster* m, int finaldamage)
{
    int PrintSpeed = 300;
    if (m->GetLevel() <= 3)
    {
        UIHelper_->PrintFile(90, 4, "asset/Target1.txt", 4);
        Sleep(PrintSpeed);
        UIHelper_->PrintFile(90, 4, "asset/Target1.txt", 15);
        std::string log = m->GetName() + "이(가) " + std::to_string(finaldamage) +  " 데미지를 입었습니다                                ";
        UIHelper_->PushLog(log, 4);
        UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
        PrintMonsterStatus(m);
        UIHelper_->textcolor(15);
        Sleep(PrintSpeed);
    }
    else if (m->GetLevel() <= 6)
    {
        UIHelper_->PrintFile(90, 4, "asset/Target2.txt", 4);
        Sleep(PrintSpeed);
        UIHelper_->PrintFile(90, 4, "asset/Target2.txt", 15);
        std::string log = m->GetName() + "이(가) " + std::to_string(finaldamage) + " 데미지를 입었습니다                                 ";
        UIHelper_->PushLog(log, 4);
        UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
        PrintMonsterStatus(m);
        UIHelper_->textcolor(15);
        Sleep(PrintSpeed);
    }
    else if (m->GetLevel() <= 9)
    {
        UIHelper_->PrintFile(90, 4, "asset/Target3.txt", 4);
        Sleep(PrintSpeed);
        UIHelper_->PrintFile(90, 4, "asset/Target3.txt", 15);
        std::string log = m->GetName() + "이(가) " + std::to_string(finaldamage) + " 데미지를 입었습니다                                 ";
        UIHelper_->PushLog(log, 4);
        UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
        PrintMonsterStatus(m);
        UIHelper_->textcolor(15);
        Sleep(PrintSpeed);
    }
    else
    {

    }
}

void UIManager::PrintPlayerTakeDamage(Player* p, int finaldamage)
{
    int PrintSpeed = 300;
    UIHelper_->PrintFile(40, 9, "asset/ManWithGun.txt", 4);
    Sleep(PrintSpeed);
    UIHelper_->PrintFile(40, 9, "asset/ManWithGun.txt", 15);
    std::string log = p->GetName() + "이(가) " + std::to_string(finaldamage) + " 데미지를 입었습니다                                     ";
    UIHelper_->PushLog(log, 8);
    UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
    PrintPlayerStatus(p);
    UIHelper_->textcolor(15);
    Sleep(PrintSpeed);
}

void UIManager::PrintUseItem(const Item* item)
{
    int PrintSpeed = 300;
    UIHelper_->PrintFile(40, 9, "asset/ManWithGun.txt", 10);
    Sleep(PrintSpeed);
    UIHelper_->PrintFile(40, 9, "asset/ManWithGun.txt", 15);
    std::string log;
    std::map<StatusType, int> Effect = item->GetEffect();
    switch (item->GetName())
    {
    case ItemType::LowHealthPotion:
        log = item->ItemTypeToString((item->GetName())) + "을 사용하여 체력을 " + std::to_string(Effect[StatusType::HP]) + "회복했습니다. 현재 재고 : " + std::to_string(Inventory_->GetItemCount(item->GetName())) + "    ";
        UIHelper_->PushLog(log, 2);
        break;
    case ItemType::LowAttackPotion:
        log = item->ItemTypeToString((item->GetName())) + "을 사용하여 공격력이 " + std::to_string(Effect[StatusType::ATK]) + "상승했습니다. 현재 재고 : " + std::to_string(Inventory_->GetItemCount(item->GetName())) + "    ";
        UIHelper_->PushLog(log, 5);
        break;
    }
    UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
    UIHelper_->textcolor(15);
    Sleep(PrintSpeed);
}

void UIManager::PrintAttackInsteadUseItem()
{
    int PrintSpeed = 300;
    std::string log = "아이템이 없어서 사용할 수 없는 대신 공격합니다.                                    ";
    UIHelper_->PushLog(log, 15);
    UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
    Sleep(PrintSpeed);
}

void UIManager::PrintVictory(const std::string& monstername, AchievementSystem* achieve)
{
    int PrintSpeed = 300;
    Sleep(PrintSpeed);
    UIHelper_->ConsoleClear(90, 1, 123, 24);
    std::string log = "--------------[암살성공]--------------                                       ";
    UIHelper_->PushLog(log, 15);
    UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
    log = monstername + " 암살에 성공했습니다.                                           ";
    UIHelper_->PushLog(log, 5);
    UIHelper_->Printlog(37, 27, UIHelper_->GetLog());

    PrintKillCount(achieve);

    Sleep(PrintSpeed);
}

void UIManager::PrintFixedRewards(int exp_reward, int levelup_count, int gain_golds)
{
    int PrintSpeed = 500;
    std::string log = "--------------[승리보상]--------------                                       ";
    UIHelper_->PushLog(log, 15);
    UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
    Sleep(PrintSpeed);
    log = "경험치 획득 : " + std::to_string(exp_reward) + "                                             ";
    UIHelper_->PushLog(log, 10);
    UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
    Sleep(PrintSpeed);
    if (levelup_count != 0)
    {
        for (int i = 0; i < levelup_count; i++)
        {
            log = "레벨업!                                                                             ";
            UIHelper_->PushLog(log, 11);
            UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
            Sleep(PrintSpeed);
        }
    }
    log = "골드 획득 : " + std::to_string(gain_golds) + "                                              ";
    UIHelper_->PushLog(log, 14);
    UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
    Sleep(PrintSpeed + 500);

    UIHelper_->textcolor(15);
}

void UIManager::PrintItemRewards(ItemType itemtype)
{
    int PrintSpeed = 500;
    std::string log = "-------------[아이템획득!]-------------                                            ";
    UIHelper_->PushLog(log, 15);
    UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
    log = Item::ItemTypeToString(itemtype) + " 아이템을 획득했습니다. 현재 재고 : " + std::to_string(Inventory_->GetItemCount(itemtype)) + "                       ";
    UIHelper_->PushLog(log, 10);
    UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
    Sleep(PrintSpeed + 500);

    UIHelper_->textcolor(15);
}

bool UIManager::ShopEnterChoice()
{
    int x = 126;
    int y = 27;
    UIHelper_->Draw(x + 2, y, "상점입장");
    UIHelper_->Draw(x + 2, y + 2, "다음전투");
    int choice = UIHelper_->UserSelection(126, 27, 2);
    UIHelper_->ConsoleClear(126, 27, 158, 41);
    switch (choice)
    {
    case 1:
        return true;
    case 2:
        return false;
    }
}

// 상점 UI
int UIManager::PrintShop(Player* p)
{
    int x = 126;
    int y = 27;

    system("cls");

    UIHelper_->PrintUIBox();
    std::string log = "---------------[상점로비]----------------                                            ";
    UIHelper_->PushLog(log, 15);
    UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
    PrintPlayerStatus(p);
    

    UIHelper_->Draw(x + 2, y, "구매");
    UIHelper_->Draw(x + 2, y + 2, "판매");
    UIHelper_->Draw(x + 2, y + 4, "다음 전투");
    int choice = UIHelper_->UserSelection(126, 27, 3);

    UIHelper_->ConsoleClear(126, 27, 158, 41);

    return choice;
}

int UIManager::PrintShopBuyChoice(int x, int y, const std::deque<Item>& catalog)
{
    UIHelper_->PrintUIBox();

    for (const auto& item : catalog)
    {
        UIHelper_->gotoxy(x, y);
        for (const auto& effect : item.GetEffect())
        {
            std::cout << Item::ItemTypeToString(item.GetName()) << " : " << "HP"/*Item::ItemTypeToString(effect.first)*/ << " : " << item.GetPrice() << " Gold          ";
        }
        y = y + 2;
    }
    return UIHelper_->UserSelection(x-2, y-4, catalog.size());
}

ItemType UIManager::PrintShopSellChoice(int x, int y, Inventory* inven)
{
    UIHelper_->PrintUIBox();

    for (const auto& item : inven->GetInventory())
    {
        UIHelper_->gotoxy(x, y);
        std::cout << Item::ItemTypeToString(item.first) << " : " << item.second << " 개 보유                                    ";

        y = y + 2;
    }
    int userchoice = UIHelper_->UserSelection(x - 2, y - 2, inven->GetInventory().size());
    auto item = inven->GetInventory().begin();
    std::advance(item, userchoice-1);

    if (item != inven->GetInventory().end())
    {
        return item->first;
    }

    return ItemType();
}


int UIManager::CountPurchasePrice(int x, int y, const int max, int userchoice, const std::deque<Item>& catalog)
{
    int choiceX = x;
    int choiceY = y;
    int choice = 0;
    int Price = 0;

    UIHelper_->ConsoleClear(126, 27, 158, 41);

    while (true)
    {
        UIHelper_->gotoxy(choiceX, choiceY);
        std::cout << "갯수 : " << choice << "    ";
        UIHelper_->gotoxy(choiceX, choiceY + 2);
        std::cout << "가격 : " << Price << "    ";

        if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            if (choice < max)
            {
                Price += catalog[userchoice - 1].GetPrice();
                choice++;
            }
            Sleep(50);
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            if (choice > 0)
            {
                Price -= catalog[userchoice - 1].GetPrice();
                choice--;
            }
            Sleep(50);
        }
        if (GetAsyncKeyState(VK_RETURN) & 0x8000)
        {
            UIHelper_->ConsoleClear(125, 26, 158, 41);
            Sleep(200);
            return choice;
        }
        Sleep(100);
    }
}

int UIManager::CountSellPrice(int x, int y, const int max, ItemType userchoice, const std::deque<Item>& catalog, double SellRate)
{
    int choiceX = x;
    int choiceY = y;
    int choice = 0;
    int Price = 0;

    while (true)
    {
        UIHelper_->gotoxy(choiceX, choiceY);
        std::cout << "갯수 : " << choice << "    ";
        UIHelper_->gotoxy(choiceX, choiceY + 2);
        std::cout << "가격 : " << Price << "    ";

        if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            if (choice < max)
            {
                Price += (Item::GetData(userchoice)->GetPrice()) * SellRate;
                choice++;
            }
            Sleep(50);
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            if (choice > 0)
            {
                Price -= (Item::GetData(userchoice)->GetPrice()) * SellRate;
                choice--;
            }
            Sleep(50);
        }
        if (GetAsyncKeyState(VK_RETURN) & 0x8000)
        {
            UIHelper_->ConsoleClear(125, 26, 158, 41);
            Sleep(200);
            return choice;
        }
        Sleep(100);
    }
}

void UIManager::PrintShoplog(const std::string& shoplog)
{
    UIHelper_->PushLog(shoplog, 14);
    UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
}
