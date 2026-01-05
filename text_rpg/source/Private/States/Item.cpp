#include "States/Item.h"
#include "Types/StatusType.h"


Item::Item(std::string name, int price) : name_(name), price_(price) {}

void Item::AddEffect(StatusType status, int value)
{
    effect_[status] = value;
}

void Item::Initialize()
{
    // 하급 체력 포션 정의
    Item HP_Potion("하급 체력 포션", 10);
    HP_Potion.AddEffect(StatusType::HP, 50);
    itemRegistry_["하급 체력 포션"] = HP_Potion;

    // 하급 공격력 포션 정의
    Item ATK_Potion("하급 공격력 포션", 15);
    HP_Potion.AddEffect(StatusType::ATK, 10);
    itemRegistry_["하급 공격력 포션"] = ATK_Potion;
}

const Item* Item::GetData(std::string name)
{
    if (itemRegistry_.find(name) != itemRegistry_.end())
    {
        return &itemRegistry_[name];
    }

    return nullptr; // 없는 아이템일 경우
}

std::string Item::GetName() const
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

void Item::SetName(const std::string& name)
{
    if (name_ == "") name_ = "이름 없음";

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