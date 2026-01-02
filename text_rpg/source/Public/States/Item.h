#pragma once

#include "Types/ItemType.h"   // ItemType, ItemDefinition
#include <memory>

class ItemFactory; // forward declaration

class Item
{
public:
    // Item은 값 객체처럼 쓰되 "복사"는 막고(정의 포인터 공유는 괜찮지만 의도 명확히)
    Item(const Item&) = delete;
    Item& operator=(const Item&) = delete;

    // 이동은 허용(Inventory가 unique_ptr로 들고 다니기 좋음)
    Item(Item&&) noexcept = default;
    Item& operator=(Item&&) noexcept = default;

    // Getter
    const char* GetName() const;
    ItemType GetType() const;
    int GetValue() const;
    int GetPrice() const;

    // 판매 가격을 반환하는 함수
    int GetSellPrice(double sellRate) const;

private:
    // ★ 핵심: 외부 생성 금지, Factory만 생성 가능
    explicit Item(const ItemDefinition* def);

    // Factory에게만 생성 권한 부여
    friend class ItemFactory;
    
private:
    const ItemDefinition* def_ = nullptr; // ItemDefs 테이블 원소를 가리키는 포인터(전역 수명)
};
