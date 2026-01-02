#include "UI/UIManager.h"

bool UIManager::PrintTitle()
{
    UIHelper_->textcolor(4);
    UIHelper_->Draw(27, 5, "          :::      ::::::::   ::::::::      :::      :::::::: :::::::::::     :::     ::::    ::: ::::::::::: :::::::::: ");
    UIHelper_->Draw(27, 6, "       :+: :+:   :+:    :+: :+:    :+:   :+: :+:   :+:    :+:    :+:       :+: :+:   :+:+:   :+:     :+:     :+:         ");
    UIHelper_->Draw(27, 7, "     +:+   +:+  +:+        +:+         +:+   +:+  +:+           +:+      +:+   +:+  :+:+:+  +:+     +:+     +:+          ");
    UIHelper_->Draw(27, 8, "   +#++:++#++: +#++:++#++ +#++:++#++ +#++:++#++: +#++:++#++    +#+     +#++:++#++: +#+ +:+ +#+     +#+     +#++:++#      ");
    UIHelper_->Draw(27, 9, "  +#+     +#+        +#+        +#+ +#+     +#+        +#+    +#+     +#+     +#+ +#+  +#+#+#     +#+     +#+            ");
    UIHelper_->Draw(27, 10, " #+#     #+# #+#    #+# #+#    #+# #+#     #+# #+#    #+#    #+#     #+#     #+# #+#   #+#+#     #+#     #+#             ");
    UIHelper_->Draw(27, 11, "###     ###  ########   ########  ###     ###  ######## ########### ###     ### ###    ####     ###     ##########       ");
    UIHelper_->textcolor(15);
    UIHelper_->Draw(80, 16, "게임시작");
    UIHelper_->Draw(80, 18, "종   료");

    int userselect = UIHelper_->UserSelection(78, 16, 2);
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
    system("cls");
    UIHelper_->Draw(80, 16, "타이틀 화면으로");
    UIHelper_->Draw(80, 18, "게  임  종  료");

    int userselect = UIHelper_->UserSelection(78, 16, 2);
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
    UIHelper_->gotoxy(40, 12);
    UIHelper_->textcolor(3);
    std::cout << "스토리를 시작하려면 ENTER를 누르세요." << std::endl;
    UIHelper_->textcolor(0);
    system("pause");
    system("cls");
    UIHelper_->textcolor(15);
    Sleep(1000);

    UIHelper_->gotoxy(32, 8);
    UIHelper_->PrintLine("2549년", 6, 60);
    UIHelper_->gotoxy(32, 10);
    UIHelper_->PrintLine("문명의 발전은 인류를 더 먼 곳까지 데리고 갔지만", 6, 60);
    UIHelper_->gotoxy(32, 12);
    UIHelper_->PrintLine("나아간 거리만큼 거대해진 욕심으로 끊임없이 전쟁이 이어졌다.", 6, 60);
    Sleep(1000);

    system("cls");

    UIHelper_->gotoxy(32, 8);
    UIHelper_->PrintLine("전쟁이 길어지면서 많은 자원과 인력을 소모하는 전장보다", 6, 60);
    UIHelper_->gotoxy(32, 10);
    UIHelper_->PrintLine("상대의 주요 인물을 암살하는 임무가 전쟁의 승패를 좌우하게 된다.", 6, 60);
    Sleep(1000);

    system("cls");

    while (true)
    {
        UIHelper_->gotoxy(50, 6);
        UIHelper_->PrintLine("요원 이름 입력", 15, 60);
        UIHelper_->gotoxy(50, 8);
        std::string Inputname = "";
        getline(std::cin, Inputname);

        if (Inputname.empty())
        {
            UIHelper_->gotoxy(40, 10);
            UIHelper_->PrintLine("올바른 이름을 다시 입력해주세요", 3, 15);
            Sleep(700);
            system("cls");
            continue;
        }
        else
        {
            system("cls");
            return Inputname;
        }
    }
}

