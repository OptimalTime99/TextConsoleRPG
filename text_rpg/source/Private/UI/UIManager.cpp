#include "UI/UIManager.h"

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
    std::cout << "엔딩 추가 예정" << std::endl;
}

std::string UIManager::PrintCreateCharacter()
{
    int x = 60;
    int y = 18;

    UIHelper_->gotoxy(x, y);
    UIHelper_->textcolor(3);
    std::cout << "스토리를 시작하려면 ENTER를 누르세요." << std::endl;
    UIHelper_->textcolor(0);
    UIHelper_->gotoxy(x, y + 1);
    system("pause");
    system("cls");
    Sleep(1000);

    UIHelper_->gotoxy(x - 30, y - 8);
    UIHelper_->PrintLine("2549년", 11, 60);
    UIHelper_->gotoxy(x - 30, y - 6);
    UIHelper_->PrintLine("문명의 발전은 인류를 더 먼 곳까지 데리고 갔지만", 11, 60);
    UIHelper_->gotoxy(x - 30, y - 4);
    UIHelper_->PrintLine("나아간 거리만큼 거대해진 욕심으로", 11, 60);
    UIHelper_->gotoxy(x - 30, y - 2);
    UIHelper_->PrintLine("끊임없이 전쟁이 이어졌다.", 11, 60);
    Sleep(1000);

    UIHelper_->gotoxy(x - 30, y + 2);
    UIHelper_->PrintLine("전쟁이 길어지면서 많은 자원과 인력을 소모하는 전장보다", 11, 60);
    UIHelper_->gotoxy(x - 30, y + 4);
    UIHelper_->PrintLine("상대의 주요 인물을 암살하는 임무가 전쟁의 승패를 좌우하게 된다.", 11, 60);
    Sleep(1000);

    system("cls");

    UIHelper_->PrintFile(x - 14, y - 16, "asset/Assassin.txt", 15);
    while (true)
    {
        UIHelper_->gotoxy(x + 9, y + 6);
        UIHelper_->PrintLine("요원 이름 입력", 15, 60);
        UIHelper_->gotoxy(x + 9, y + 8);
        std::string Inputname = "";
        getline(std::cin, Inputname);

        if (Inputname.empty())
        {
            UIHelper_->gotoxy(x + 2, y + 10);
            UIHelper_->PrintLine("올바른 이름을 다시 입력해주세요", 3, 15);
            Sleep(700);
            UIHelper_->gotoxy(x + 2, y + 10);
            UIHelper_->PrintLine("올바른 이름을 다시 입력해주세요", 0, 15);
            continue;
        }
        if (Inputname.length() > 10)
        {
            Inputname = Inputname.substr(0, 10);
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
        UIHelper_->PrintLine("요원 정보 탐색 중...", 2, 50);
        Sleep(1000);
        UIHelper_->gotoxy(x + 5, y + 10);
        UIHelper_->PrintLine("요원 정보 불러오는 중...", 4, 50);
        Sleep(1000);
        UIHelper_->gotoxy(x + 5, y + 10);
        UIHelper_->PrintLine("작전 지역으로 이동 중...", 14, 50);
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

    UIHelper_->Draw(x, y + 2, "HP");
    UIHelper_->Draw(x + 5, y + 2, "[");
    UIHelper_->Draw(x + 16, y + 2, "]");
    UIHelper_->DrawBar(x + 6, y + 2, 10, player->GetHP(), player->GetMaxHP(), 12);
    UIHelper_->gotoxy(x + 18, y + 2);
    std::cout << player->GetHP() << " / " << player->GetMaxHP();

    //UIHelper_->Draw(x, y+2, "총알");
    //UIHelper_->Draw(x+5, y+2, "[");
    //UIHelper_->Draw(x+16, y+2, "]");
    //UIHelper_->gotoxy(x+18, y+2);
    //std::cout << 10 << " / " << 30;
    /*UIHelper_->DrawBar(x+6, y+2, 10, 10, 30, 8);*/

    UIHelper_->Draw(x, y + 3, "Exp");
    UIHelper_->Draw(x + 5, y + 3, "[");
    UIHelper_->Draw(x + 16, y + 3, "]");
    UIHelper_->DrawBar(x + 6, y + 3, 10, player->GetExp(), player->GetMaxExp(), 2);
    UIHelper_->gotoxy(x + 18, y + 3);
    std::cout << player->GetExp() << " / " << player->GetMaxExp();

    UIHelper_->Draw(x, y + 5, "공격력 : ");
    UIHelper_->gotoxy(x + 9, y + 5);
    std::cout << player->Attack();

    //UIHelper_->Draw(x, y + 6, "속도 : ");
    //UIHelper_->gotoxy(x + 7, y + 6);
    //std::cout << "player->GetSpeed()";

    UIHelper_->Draw(x, y + 7, "Gold : ");
    UIHelper_->gotoxy(x + 7, y + 7);
    std::cout << player->GetGold();

    UIHelper_->gotoxy(0, 45);
}

void UIManager::PrintMonsterStatus(Monster* monster)
{
    int x = 126;
    int y = 2;
    UIHelper_->textcolor(15);
    UIHelper_->Draw(x, y, "타겟 :");
    UIHelper_->gotoxy(x + 7, y);
    std::cout << monster->GetName();

    UIHelper_->Draw(x, y + 2, "HP");
    UIHelper_->Draw(x + 5, y + 2, "[");
    UIHelper_->Draw(x + 16, y + 2, "]");
    UIHelper_->DrawBar(x+6, y+2, 10, monster->GetHP(), monster->GetMaxHP(), 12);
    UIHelper_->gotoxy(x + 18, y + 2);
    std::cout << monster->GetHP() << " / " << monster->GetMaxHP();

    //UIHelper_->Draw(x, y + 2, "총알");
    //UIHelper_->Draw(x + 5, y + 2, "[");
    //UIHelper_->Draw(x + 16, y + 2, "]");
    //UIHelper_->DrawBar(x+6, y+2, 10, 10, 30, 8);
    //UIHelper_->gotoxy(x + 18, y + 2);
    //std::cout << 10 << " / " << 30;

    UIHelper_->Draw(x, y + 4, "공격력 : ");
    UIHelper_->gotoxy(x + 9, y + 4);
    std::cout << monster->GetAttack();

    //UIHelper_->Draw(x, y + 4, "속도 : ");
    //UIHelper_->gotoxy(x + 7, y + 4);
    //std::cout << monster->GetSpeed();

    UIHelper_->gotoxy(0, 45);

}

void UIManager::PrintKillCount(AchievementSystem* achieve)
{
    int x = 2;
    int y = 12;
    UIHelper_->textcolor(15);

    std::map<std::string, int> KillCount =achieve->GetAllKillCount();

    UIHelper_->Draw(x, y, "[킬 카운트]");
    int dy = 0;
    for (std::map<std::string, int>::iterator itr = KillCount.begin(); itr != KillCount.end(); itr++)
    {
        UIHelper_->gotoxy(x, y + dy);
        std::cout << itr->first << " " << itr->second;
        dy++;
    }

    UIHelper_->gotoxy(0, 30);
}

void UIManager::PrintBattleStart(Player* p, Monster* m)
{
    std::string printmsg = p->GetName() + "이(가) 목표물 " + m->GetName() +"을(를) 발견했다.";
    UIHelper_->BoxUI(26, 12, 133, 29, 15);
    UIHelper_->gotoxy(30, 14);
    UIHelper_->PrintLine(printmsg, 15, 40);
    Sleep(1000);
    system("cls");

    PrintPlayerStatus(p);
    PrintMonsterStatus(m);

    UIHelper_->Draw(37, 26, "<작전 현황표>");
    UIHelper_->BoxUI(0, 0, 159, 42, 15);
    UIHelper_->BoxUI(0, 0, 35, 42, 15);
    UIHelper_->BoxUI(124, 0, 159, 42, 15);
    UIHelper_->BoxUI(0, 25, 159, 42, 15);

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

void UIManager::PrintMonsterTakeDamage(Monster* m)
{
    if (m->GetLevel() <= 3)
    {
        UIHelper_->PrintFile(90, 4, "asset/Target1.txt", 4);
        Sleep(200);
        UIHelper_->PrintFile(90, 4, "asset/Target1.txt", 15);
        std::string log = m->GetName() + "이(가) 데미지를 입었습니다     ";
        UIHelper_->PushLog(log, 4);
        UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
        PrintMonsterStatus(m);
        UIHelper_->textcolor(15);
        Sleep(150);
    }
    else if (m->GetLevel() <= 6)
    {
        UIHelper_->PrintFile(90, 4, "asset/Target2.txt", 4);
        Sleep(200);
        UIHelper_->PrintFile(90, 4, "asset/Target2.txt", 15);
        std::string log = m->GetName() + "이(가) 데미지를 입었습니다     ";
        UIHelper_->PushLog(log, 4);
        UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
        PrintMonsterStatus(m);
        UIHelper_->textcolor(15);
        Sleep(150);
    }
    else if (m->GetLevel() <= 9)
    {
        UIHelper_->PrintFile(90, 4, "asset/Target3.txt", 4);
        Sleep(200);
        UIHelper_->PrintFile(90, 4, "asset/Target3.txt", 15);
        std::string log = m->GetName() + "이(가) 데미지를 입었습니다     ";
        UIHelper_->PushLog(log, 4);
        UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
        PrintMonsterStatus(m);
        UIHelper_->textcolor(15);
        Sleep(150);
    }
    else
    {

    }
}

void UIManager::PrintPlayerTakeDamage(Player* p)
{
    UIHelper_->PrintFile(40, 9, "asset/ManWithGun.txt", 4);
    Sleep(200);
    UIHelper_->PrintFile(40, 9, "asset/ManWithGun.txt", 15);
    std::string log = p->GetName() + "이(가) 데미지를 입었습니다      ";
    UIHelper_->PushLog(log, 8);
    UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
    PrintPlayerStatus(p);
    UIHelper_->textcolor(15);
    Sleep(150);
}

void UIManager::PrintUseItem(Item* item)
{
    UIHelper_->PrintFile(40, 9, "asset/ManWithGun.txt", 10);
    Sleep(200);
    UIHelper_->PrintFile(40, 9, "asset/ManWithGun.txt", 15);
    std::string log;
    switch (item->GetType())
    {
    case ItemType::HealPotion:
        log = std::string(item->GetName()) + "을 사용하여 체력을 " + std::to_string(item->GetValue()) + "회복했습니다.     ";
        UIHelper_->PushLog(log, 2);
        break;
    case ItemType::AtkPotion:
        log = std::string(item->GetName()) + "을 사용하여 공격력이 " + std::to_string(item->GetValue()) + "상승했습니다.   ";
        UIHelper_->PushLog(log, 5);
        break;
    }
    UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
    UIHelper_->textcolor(15);
    Sleep(150);
}

void UIManager::PrintVictory()
{
    Sleep(150);
    UIHelper_->ConsoleClear(90, 1, 123, 24);
    std::string log = "--------------[암살성공]--------------";
    UIHelper_->PushLog(log, 15);
    UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
    Sleep(150);
}

void UIManager::PrintFixedRewards(int exp_reward, int levelup_count, int gain_golds)
{
    std::string log = "--------------[승리보상]--------------";
    UIHelper_->PushLog(log, 15);
    UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
    Sleep(150);
    log = "경험치 획득 : " + std::to_string(exp_reward) + "                          ";
    UIHelper_->PushLog(log, 10);
    UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
    Sleep(150);
    if (levelup_count != 0)
    {
        for (int i = 0; i < levelup_count; i++)
        {
            log = "레벨업!                                                            ";
            UIHelper_->PushLog(log, 11);
            UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
            Sleep(150);
        }
    }
    log = "골드 획득 : " + std::to_string(gain_golds) + "                            ";
    UIHelper_->PushLog(log, 14);
    UIHelper_->Printlog(37, 27, UIHelper_->GetLog());
    Sleep(150);

    UIHelper_->textcolor(15);
}

bool UIManager::ShopEnterChoice()
{
    int choice = UIHelper_->UserSelection(1, 1, 2);
    switch (choice)
    {
    case 1:
        return true;
    case 2:
        return false;
    }
}

// 상점 UI
int UIManager::PrintShop()
{
    UIHelper_->Draw(20, 20, "상점UI 추가예정");
    return 1;
}

int UIManager::PrintShopCatalog()
{
    UIHelper_->Draw(20, 20, "상점 구매 카탈로그");
    return 0;
}
