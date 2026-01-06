#include "Core/GameManager.h"
#include "States/Item.h"

GameManager* GameManager::instance = nullptr;

int main()
{
    GameManager* game = GameManager::GetInstace();

    Item::Initialize();
    while (true)
    {
        if (!game->StartGame()) // 게임 오버시 재시작 할게 아니라면 반복문 탈출
        {
            break;
        }
    }

    delete game;

    return 0;
}