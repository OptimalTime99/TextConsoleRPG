#include <string>
#include "States/Inventory.h"


void Inventory::AddItem(ItemType name, int count)
{
    // 인벤토리에 아이템이 없는 경우 초기화
    if(inventory_.find(name) == inventory_.end())
    {
        inventory_[name] = 0;
    }

    inventory_[name] += count;
}

bool Inventory::RemoveItem(ItemType name, int count)
{
    // 현재 수량이 부족한 경우 제거 실패
    if(inventory_[name] < count)
    {
        return false;
    }

    inventory_[name] -= count;
    return true;
}


int Inventory::GetItemCount(ItemType name) const
{
    return inventory_.at(name);
}

const std::map<ItemType, int>& Inventory::GetInventory() const
{
    return inventory_;
}