#include "Types/ItemFactory.h"
#include "States/Item.h"
#include "Types/ItemDefs.h"

std::unique_ptr<Item> ItemFactory::CreateByName(const char* name)
{
    const ItemDefinition* def = FindItemDefByName(name);
    if (!def)
        return nullptr;

    // Item 생성자는 private이지만 friend class ItemFactory 덕분에 호출 가능
    return std::unique_ptr<Item>(new Item(def));
}
