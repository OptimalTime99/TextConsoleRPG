#include "Core/GameManager.h"
#include "States/Player.h"
#include "UI/UIManager.h"
#include "Modes/BattleSystem.h"
#include "Modes/ShopSystem.h"
#include "Types/GameMode.h"

GameManager::GameManager()
{
    Player_ = nullptr;
    Battle_ = nullptr;
    Inventory_ = nullptr;;
    Achieve_ = nullptr;
    UI_ = new UIManager(Inventory_);
    Shop_ = new ShopSystem();
    Mode_ = GameMode::BATTLE_MODE;
}

GameManager::~GameManager()
{
    delete UI_;
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

bool GameManager::StartGame()
{
    if (UI_->PrintTitle())
    {
        // UI가 항상 정상적인 이름을 받아오기 때문에 이름 입력과 동시에 플레이어 객체 생성.
        Player_ = new Player(UI_->PrintCreateCharacter());
        Inventory_ = new Inventory();
        UI_->SetInventory(Inventory_);
        Achieve_ = new AchievementSystem();
        Battle_ = new BattleSystem(Player_, UI_, Inventory_, Achieve_);


        bool bCanGameRunning = true;

        while (bCanGameRunning)
        {
            switch (Mode_)
            {
            case GameMode::BATTLE_MODE: // 전투 시작
                Mode_ = StartBattle();
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
                Shop_->Shop(Player_, UI_);

                break;

            case GameMode::GAMEOVER_MODE:
                bCanGameRunning = false;

                if (UI_->PrintGameOver()) // 다시 시작을 선택했을 시
                {
                    delete Battle_;
                    delete Player_;
                    delete Inventory_;
                    delete Achieve_;

                    Battle_ = nullptr;
                    Player_ = nullptr;
                    Inventory_ = nullptr;
                    Achieve_ = nullptr;

                    Mode_ = GameMode::BATTLE_MODE;
                    return true;
                }
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

    return false;
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
