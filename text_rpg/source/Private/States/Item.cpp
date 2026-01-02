#include "States/Item.h"
#include "Types/ItemType.h"


Item::Item(const ItemDefinition* def) : def_(def) {}

int Item::GetSellPrice(double sellRate) const
{
    if (sellRate <= 0)
    {
        return def_->Price_;
    }

    return def_->Price_ * sellRate;
}

const char* Item::GetName() const
{
    return def_->Name_;
}


ItemType Item::GetType() const
{
    return def_->Type_;
}

int Item::GetValue() const
{
    return def_->Value_;
}

int Item::GetPrice() const
{
    return def_->Price_;
}