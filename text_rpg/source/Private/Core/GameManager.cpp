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
                Mode_ = Battle_->StartBattle(false);
                break;

            case GameMode::APPLY_RWARDS:
                // 상점 방문 선택 기능 필요
                // 상점 방문 선택 UI 출력
                if (Shop_->EnterChoice(Player_, UI_))
                {
                    // 상점 방문
                    Mode_ = GameMode::SHOP_MODE;
                    break;
                }

                if (Player_->GetLevel() == 10)
                {
                    Mode_ = GameMode::BOSS_BATTLE;
                }
                else
                {
                    Mode_ = GameMode::BATTLE_MODE;
                }
                break;

            case GameMode::BOSS_BATTLE:
                // 보스 연출 출력 부분
                // 보스 연출 출력하고 보스배틀 시작
                if (Battle_->StartBattle(true) == GameMode::APPLY_RWARDS)
                {
                    // 보스전을 승리 했다면 엔딩 출력
                    Mode_ = GameMode::GAMEENDING_MODE;
                }
                break;

            case GameMode::SHOP_MODE:
                // 상점 생성
                // 상점 호출 UI
                Shop_->Shop(Inventory_, Player_, UI_);

                if (Player_->GetLevel() == 10)
                {
                    // 도전기능을 구현할 거면 보스전으로
                    Mode_ = GameMode::BOSS_BATTLE;
                }
                else
                {
                    Mode_ = GameMode::BATTLE_MODE;
                }
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