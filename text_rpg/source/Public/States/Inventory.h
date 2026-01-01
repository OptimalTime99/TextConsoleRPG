#pragma once
#include <vector>
#include "States/Item.h"

class Inventory
{
public:
    // 아이템을 인벤토리에 추가하는 함수
    void Add(const Item& item);

    // 인덱스로 아이템을 인벤토리에서 제거하는 함수(폐기)
    void RemoveByIndex(int idx);

    // 인벤토리가 비어있는지 확인하는 함수
    bool IsEmpty() const;

    // 아이템 개수를 반환하는 함수
    int GetCount() const;

    // 전투 중 사용할 아이템의 인덱스를 반환하는 함수
    int GetRandomUsableIndex() const;

    // 아이템을 조회하는 함수
    Item GetItem(int idx) const;

    // 아이템을 꺼내며 제거하는 함수(사용/판매)
    Item TakeItem(int idx);

private:
    std::vector<Item> Items_;
};


