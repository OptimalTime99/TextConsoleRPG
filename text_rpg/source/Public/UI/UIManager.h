#pragma once
#include "UIHelper.h"
#include "States/Player.h"
#include "States/Monster.h"
#include "Modes/AchievementSystem.h"
#include "Windows.h"
#include "conio.h"
#include <iostream>
#include <string>

class UIManager
{
public:
    UIManager()
    {
        UIHelper_ = new UIHelper;
        UIHelper_->SetConsoleSetting();
    }
    ~UIManager()
    {
        delete UIHelper_;
    }

public:
    // 타이틀 화면을 출력하고, 유저의 선택지에 따른 값을 반환.
    bool PrintTitle();

    //게임종료 전에 종료를 유저에게 알리는 화면 출력.
    void PrintOff();

    // 게임오버 화면을 출력하고, 유저의 선택지에 따른 값을 반환.
    bool PrintGameOver();

    // 엔딩화면을 출력.
    void PrintEndingEvent();

public:
    // 캐릭터 생성 UI
    std::string PrintCreateCharacter();

    // 플레이어 상태 출력
    void PrintPlayerStatus(Player* player);

    // 몬스터 상태 출력
    void MonsterStatus(Monster* monster);

    void PrintKillCount(AchievementSystem* achieve);

    // 상점 UI
    void ShopUI();
private:
    UIHelper* UIHelper_;
};