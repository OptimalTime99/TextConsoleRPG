#include "UI/UIManager.h"

class Player;

bool UIManager::PrintTitle()
{
    int x = 27;
    int y = 5;
    UIHelper_->textcolor(4);
    UIHelper_->Draw(x, y, "          :::      ::::::::   ::::::::      :::      :::::::: :::::::::::     :::     ::::    ::: ::::::::::: :::::::::: ");
    UIHelper_->Draw(x, y+1, "       :+: :+:   :+:    :+: :+:    :+:   :+: :+:   :+:    :+:    :+:       :+: :+:   :+:+:   :+:     :+:     :+:         ");
    UIHelper_->Draw(x, y+2, "     +:+   +:+  +:+        +:+         +:+   +:+  +:+           +:+      +:+   +:+  :+:+:+  +:+     +:+     +:+          ");
    UIHelper_->Draw(x, y+3, "   +#++:++#++: +#++:++#++ +#++:++#++ +#++:++#++: +#++:++#++    +#+     +#++:++#++: +#+ +:+ +#+     +#+     +#++:++#      ");
    UIHelper_->Draw(x, y+4, "  +#+     +#+        +#+        +#+ +#+     +#+        +#+    +#+     +#+     +#+ +#+  +#+#+#     +#+     +#+            ");
    UIHelper_->Draw(x, y+5, " #+#     #+# #+#    #+# #+#    #+# #+#     #+# #+#    #+#    #+#     #+#     #+# #+#   #+#+#     #+#     #+#             ");
    UIHelper_->Draw(x, y+6, "###     ###  ########   ########  ###     ###  ######## ########### ###     ### ###    ####     ###     ##########       ");
    UIHelper_->textcolor(15);
    UIHelper_->Draw(x+53, y+11, "게임시작");
    UIHelper_->Draw(x+53, y+13, "종   료");

    int userselect = UIHelper_->UserSelection(x+51, y+11, 2);
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
    int y = 5;
    system("cls");
    UIHelper_->textcolor(4);
    UIHelper_->Draw(x, y, "      ::::::::      :::       :::   :::   ::::::::::         ::::::::  :::     ::: :::::::::: ::::::::: ");
    UIHelper_->Draw(x, y+1, "    :+:    :+:   :+: :+:    :+:+: :+:+:  :+:               :+:    :+: :+:     :+: :+:        :+:    :+: ");
    UIHelper_->Draw(x, y+2, "   +:+         +:+   +:+  +:+ +:+:+ +:+ +:+               +:+    +:+ +:+     +:+ +:+        +:+    +:+  ");
    UIHelper_->Draw(x, y+3, "  :#:        +#++:++#++: +#+  +:+  +#+ +#++:++#          +#+    +:+ +#+     +:+ +#++:++#   +#++:++#:    ");
    UIHelper_->Draw(x, y+4, " +#+   +#+# +#+     +#+ +#+       +#+ +#+               +#+    +#+  +#+   +#+  +#+        +#+    +#+    ");
    UIHelper_->Draw(x, y+5, "#+#    #+# #+#     #+# #+#       #+# #+#               #+#    #+#   #+#+#+#   #+#        #+#    #+#     ");
    UIHelper_->Draw(x, y+6, "########  ###     ### ###       ### ##########         ########      ###     ########## ###    ###      ");
    UIHelper_->textcolor(15);
    UIHelper_->Draw(x+42, y+11, "타이틀 화면으로");
    UIHelper_->Draw(x+42, y+13, "게  임  종  료");

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
    UIHelper_->gotoxy(65, 18);
    UIHelper_->textcolor(3);
    std::cout << "스토리를 시작하려면 ENTER를 누르세요." << std::endl;
    UIHelper_->textcolor(0);
    UIHelper_->gotoxy(65, 19);
    system("pause");
    system("cls");
    Sleep(1000);

    UIHelper_->textcolor(6);
    UIHelper_->Draw(60, 18, "                                    .:. ..::---==-----::........       ");
    UIHelper_->Draw(60, 19, "                                ...:-++=. .-=-=====--::...             ");
    UIHelper_->Draw(60, 20, "                            . :-=+*+-.::---:::::--:....                ");
    UIHelper_->Draw(60, 21, "                          ...   :==:.:=+=+=-....-... .                 ");
    UIHelper_->Draw(60, 22, "                       ..:+*+*+:..:+-  ...:-:....:-.                   ");
    UIHelper_->Draw(60, 23, "                     ..-**=+**+-:+:    ..::-=--.                       ");
    UIHelper_->Draw(60, 24, "                   .:=***=***--:=.. :.:::-:.::-.. .                    ");
    UIHelper_->Draw(60, 25, "                 ..-*#***+**-..=..  -- .: :.:=:..=*-. ..               ");
    UIHelper_->Draw(60, 26, "                .:+****=.:-=:::=.  .:.......--..  .:                   ");
    UIHelper_->Draw(60, 27, "               .-******+:.   .:-.  ::.:....-=:.     .                  ");
    UIHelper_->Draw(60, 28, "             ..-******++==+=.:.=:    .: .-:=: ...                      ");
    UIHelper_->Draw(60, 29, "             .=*+**+++++=-==-:.:--:::::. .... :++:.                    ");
    UIHelper_->Draw(60, 30, "            .-++++++=====--:::..:----.. : ..                           ");
    UIHelper_->Draw(60, 31, "           .:=========--::-. ..:....   ...:.     .                     ");
    UIHelper_->Draw(60, 32, "           .-===--:::--::::..... . ..                                  ");
    UIHelper_->Draw(60, 33, "          .:---:::::::..........                                       ");
    UIHelper_->Draw(60, 34, "          .::..::::..........                  -- = ::----::::.:::     ");
    UIHelper_->textcolor(15);

    UIHelper_->gotoxy(60, 10);
    UIHelper_->PrintLine("2549년", 11, 60);
    UIHelper_->gotoxy(60, 12);
    UIHelper_->PrintLine("문명의 발전은 인류를 더 먼 곳까지 데리고 갔지만", 11, 60);
    UIHelper_->gotoxy(60, 14);
    UIHelper_->PrintLine("나아간 거리만큼 거대해진 욕심으로 끊임없이 전쟁이 이어졌다.", 11, 60);
    Sleep(1000);
    
    system("cls");

    UIHelper_->textcolor(13);
    UIHelper_->Draw(54, 2, "@@@@@@@@@@@@@@@@@@@@@@@@%%%%%%%%%%%%%%%%%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    UIHelper_->Draw(54, 3, "@@@@@@@@@@@@@@@@@@@@@@@@%%%%%%%%#**+==++*%%%%%@@@@@@@@@@@@@@@@@@@@@@@@@");
    UIHelper_->Draw(54, 4, "@@@@@@@@@@@@@@@@@@@@@@@@%%%%##***++===--::.:#%%%%@@@@@@@@@@@@@@@@@@@@@@");
    UIHelper_->Draw(54, 5, "@@@@@@@@@@@@@@@@@@@@@@@%%%###******++===--:. .#%%@@@@@@@@@@@@@@@@@@@@@@");
    UIHelper_->Draw(54, 6, "@@@@@@@@@@@@@@@@@@@@@%%%%####********+++=--:.  *%@@@@@@@@@@@@@@@@@@@@@@");
    UIHelper_->Draw(54, 7, "@@@@@@@@@@@@@@@@@@@@@%%%############***++=-:.  :%@@@@@@@@@@@@@@@@@@@@@@");
    UIHelper_->Draw(54, 8, "@@@@@@@@@@@@@@@@@@%%%%%%#############***+=-:.  .#@%%@@@@@@@@@@@@@@@@@@@");
    UIHelper_->Draw(54, 9, "@@@@@@@@@@@@@@@@@@%%%%%##############***+=-:.   *%%%@@@@@@@@@@@@@@@@@@@");
    UIHelper_->Draw(54, 10, "@@@@@@@@@@@@@@@@@@%%%%%#**#####%%%####**+=-:    +%%%@@@@@@@@@@@@@@@@@@@");
    UIHelper_->Draw(54, 11, "@@@@@%%%%%%%%@@@@@%%%%%#***####%######**+=-.    . :%@@@@@@@@@@@@@@@@@@@");
    UIHelper_->Draw(54, 12, "@@@%%%%#*++#%%%@@@%%%%******########***+=-:.      :%@@@@@@@@@@@@@@@@@@@");
    UIHelper_->Draw(54, 13, "@@@%%*#%%*-=#%%@@@@%%%#*+*************+=--::.     +%@@@@@@@@@@@@@@@@@@@");
    UIHelper_->Draw(54, 14, "%%%++%#*%%#-+%%@@@%%%%%#++****###*****+==---:     %%@@@@@@@@@@@@@@@@@@@");
    UIHelper_->Draw(54, 15, "%%%%*+%#*%%#-+%%%%%%%%%#+=********++++++===-:    -%%@@@@@@@%%%%%%%%%%%@");
    UIHelper_->Draw(54, 16, "%%%%%*=%**%%#=+%%%%%%%%%%+--+***++=======-.    .#%%%@@@@@%%%#=+#+-#%%%@");
    UIHelper_->Draw(54, 17, "@@@@@@#-**%%%#-=%%%@@@@%%**+:-:..::-:           *%%%@@@@@@%%*%%#:*++%%@");
    UIHelper_->Draw(54, 18, "%%%@@@%+*%%%%%#--#%%%%@@%#-*##*****#=.::---:    *%%%@@%%%%*#%%++##-.=%@");
    UIHelper_->Draw(54, 19, "%%@@@@%%=+%%%%%%=-#%%%@%%%=:-+*****#+.:---:     -#%%@@%%#*%%#-##=.:#%%@");
    UIHelper_->Draw(54, 20, "@@@@@@%%%%++%#%%%+::*#=. .+:-:=:-==*=.   .           =##%%*+#-.=%%%%@@@");
    UIHelper_->Draw(54, 21, "@@@@@@@@@%%=###%%%+::.   :*#-:::---:               .*%%%#+%*: -%%%%@@@@");
    UIHelper_->Draw(54, 22, "%%%%%%%%%#*#-*##%%%*: :  :+*#+..--:..             -#%%%+*#:..#%%%%@@@@@");
    UIHelper_->Draw(54, 23, "%#=::. ..    .*##%%%*=.. .++*##=:-----:.        .-#%%*+%=.    .=%%%%%%%");
    UIHelper_->textcolor(15);

    UIHelper_->gotoxy(60, 26);
    UIHelper_->PrintLine("전쟁이 길어지면서 많은 자원과 인력을 소모하는 전장보다", 11, 60);
    UIHelper_->gotoxy(60, 28);
    UIHelper_->PrintLine("상대의 주요 인물을 암살하는 임무가 전쟁의 승패를 좌우하게 된다.", 11, 60);
    Sleep(1000);

    system("cls");

    while (true)
    {
        UIHelper_->gotoxy(65, 13);
        UIHelper_->PrintLine("요원 이름 입력", 15, 60);
        UIHelper_->gotoxy(65, 15);
        std::string Inputname = "";
        getline(std::cin, Inputname);

        if (Inputname.empty())
        {
            UIHelper_->gotoxy(65, 17);
            UIHelper_->PrintLine("올바른 이름을 다시 입력해주세요", 3, 15);
            Sleep(700);
            system("cls");
            continue;
        }
        else
        {
            UIHelper_->gotoxy(65, 20);
            UIHelper_->PrintLine("요원 정보 탐색 중...", 2, 50);
            Sleep(1000);
            UIHelper_->gotoxy(65, 20);
            UIHelper_->PrintLine("요원 정보 불러오는 중...", 4, 50);
            Sleep(1000);
            UIHelper_->gotoxy(65, 20);
            UIHelper_->PrintLine("작전 지역으로 이동 중...", 9, 50);
            Sleep(1000);
            system("cls");
            return Inputname;
        }
    }
}

void UIManager::PrintPlayerStatus(Player* player)
{
    int x = 1;
    int y = 1;
    UIHelper_->textcolor(15);
    UIHelper_->Draw(x, y, "요원명 :");
    UIHelper_->gotoxy(x+9, y);
    std::cout << player->GetName();

    UIHelper_->Draw(x, y+1, "HP");
    UIHelper_->Draw(x+5, y+1, "[");
    UIHelper_->Draw(x+16, y+1, "]");
    UIHelper_->gotoxy(x+18, y+1);
    std::cout << player->GetHP() << " / " << player->GetMaxHP();

    UIHelper_->Draw(x, y+2, "총알");
    UIHelper_->Draw(x+5, y+2, "[");
    UIHelper_->Draw(x+16, y+2, "]");
    UIHelper_->gotoxy(x+18, y+2);
    std::cout << 10 << " / " << 30;

    UIHelper_->Draw(x, y+3, "Exp");
    UIHelper_->Draw(x+5, y+3, "[");
    UIHelper_->Draw(x+16, y+3, "]");
    UIHelper_->gotoxy(x+18, y+3);
    std::cout << player->GetExp() << " / " << player->GetMaxExp();

    UIHelper_->Draw(x, y+4, "공격력 : ");
    UIHelper_->gotoxy(x+9, y+4);
    std::cout << player->Attack();

    UIHelper_->Draw(x, y+5, "속도 : ");
    UIHelper_->gotoxy(x+7, y+5);
    std::cout << "player->GetSpeed()";

    UIHelper_->Draw(x, y+6, "Gold : ");
    UIHelper_->gotoxy(x+7, y+6);
    std::cout << player->GetGold();

    UIHelper_->DrawBar(x+6, y+1, player->GetHP(), player->GetMaxHP(), 12);
    UIHelper_->DrawBar(x+6, y+2, 10, 30, 8);
    UIHelper_->DrawBar(x+6, y+3, player->GetExp(), player->GetMaxExp(), 2);

    UIHelper_->gotoxy(0, 45);
}

void UIManager::PrintMonsterStatus(Monster* monster)
{
    int x = 110;
    int y = 1;
    UIHelper_->textcolor(15);
    UIHelper_->Draw(x, y, "타겟 :");
    UIHelper_->gotoxy(x+7, y);
    std::cout << "monster->GetName()";

    UIHelper_->Draw(x, y+1, "HP");
    UIHelper_->Draw(x+5, y+1, "[");
    UIHelper_->Draw(x+16, y+1, "]");
    UIHelper_->gotoxy(x+18, y+1);
    std::cout << "monster->GetHP()" << " / " << "monster->GetMaxHP()";

    UIHelper_->Draw(x, y+2, "총알");
    UIHelper_->Draw(x+5, y+2, "[");
    UIHelper_->Draw(x+16, y+2, "]");
    UIHelper_->gotoxy(x+18, y+2);
    std::cout << 10 << " / " << 30;

    UIHelper_->Draw(x, y+3, "공격력 : ");
    UIHelper_->gotoxy(x+9, y+3);
    std::cout << "monster->GetAttack()";

    UIHelper_->Draw(x, y+4, "속도 : ");
    UIHelper_->gotoxy(x+7, y+4);
    std::cout << "monster->GetSpeed()";

    UIHelper_->DrawBar(x+6, y+1, 200, 200, 12);
    UIHelper_->DrawBar(x+6, y+2, 10, 30, 8);

    //UIHelper_->DrawBar(x+6, y+1, monster->GetHP(), monster->GetMaxHP(), 12);
    //UIHelper_->DrawBar(x+6, y+2, 10, 30, 8);

    UIHelper_->gotoxy(0, 45);

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
void UIManager::PrintShop()
{
    UIHelper_->Draw(20, 20, "상점UI 추가예정");
}