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


static const ItemDefinition HealPotionDef{
    "Heal 50 Potion",
    ItemType::HealPotion,
    50,
    10
};

static const ItemDefinition AtkPotionDef{
    "Atk 10 Potion",
    ItemType::AtkPotion,
    10,
    20
};
