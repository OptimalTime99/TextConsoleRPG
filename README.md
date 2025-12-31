# SF TEXT RPG

## 폴더 구조

```
Source/TextRPG/
├── Public/
│   ├── Core/
│   │   ├── GameManager.h
│   │   └── GameTypes.h
│   ├── States/
│   │   ├── Player.h
│   │   ├── Monster.h
│   │   ├── Inventory.h
│   │   └── Item.h
│   ├── Modes/
│   │   ├── BattleSystem.h
│   │   └── ShopSystem.h
│   ├── Interfaces/
│   │   └── (비워둠 또는 IUI.h, IRng.h 추후 확장)
│   └── UI/
│       └── UIManager.h
│
└── Private/
    ├── Core/
    │   ├── GameManager.cpp
    │   └── GameTypes.cpp
    ├── States/
    │   ├── Player.cpp
    │   ├── Monster.cpp
    │   ├── Inventory.cpp
    │   └── Item.cpp
    ├── Modes/
    │   ├── BattleSystem.cpp
    │   └── ShopSystem.cpp
    └── UI/
        └── UIManager.cpp
```