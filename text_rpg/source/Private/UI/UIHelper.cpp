#include "UI/UIHelper.h"
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACEBAR 32

HWND hwnd = GetConsoleWindow();
HWND owner = GetWindow(hwnd, GW_OWNER);
HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

void UIHelper::SetConsoleSetting()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    if (hwnd != NULL)
    {
        if (owner == NULL)
        {
            // Window 10
            SetWindowPos(hwnd, nullptr, 0, 0, WIDTH_, HEIGHT_, SWP_NOZORDER | SWP_NOMOVE);
        }
        else
        {
            // Window 11
            SetWindowPos(owner, nullptr, 0, 0, WIDTH_, HEIGHT_, SWP_NOZORDER | SWP_NOMOVE);
        }
    }
    else
    {
        std::cout << "콘솔 창 핸들을 가져올 수 없습니다." << std::endl;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    SetConsoleTitle(TEXT("SF TEXT RPG"));
    COORD newBufferSize = { WIDTH_, HEIGHT_ };
    SetConsoleScreenBufferSize(consoleHandle, newBufferSize);
    SMALL_RECT windowRect = { 0, 0, WIDTH_ - 1, HEIGHT_ - 1 };
    SetConsoleWindowInfo(consoleHandle, TRUE, &windowRect);

    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = 0;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void UIHelper::textcolor(int color_num)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_num);
}

void UIHelper::gotoxy(int x, int y)
{
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(consoleHandle, Cur);
}

void UIHelper::BoxUI(int x, int y, int sx, int sy, int color_num)
{
    textcolor(color_num);
    for (int i = x; i <= sx; i++)
    {
        for (int j = y; j <= sy; j++)
        {
            if (j == y || j == sy)
            {
                Draw(i, j, "▒");
            }
            if (i == x || i == sx)
            {
                Draw(i, j, "▒");
            }
        }
    }
}

void UIHelper::Draw(int x, int y, const std::string spr)
{
    gotoxy(x, y);
    std::cout << spr;
}

void UIHelper::DrawBar(int x, int y, double currentvalue, double Maxvalue, int color_num)
{
    int Bar_length = currentvalue / Maxvalue * 10;
    gotoxy(x, y);
    textcolor(color_num);
    for (int i = 0; i < Bar_length; i++)
    {
        std::cout << "■";
    }
    for (int i = 0; i < 10 - Bar_length; i++)
    {
        std::cout << "-";
    }
}

int UIHelper::UserSelection(int x, int y, int n)
{
    int choiceX = x;
    int choiceY = y;
    int MaxY = y + 2 * (n - 1);
    int choice = 1;

    while (true)
    {
        gotoxy(choiceX, choiceY);
        std::cout << ">";
        if (GetAsyncKeyState(VK_UP) & 0x8000)
        {
            if (choiceY > y)
            {
                Draw(choiceX, choiceY, " ");
                choiceY -= 2;
                choice--;
            }
            Sleep(100);
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000)
        {
            if (choiceY < MaxY)
            {
                Draw(choiceX, choiceY, " ");
                choiceY += 2;
                choice++;
            }
            Sleep(100);
        }
        if (GetAsyncKeyState(VK_SPACE) & 0x8000)
        {
            system("cls");
            Sleep(200);
            return choice;
        }
        Sleep(100);
    }
}

void UIHelper::PrintLine(const std::string& msg, int color_num, int speed)
{
    textcolor(color_num);
    for (const char& c : msg)
    {
        std::cout << c;
        Sleep(speed);
    }
    textcolor(15);
}
