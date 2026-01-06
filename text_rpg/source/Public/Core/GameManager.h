#pragma once
#include "Types/GameMode.h"

class Player;
class UIManager;
class BattleSystem;
class ShopSystem;
class Item;
class Inventory;
class AchievementSystem;

class GameManager 
{
private:
    // 싱글톤 클래스임을 알려주기 위해 상단이 private로 만듬
    GameManager();

public:
    // 복사 생성자와 대입 연산자를 삭제하여 복사 방지
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;

    // 소멸자로 동적할당했던 변수들 제거
    ~GameManager();

    static GameManager* GetInstace();

    // 게임시작
    bool StartGame();

private:
    static GameManager* instance;   // 유일한 게임매니저를 가리킬 정적 포인터
    Player* Player_;    // 플레이어
    Inventory* Inventory_;
    AchievementSystem* Achieve_;
    UIManager* UI_; // UI
    BattleSystem* Battle_;  // 배틀시스템
    ShopSystem* Shop_;  // 상점시스템
    GameMode Mode_; // 게임모드 eNUM;
};