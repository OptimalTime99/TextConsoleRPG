#include "Core/GameManager.h"
#include "States/Player.h"
#include "UI/UIManager.h"
#include "Modes/BattleSystem.h"
#include "Modes/ShopSystem.h"
#include "Types/GameMode.h"

GameManager::GameManager()
{
    Player_ = nullptr;
    Item_ = nullptr;
    Inventory_ = new Inventory();
    UI_ = new UIManager();
    Battle_ = nullptr;
    Shop_ = new ShopSystem();
    Mode_ = GameMode::BATTLE_MODE;
}

GameManager::~GameManager()
{
    delete Player_;
    delete Item_;
    delete Inventory_;
    delete UI_;
    delete Battle_;
    delete Shop_;
}

// 인스턴스 반환용 함수
GameManager* GameManager::GetInstace()
{
    if (instance == nullptr)
    {
        instance = new GameManager();
    }
    return instance;
}

void GameManager::StartGame()
{
    if (UI_->PrintTitle())
    {
        // UI가 항상 정상적인 이름을 받아오기 때문에 이름 입력과 동시에 플레이어 객체 생성.
        Player_ = new Player(UI_->PrintCreateCharacter());
        Battle_ = new BattleSystem(Player_, Item_, UI_, Inventory_);
        Item::Initialize();
        bool bCanGameRunning = true;

        while (bCanGameRunning)
        {
            switch (Mode_)
            {
            case GameMode::BATTLE_MODE:
                StartBattle();
                break;
            case GameMode::APPLY_RWARDS:
                // 상점 방문 선택 기능 필요
                if (Player_->GetLevel() == 10)
                {
                    Mode_ = GameMode::GAMEENDING_MODE;
                }
                else
                {
                    Mode_ = GameMode::BATTLE_MODE;
                }
                break;
            case GameMode::SHOP_MODE:
                // 상점 생성
                // 상점 호출 UI
                break;
            case GameMode::GAMEOVER_MODE:
                UI_->PrintGameOver();
                bCanGameRunning = false;
                break;
            case GameMode::GAMEENDING_MODE:
                UI_->PrintEndingEvent();
                bCanGameRunning = false;
                break;
            default:
                break;
            }
        }
    }
    else
    {
        UI_->PrintOff();
    }
}

GameMode GameManager::StartBattle()
{
    return Battle_->StartBattle();
}

void GameManager::VisitShop()
{

}

void GameManager::BattleDone()
{

}
