#include "Core/GameManager.h"
#include "States/Player.h"
#include "UI/UIManager.h"
#include "Modes/BattleSystem.h"
#include "Modes/ShopSystem.h"
#include "Types/GameMode.h"

GameManager::GameManager()
{
    //Player_ = new Player();
    //UI_ = new UIManager();
    Battle_ = new BattleSystem();
    Shop_ = new ShopSystem();
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
    /*if (UI_->PrintTitle())
    {
        GameMode gamemode_ = GameMode::PlayGame;
        Player_->SetName(UI_->PrintCreateCharacter());

        while (gamemode_ != GameMode::GameEnd)
        {
            Battle_->StartBattle(Player_, UI_);
        }
    }
    else
    {
        UI_->PrintOff();
    }*/
}

void GameManager::StartBattle()
{
    //Battle_->StartBattle(Player_, UI_);
}

void GameManager::VisitShop()
{

}

void GameManager::BattleDone()
{

}
