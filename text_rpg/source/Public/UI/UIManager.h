#pragma once
#include "UIConsole.h"
#include <iostream>
#include <string>

class UIManager
{
public:
    UIManager()
    {
        UIConsole* UIconsole = new UIConsole;
        ScreenData_ = new char[WIDTH_ * HEIGHT_];
        UIconsole->SetConsole();
    }
    ~UIManager()
    {
        delete UIconsole_;
        delete ScreenData_;
    }

    // 화면을 특정한 문자로 초기화
    void ClearScreen(char str[], char str_s, int max_value);

    // 화면을 특정한 문자로 구성
    void EditScreen(int x, int y, char str);

    // 원하는 위치에 문자를 출력
    void Draw(int x, int y, const char spr[]);

public:
    void PrintLine(const std::string& msg);
    void LogEvent(const std::string& msg);
    void PrintStatus();
public:
    void PrintTitle();
    void PrintEnding();

private:
    UIConsole* UIconsole_;
    char* ScreenData_;
    int WIDTH_ = 100;
    int HEIGHT_ = 100;
};