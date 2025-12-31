#include "UI/UIManager.h"

void UIManager::ClearScreen(char str[], char str_s, int max_value)
{
    for (int i = 0; i < max_value; i++)
    {
        str[i] = str_s;
    }
}
void UIManager::EditScreen(int x, int y, char str)
{
    if (x > 0 && y > 0 && x - 1 < WIDTH_ - 1 && y - 1 < HEIGHT_ - 1)
    {
        str = ScreenData_[(y - 1) * WIDTH_ + x - 1];
    }
}

void UIManager::Draw(int x, int y, const char spr[])
{
    UIconsole_->gotoxy(x, y);
    std::cout << spr;
}




void UIManager::PrintTitle()
{
    ClearScreen(ScreenData_, ' ', 1200);
    Draw(0, 0, "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩");
    Draw(20, 5, "  __    __   __   __    __  _  __  __  _ _____ ___  ");
    Draw(20, 6, " /  \ /' _//' _/ /  \ /' _/| |/  \|  \| |_   _| __| ");
    Draw(20, 7, "| /\ |`._`.`._`.| /\ |`._`.| | /\ | | ' | | | | _|  ");
    Draw(20, 8, "|_||_||___/|___/|_||_||___/|_|_||_|_|\__| |_| |___| ");

    Draw(40, 12, "게임시작");
    Draw(40, 14, "종    료");
    Draw(0, 20, "▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩");

    int choiceX = 38;
    int choiceY = 12;

    while (true)
    {
        UIconsole_->gotoxy(choiceX, choiceY);
        std::cout << ">";

        if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            if (choiceY > 12)
            {
                Draw(choiceX, choiceY, " ");
                choiceY -= 2;
            }
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            if (choiceY < 14)
            {
                Draw(choiceX, choiceY, " ");
                choiceY += 2;
            }
        }
        Sleep(100);
    }
}

void UIManager::PrintEnding()
{

}

