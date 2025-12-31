#pragma once
#include "Types/GameMode.h"

class Player;
class UIManager;
class BattleSystem;
class ShopSystem;

class GameManager 
{
    // 배틀시작
    void StartBattle();

    // 상점방문
    void VisitShop();

    // 배틀 종료
    void BattleDone();

private:
    Player* Player_;
    UIManager* UI_;
    BattleSystem* Battle_;
    ShopSystem* Shop_;
    GameMode Mode_;
};