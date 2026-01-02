#pragma once

#include <memory>

class Item;

class ItemFactory
{
public:
    // 이름으로 아이템 생성 (정의가 없으면 nullptr 반환)
    static std::unique_ptr<Item> CreateByName(const char* name);
};
