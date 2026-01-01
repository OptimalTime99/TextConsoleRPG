#include "States/Item.h"
#include "States/Player.h"


Item::Item(const std::string& Name, ItemType Type, int Value, int Price)
        : Name_(Name), Type_(Type), Value_(Value), Price_(Price) {}

//void Item::ApplyTo(Player* p)
//{
//    if (p != nullptr)
//    {
//        switch (Type_)
//        {
//        case ItemType::HealPotion:
//            p->HP_ = std::min(p->HP_ + Value_, p->MaxHP_);
//            break;
//
//        case ItemType::AtkPotion:
//            p->Attack_ += Value_;
//            break;
//
//        default:
//            break;
//        }
//    }
//}

int Item::GetSellPrice(double sellRate) const
{
    return static_cast<int>(Price_ * sellRate);
}

std::string Item::GetName()
{
    return Name_;
}