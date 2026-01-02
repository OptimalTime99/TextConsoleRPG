#pragma once
#include <string>
#include "Types/ItemType.h"

class Item
{
public:
    explicit Item(const ItemDefinition* def);

    // Getter
    const char* GetName() const;
    ItemType GetType() const;
    int GetValue() const;
    int GetPrice() const;

    // 판매 가격을 반환하는 함수
    int GetSellPrice(double sellRate) const;

private:
    const ItemDefinition* def_;
};


