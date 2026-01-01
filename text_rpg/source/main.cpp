#include "Core/GameManager.h"

GameManager* GameManager::instance = nullptr;

int main()
{
    GameManager* game = GameManager::GetInstace();
    game->StartGame();
    delete game;

    return 0;
}