#pragma once

enum class ItemType
{
    HealPotion,
    AtkPotion
};

struct ItemDefinition
{
    const char* Name_;
    ItemType Type_;
    int Value_;
    int Price_;
};
