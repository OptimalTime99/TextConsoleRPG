#include "Core/GameManager.h"
#include "States/Player.h"
#include "UI/UIManager.h"
#include "Modes/BattleSystem.h"
#include "Modes/ShopSystem.h"
#include "Types/GameMode.h"

GameManager::GameManager()
{
    Player_ = new Player();
    UI_ = new UIManager();
    Battle_ = new BattleSystem();
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
        Player_->SetName(UI_->PrintCreateCharacter());


        Mode_ = GameMode::BATTLE_MODE;
        while (Mode_ == GameMode::BATTLE_MODE)
        {
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
