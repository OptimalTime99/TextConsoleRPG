#include "UI/UIHelper.h"

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
            SetWindowPos(hwnd, nullptr, 0, 0, WIDTH_-100, HEIGHT_, SWP_NOZORDER | SWP_NOMOVE);
        }
        else
        {
            // Window 11
            SetWindowPos(owner, nullptr, 0, 0, WIDTH_-100, HEIGHT_, SWP_NOZORDER | SWP_NOMOVE);
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

void UIHelper::ConsoleClear(int x, int y, int mx, int my)
{
    for (int i = x; i <= mx; i++)
    {
        for (int j = y; j <= my; j++)
        {
            Draw(i, j, " ");
        }
    }
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
            if (i == x || i == sx)
            {
                Draw(i, j, "▒");
            }
            if (j == y || j == sy)
            {
                Draw(i, j, "■");
            }
        }
    }
    textcolor(15);
}

void UIHelper::PrintUIBox()
{
    BoxUI(0, 0, 159, 42, 15);
    BoxUI(0, 0, 35, 42, 15);
    BoxUI(124, 0, 159, 42, 15);
    BoxUI(0, 25, 159, 42, 15);
}

void UIHelper::Draw(int x, int y, const std::string spr)
{
    gotoxy(x, y);
    std::cout << spr;
}

void UIHelper::PrintFile(int x, int y, const std::string& filename, int color_num)
{
    textcolor(color_num);
    std::string line;
    std::ifstream file(filename);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            Draw(x, y, line);
            y++;
        }
    }
    else
    {
        std::cerr << "파일을 열 수 없습니다." << std::endl;
    }
    textcolor(15);
}

void UIHelper::DrawBar(int x, int y, int barsize, double currentvalue, double Maxvalue, int color_num)
{
    int Bar_length = currentvalue / Maxvalue * barsize;
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
    textcolor(15);
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
        std::cout << "▶";
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
        if (GetAsyncKeyState(VK_RETURN) & 0x8000)
        {
            Sleep(200);
            return choice;
        }
        Sleep(100);
    }
}

void UIHelper::PushLog(const std::string& log, int color_num)
{
    Log_.push_back({ log, color_num });
}

void UIHelper::Printlog(int x, int y, std::deque<ColoredText>& log)
{
    int defaultX = x;
    int defaultY = y;
    if (log.size() == 16)
    {
        y = defaultY;
        log.erase(log.begin());
        for (const auto& line : log)
        {
            textcolor(line.colornum_);
            Draw(x, y, line.text_);
            y++;
        }
    }
    else
    {
        for (const auto& line : log)
        {
            textcolor(line.colornum_);
            Draw(x, y, line.text_);
            y++;
        }
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

std::deque<ColoredText>& UIHelper::GetLog()
{
    return Log_;
}
