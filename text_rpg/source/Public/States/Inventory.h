#pragma once
#include <map>
#include <string>
#include "Types/ItemType.h"

class Inventory
{
public:
    // 아이템 추가 함수
    void AddItem(ItemType name, int count);

    // 아이템 제거 함수
    bool RemoveItem(ItemType name, int count);

    // 아이템 수량 조회 함수
    int GetItemCount(ItemType name) const;

private:
    // 아이템 이름과 수량을 저장하는 맵
    std::map<ItemType, int> inventory_;
};