#include "States/Item.h"
#include <cassert>


Item::Item(const ItemDefinition* def) : def_(def)
{
    assert(def_ && "ItemDefinition is null.");
}

int Item::GetSellPrice(double sellRate) const
{
    assert(def_);

    if (sellRate <= 0)
    {
        return def_->Price_;
    }

    return def_->Price_ * sellRate;
}

const char* Item::GetName() const
{
    assert(def_);
    return def_->Name_;
}


ItemType Item::GetType() const
{
    assert(def_);
    return def_->Type_;
}

int Item::GetValue() const
{
    assert(def_);
    return def_->Value_;
}

int Item::GetPrice() const
{
    assert(def_);
    return def_->Price_;
}