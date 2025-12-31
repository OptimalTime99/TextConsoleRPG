#pragma once
#include "UIConsole.h"
#include <iostream>
#include <string>
#include <fstream>

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
    // 원하는 위치에 문자를 출력
    void Draw(int x, int y, const std::string spr);
    
    void DrawBar(int x, int y, double currentvalue, double Maxvalue, int color_num);

    // 메시지 출력 함수. 속도 조정 가능.
    void PrintLine(const std::string& msg, int color_num, int speed);

    // 유저 선택 함수. xy는 위치 n은 선택지 개수
    int UserSelection(int x, int y, int n);

public:
    // 타이틀 화면을 출력하고, 유저의 선택지에 따른 값을 반환.
    bool PrintTitle();

    //게임종료 전에 종료를 유저에게 알리는 화면 출력.
    void PrintOff();

    // 게임오버 화면을 출력하고, 유저의 선택지에 따른 값을 반환.
    int PrintGameOver();

    // 엔딩화면을 출력.
    void PrintEndingEvent();

    // 게임전반적인 UI 출력.
    void PrintgameUI();

public:
    // 캐릭터 생성 UI
    std::string PrintCreateCharacter();
    
    // 전투 UI
    void BattleUI();

    // 상점 UI
    void ShopUI();

private:
    UIConsole* UIconsole_;
    char* ScreenData_;
    int WIDTH_ = 150;
    int HEIGHT_ = 100;
};