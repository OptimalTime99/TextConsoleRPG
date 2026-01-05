#pragma once
#include "UIHelper.h"
#include "States/Player.h"
#include "States/Monster.h"
#include "Modes/AchievementSystem.h"
#include "Types/ItemType.h"
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
    void PrintMonsterStatus(Monster* monster);

    // 킬 카운트 출력
    void PrintKillCount(AchievementSystem* achieve);

    // 전투대상 조우시 출력
    void PrintBattleStart(Player* p, Monster* m);

    // 몬스터가 데미지를 받을 때 출력
    void PrintMonsterTakeDamage(Monster* m);

    // 플레이어가 데미지를 받을 때 출력
    void PrintPlayerTakeDamage(Player* p);

    // 아이템 사용 시 출력로그
    void PrintUseItem(Item* item);

    void PrintVictory();

    // 일반 보상 획득 출력
    void PrintFixedRewards(int exp_reward, int levelup_count, int gain_golds);

    // 아이템 보상 획득 출력
    void PrintItemRewards();

    // 상점 UI
    void PrintShop();
private:
    UIHelper* UIHelper_;
};