#include <string>
#include "States/Inventory.h"


void Inventory::AddItem(std::string name, int count)
{
    // 인벤토리에 아이템이 없는 경우 초기화
    if(inventory_.find(name) == inventory_.end())
    {
        inventory_[name] = 0;
    }

    inventory_[name] += count;
}

bool Inventory::RemoveItem(std::string name, int count)
{
    // 현재 수량이 부족한 경우 제거 실패
    if(inventory_[name] < count)
    {
        return false;
    }

    inventory_[name] -= count;
    return true;
}


int Inventory::GetItemCount(std::string name) const
{
    return inventory_.at(name);
}