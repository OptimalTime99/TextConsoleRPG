#pragma once
#include <string>
#include <map>
#include "Types/StatusType.h"

class Item
{
public:
    Item(std::string name, int price);

    // 아이템 효과 추가 함수
    void AddEffect(StatusType status, int value);

    // 게임 시작 시 한 번만 호출해서 데이터를 채워넣는 함수
    static void Initialize();

    // 이름으로 아이템 원형 데이터를 가져오는 함수
    static const Item* GetData(std::string name);

    // Getter
    std::string GetName() const;
    int GetPrice() const;
    std::map<StatusType, int> GetEffect() const;

    // Setter
    void SetName(const std::string& name);
    void SetPrice(int price);
    void SetEffect(const std::map<StatusType, int>& effect);

private:
    // 아이템 명
    std::string name_;

    // 아이템 가격
    int price_;

    // 아이템 효과를 저장하는 맵
    std::map<StatusType, int> effect_;

    // 아이템 원형 데이터를 저장하는 정적 맵
    static std::map<std::string, Item> itemRegistry_;
};