#pragma once
#include <string>
#include <map>
#include "Types/StatusType.h"
#include "Types/ItemType.h"

class Item
{
public:
    Item() = default;
    Item(ItemType name, int price);

    // 아이템 효과 추가 함수
    void AddEffect(StatusType status, int value);

    // 게임 시작 시 한 번만 호출해서 데이터를 채워넣는 함수
    static void Initialize();

    // 이름으로 아이템 원형 데이터를 가져오는 함수
    static const Item* GetData(ItemType name);

    // Getter
    ItemType GetName() const;
    int GetPrice() const;
    std::map<StatusType, int> GetEffect() const;

    // 모든 아이템 원형 데이터를 가져오는 함수
    static const std::map<ItemType, Item>& GetAllItems();

    // 아이템 타입에 따른 문자열 변환 함수
    static std::string ItemTypeToString(ItemType type);

    // Setter
    void SetName(ItemType name);
    void SetPrice(int price);
    void SetEffect(const std::map<StatusType, int>& effect);

private:


    // 아이템 명
    ItemType name_;

    // 아이템 가격
    int price_;

    // 아이템 효과를 저장하는 맵
    std::map<StatusType, int> effect_;

    // 아이템 원형 데이터를 저장하는 정적 맵
    static std::map<ItemType, Item> itemRegistry_;
};