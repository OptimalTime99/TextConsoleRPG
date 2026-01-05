#include "States/Item.h"
#include "Types/StatusType.h"
#include "Types/ItemType.h"

std::map<ItemType, Item> Item::itemRegistry_;
Item::Item(ItemType name, int price) : name_(name), price_(price) {}

void Item::AddEffect(StatusType status, int value)
{
    effect_[status] = value;
}

void Item::Initialize()
{
    // 하급 체력 포션 정의
    Item HP_Potion(ItemType::LowHealthPotion, 10);
    HP_Potion.AddEffect(StatusType::HP, 50);
    itemRegistry_[ItemType::LowHealthPotion] = HP_Potion;

    // 하급 공격력 포션 정의
    Item ATK_Potion(ItemType::LowAttackPotion, 15);
    HP_Potion.AddEffect(StatusType::ATK, 10);
    itemRegistry_[ItemType::LowAttackPotion] = ATK_Potion;
}

const Item* Item::GetData(ItemType name)
{
    if (itemRegistry_.find(name) != itemRegistry_.end())
    {
        return &itemRegistry_[name];
    }

    return nullptr; // 없는 아이템일 경우
}

ItemType Item::GetName() const
{
    return name_;
}

int Item::GetPrice() const
{
    return price_;
}

std::map<StatusType, int> Item::GetEffect() const
{
    return effect_;
}

const std::map<ItemType, Item>& Item::GetAllItems()
{
    return itemRegistry_;
}

void Item::SetName(ItemType name)
{
    name_ = name;
}

void Item::SetPrice(int price)
{
    if(price < 0) price_ = 0;
        
    price_ = price;
}

void Item::SetEffect(const std::map<StatusType, int>& effect)
{
    if (effect.empty()) return;

    effect_ = effect;
}