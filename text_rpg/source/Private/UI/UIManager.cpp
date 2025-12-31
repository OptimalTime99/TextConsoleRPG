#include "UI/UIManager.h"

void UIManager::Draw(int x, int y, const std::string spr)
{
    UIconsole_->gotoxy(x, y);
    std::cout << spr;
}

void UIManager::DrawBar(int x, int y, double currentvalue, double Maxvalue, int color_num)
{
    int Bar_length = currentvalue / Maxvalue * 10;
    UIconsole_->gotoxy(x, y);
    UIconsole_->textcolor(color_num);
    for (int i = 0; i < Bar_length; i++)
    {
        std::cout << "■";
    }
    for (int i = 0; i < 10 - Bar_length; i++)
    {
        std::cout << "-";
    }
}

int UIManager::UserSelection(int x, int y, int n)
{
    int choiceX = x;
    int choiceY = y;
    int MaxY = y + 2*(n-1);
    int choice = 1;

    while (true)
    {
        UIconsole_->gotoxy(choiceX, choiceY);
        std::cout << ">";

        if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            if (choiceY > y)
            {
                Draw(choiceX, choiceY, " ");
                choiceY -= 2;
                choice--;
            }
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            if (choiceY < MaxY)
            {
                Draw(choiceX, choiceY, " ");
                choiceY += 2;
                choice++;
            }
        }
        if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {
            system("cls");
            return choice;
        }
        Sleep(100);
    }
}

void UIManager::PrintLine(const std::string& msg, int color_num, int speed)
{
    UIconsole_->textcolor(color_num);
    for (const char& c : msg)
    {
        std::cout << c;
        Sleep(speed);
    }
    UIconsole_->textcolor(15);
}

bool UIManager::PrintTitle()
{
    UIconsole_->textcolor(4);
    Draw(0, 5, "          :::      ::::::::   ::::::::      :::      :::::::: :::::::::::     :::     ::::    ::: ::::::::::: :::::::::: ");
    Draw(0, 6, "       :+: :+:   :+:    :+: :+:    :+:   :+: :+:   :+:    :+:    :+:       :+: :+:   :+:+:   :+:     :+:     :+:         ");
    Draw(0, 7, "     +:+   +:+  +:+        +:+         +:+   +:+  +:+           +:+      +:+   +:+  :+:+:+  +:+     +:+     +:+          ");
    Draw(0, 8, "   +#++:++#++: +#++:++#++ +#++:++#++ +#++:++#++: +#++:++#++    +#+     +#++:++#++: +#+ +:+ +#+     +#+     +#++:++#      ");
    Draw(0, 9, "  +#+     +#+        +#+        +#+ +#+     +#+        +#+    +#+     +#+     +#+ +#+  +#+#+#     +#+     +#+            ");
    Draw(0, 10, " #+#     #+# #+#    #+# #+#    #+# #+#     #+# #+#    #+#    #+#     #+#     #+# #+#   #+#+#     #+#     #+#             ");
    Draw(0, 11, "###     ###  ########   ########  ###     ###  ######## ########### ###     ### ###    ####     ###     ##########       ");
    UIconsole_->textcolor(15);
    Draw(52, 16, "게임시작");
    Draw(52, 18, "종   료");

    int userselect = UserSelection(48, 16, 2);
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

void UIManager::PrintEndingEvent()
{
    
}

void UIManager::PrintgameUI()
{
    Draw(102, 1, "HP");
    Draw(107, 1, "[");
    Draw(118, 1, "]");
    Draw(102, 2, "총알");
    Draw(107, 2, "[");
    Draw(118, 2, "]");
    Draw(102, 3, "Exp");
    Draw(107, 3, "[");
    Draw(118, 3, "]");
    Draw(102, 4, "Gold");

    while (true)
    {
        DrawBar(108, 1, 160, 200, 12);
        DrawBar(108, 2, 15, 30, 8);
        DrawBar(108, 3, 30, 100, 2);
    }

    UIconsole_->gotoxy(0, 30);
}
