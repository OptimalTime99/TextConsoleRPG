// Inventory.cpp
#include "States/Inventory.h"

#include "Types/ItemFactory.h"
#include "States/Item.h"

#include <algorithm>
#include <cstring> // std::strcmp

Inventory::Inventory(int capacity)
    : capacity_(capacity)
{
    if (capacity_ <= 0) capacity_ = 1;
    items_.reserve(static_cast<size_t>(capacity_));
}

bool Inventory::AddByName(const char* itemName)
{
    if (!itemName) return false;
    if (IsFull())  return false;

    auto item = ItemFactory::CreateByName(itemName);
    if (!item) return false;

    items_.push_back(std::move(item));
    return true;
}

bool Inventory::Add(std::unique_ptr<Item> item)
{
    if (!item)   return false;
    if (IsFull()) return false;

    items_.push_back(std::move(item));
    return true;
}

std::unique_ptr<Item> Inventory::TakeItemByName(const char* itemName)
{
    if (!itemName) return nullptr;

    for (size_t i = 0; i < items_.size(); ++i)
    {
        // Item 이름 비교(문자열 내용 비교)
        if (items_[i] && std::strcmp(items_[i]->GetName(), itemName) == 0)
        {
            // 소유권 꺼내기
            std::unique_ptr<Item> out = std::move(items_[i]);

            // 벡터에서 제거(순서 유지)
            items_.erase(items_.begin() + static_cast<long long>(i));
            return out;
        }
    }

    return nullptr;
}

const Item* Inventory::FindItemByName(const char* itemName) const
{
    if (!itemName) return nullptr;

    for (const auto& it : items_)
    {
        if (it && std::strcmp(it->GetName(), itemName) == 0)
            return it.get();
    }
    return nullptr;
}


int Inventory::GetCapacity() const
{ 
    return capacity_;
}

int Inventory::GetSize() const
{
    return static_cast<int>(items_.size());
}

bool Inventory::IsFull() const
{
    return GetSize() >= capacity_;
}

bool Inventory::IsEmpty() const
{
    return items_.empty();
}