#include "Core/GameManager.h"
#include "States/Player.h"
#include "UI/UIManager.h"
#include "Modes/BattleSystem.h"
#include "Modes/ShopSystem.h"
#include "Types/GameMode.h"

GameManager::GameManager()
{
    Player_ = nullptr;
    UI_ = new UIManager();
    Battle_ = nullptr;
    Shop_ = new ShopSystem();
    Mode_ = GameMode::PLAY_GAME;
}

GameManager::~GameManager()
{
    delete Player_;
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
        Battle_ = new BattleSystem(Player_);

        Mode_ = GameMode::BATTLE_MODE;
        while (Mode_ == GameMode::BATTLE_MODE)
        {
            // Mode_가 BATTLE_MODE가 아닐때까지 계속 배틀
            Mode_ = StartBattle();
        }
    }
    else
    {
        UI_->PrintOff();
    }

    if (Mode_ == GameMode::GAMEOVER_MODE)
    {
        UI_->PrintGameOver();
    }
}

GameMode GameManager::StartBattle()
{
    return Battle_->StartBattle(Player_, UI_);
}

void GameManager::VisitShop()
{

}

void GameManager::BattleDone()
{

}
