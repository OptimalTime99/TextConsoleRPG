#pragma once
#include <string>
#include "States/Player.h"

enum ItemType
{
    HealPotion,
    AtkPotion
};

class Item
{
public:
    Item(const std::string& Name, ItemType Type, int Value, int Price);

    // 플레이어에게 아이템 효과를 적용하는 함수
    //void ApplyTo(Player* p);

    // 판매 가격을 반환하는 함수
    int GetSellPrice(double sellRate) const;

    std::string GetName();

private:
    std::string Name_;
    ItemType Type_;
    int Value_;
    int Price_;
};