void UIManager::PrintPlayerStatus(Player* player)
{
    UIHelper_->Draw(1, 1, "요원명 :");
    UIHelper_->gotoxy(10, 1);
    std::cout << player->GetName();

    UIHelper_->Draw(1, 2, "HP");
    UIHelper_->Draw(6, 2, "[");
    UIHelper_->Draw(17, 2, "]");
    UIHelper_->gotoxy(19, 2);
    std::cout << player->GetHP() << " / " << player->GetMaxHP();

    UIHelper_->Draw(1, 3, "총알");
    UIHelper_->Draw(6, 3, "[");
    UIHelper_->Draw(17, 3, "]");
    UIHelper_->gotoxy(19, 3);
    std::cout << 10 << " / " << 30;

    UIHelper_->Draw(1, 4, "Exp");
    UIHelper_->Draw(6, 4, "[");
    UIHelper_->Draw(17, 4, "]");
    UIHelper_->gotoxy(19, 4);
    std::cout << player->GetExp() << " / " << player->GetMaxExp();

    UIHelper_->Draw(1, 5, "공격력 : ");
    UIHelper_->gotoxy(10, 5);
    std::cout << player->GetAttack();

    UIHelper_->Draw(1, 6, "속도 : ");
    UIHelper_->gotoxy(8, 6);
    std::cout << "player->GetSpeed()";

    UIHelper_->Draw(1, 7, "Gold : ");
    UIHelper_->gotoxy(8, 7);
    std::cout << player->GetGold();

    UIHelper_->DrawBar(7, 2, player->GetHP(), player->GetMaxHP(), 12);
    UIHelper_->DrawBar(7, 3, 10, 30, 8);
    UIHelper_->DrawBar(7, 4, player->GetExp(), player->GetMaxExp(), 2);

    UIHelper_->gotoxy(0, 30);
}

void UIManager::MonsterStatus(Monster* monster)
{
    UIHelper_->textcolor(15);
    UIHelper_->Draw(100, 1, "타겟 :");
    UIHelper_->gotoxy(107, 1);
    std::cout << "monster->GetName()";

    UIHelper_->Draw(100, 2, "HP");
    UIHelper_->Draw(105, 2, "[");
    UIHelper_->Draw(116, 2, "]");
    UIHelper_->gotoxy(118, 2);
    std::cout << "monster->GetHP()" << " / " << "monster->GetMaxHP()";

    UIHelper_->Draw(100, 3, "총알");
    UIHelper_->Draw(105, 3, "[");
    UIHelper_->Draw(116, 3, "]");
    UIHelper_->gotoxy(118, 3);
    std::cout << 10 << " / " << 30;

    UIHelper_->Draw(100, 4, "공격력 : ");
    UIHelper_->gotoxy(109, 4);
    std::cout << "monster->GetAttack()";

    UIHelper_->Draw(100, 5, "속도 : ");
    UIHelper_->gotoxy(107, 5);
    std::cout << "monster->GetSpeed()";

    UIHelper_->DrawBar(106, 2, 200, 200, 12);
    UIHelper_->DrawBar(106, 3, 10, 30, 8);

    //UIHelper_->DrawBar(7, 2, monster->GetHP(), monster->GetMaxHP(), 12);
    //UIHelper_->DrawBar(7, 3, 10, 30, 8);
    //UIHelper_->DrawBar(7, 4, monster->GetExp(), monster->GetMaxExp(), 2);

    UIHelper_->gotoxy(0, 30);

}

void UIManager::PrintKillCount(AchievementSystem* achieve)
{
    UIHelper_->textcolor(15);

    std::map<std::string, int> KillCount =achieve->GetAllKillCount();

    UIHelper_->Draw(1, 9, "[킬 카운트]");
    int x = 0;
    for (std::map<std::string, int>::iterator itr = KillCount.begin(); itr != KillCount.end(); itr++)
    {
        UIHelper_->gotoxy(1, 10 + x);
        std::cout << itr->first << " " << itr->second;
        x++;
    }

    UIHelper_->gotoxy(0, 30);
}

// 상점 UI
void UIManager::ShopUI()
{
    UIHelper_->Draw(20, 20, "상점UI 추가예정");
}