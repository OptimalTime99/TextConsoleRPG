#pragma once
class Player;
class UIManager;
class BattleSystem;
class ShopSystem;
class GameMode;

class GameManager 
{


private:
    Player* Player_;
    UIManager* UI_;
    BattleSystem* Battle_;
    ShopSystem* Shop_;
    GameMode* Mode_;
};