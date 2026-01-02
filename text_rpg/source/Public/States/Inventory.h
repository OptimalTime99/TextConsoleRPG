// Inventory.h
#pragma once

#include <memory>
#include <vector>

class Item;

class Inventory
{
public:
    explicit Inventory(int capacity = 20);

    // 인벤토리 최대 공간을 반환하는 함수
    int GetCapacity() const;

    // 인벤토리 현재 공간을 반환하는 함수
    int GetSize() const;

    // 인벤토리가 꽉 찼는지 여부를 반환하는 함수
    bool IsFull() const;

    // 인벤토리가 비었는지 여부를 반환하는 함수
    bool IsEmpty() const;

    // Factory 기반 추가: ItemDefs에 존재하는 이름만 추가 가능
    bool AddByName(const char* itemName);

    // 소유권을 외부에서 넘겨받아 추가(테스트/드랍 등)
    bool Add(std::unique_ptr<Item> item);

    // ★ 핵심: 이름으로 아이템을 "꺼내면서" 제거 (없으면 nullptr)
    std::unique_ptr<Item> TakeItemByName(const char* itemName);

    // (선택) UI/검사용: 제거 없이 조회 (없으면 nullptr)
    const Item* FindItemByName(const char* itemName) const;

private:
    int capacity_ = 20;
    std::vector<std::unique_ptr<Item>> items_;
};
