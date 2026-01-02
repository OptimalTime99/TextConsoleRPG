// 게임의 아이템 원형(정의)을 한 곳에 모아두고, 이름으로 빠르게 찾아주는 데이터 테이블 모듈
#include "Types/ItemDefs.h"
#include <unordered_map>
#include <cstring>   // strcmp (선형 fallback용)
#include <string>

namespace
{
    // 1) 원본 데이터 테이블 (전역 수명, 불변)
    static const ItemDefinition kItemDefs[] =
    {
        { "HealPotion1",  ItemType::HealPotion, 50, 10 },
        { "AtkPotion1",   ItemType::AtkPotion, 10, 20 },
    };

    constexpr int kItemDefCount =
        sizeof(kItemDefs) / sizeof(kItemDefs[0]);

    // 2) name -> def 포인터 인덱스 (cpp 내부 전용)
    static std::unordered_map<std::string, const ItemDefinition*> gNameIndex;

    // 3) 인덱스 초기화 (1회)
    static void BuildNameIndex()
    {
        gNameIndex.reserve(kItemDefCount);
        for (int i = 0; i < kItemDefCount; ++i)
        {
            gNameIndex.emplace(kItemDefs[i].Name_, &kItemDefs[i]);
        }
    }

    // 4) 정적 초기화 트릭: 프로그램 시작 시 자동 실행
    struct FNameIndexInitializer
    {
        FNameIndexInitializer()
        {
            BuildNameIndex();
        }
    };

    static FNameIndexInitializer GNameIndexInitializer;
}

const ItemDefinition* FindItemDefByName(const char* name)
{
    if (!name) return nullptr;

    // 평균 O(1)
    auto it = gNameIndex.find(name);
    if (it != gNameIndex.end())
    {
        return it->second;
    }

    return nullptr;
}
