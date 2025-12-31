#include <cassert>
#include <random>
#include "States/Inventory.h"

void Inventory::Add(const Item& item)
{
    Items_.push_back(item);
}

void Inventory::RemoveByIndex(int idx)
{
    assert(idx >= 0 && idx < static_cast<int>(Items_.size()));

    Items_.erase(Items_.begin() + idx);
}

bool Inventory::IsEmpty() const
{
    return Items_.empty();
}

int Inventory::GetCount() const
{
    return static_cast<int>(Items_.size());
}

int Inventory::GetRandomUsableIndex() const
{
    if (Items_.empty()) return -1;

    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, static_cast<int>(Items_.size()) - 1);

    return dist(gen);
}

Item Inventory::GetItem(int idx) const
{
    assert(idx >= 0 && idx < static_cast<int>(Items_.size()));

    return Items_[idx];
}

Item Inventory::TakeItem(int idx)
{
    assert(idx >= 0 && idx < static_cast<int>(Items_.size()));

    Item item = Items_[idx];
    Items_.erase(Items_.begin() + idx);

    return item;
}