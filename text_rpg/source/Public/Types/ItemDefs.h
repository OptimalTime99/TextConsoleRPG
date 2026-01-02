// ItemDefs.h
#pragma once
#include "Types/ItemType.h"

// 이름으로 ItemDefinition 조회 (없으면 nullptr)
const ItemDefinition* FindItemDefByName(const char* name);
