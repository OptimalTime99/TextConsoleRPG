#pragma once
#include <map>
#include <string>

class Inventory
{
public:
    // 아이템 추가 함수
    void AddItem(std::string name, int count);

    // 아이템 제거 함수
    bool RemoveItem(std::string name, int count);

    // 아이템 수량 조회 함수
    int GetItemCount(std::string name) const;

private:
    // 아이템 이름과 수량을 저장하는 맵
    std::map<std::string, int> inventory_; 
};