# **Text RPG Project (Assassinate)**
 <img width="1484" height="886" alt="image" src="https://github.com/user-attachments/assets/22edb4d1-7a2b-4c60-8538-91db1d968321" />

## **Project Outline**
- **개발 기간**: 2025.12.29 ~ 2026.01.06
- **개발 인원**: 5명 (Team Project)
- **주요 목표**:
    - C++ 클래스 상속과 다형성을 활용한 유연한 시스템 설계
    - Git-Flow 및 코드 리뷰를 통한 협업 프로세스 경험
    - 메모리 효율성을 고려한 디자인 패턴(Singleton, Flyweight) 적용

## **Game Scenario**
**"끝나지 않는 성간 전쟁, 전황을 뒤집을 단 한 번의 암살."**

> 행성 간 전쟁이 격화된 미래, 전선은 오랜 시간 고착되어 전면전으로는 승부를 낼 수 없는 상황에 이르렀습니다.
>
> 사령부는 소모적인 전투 대신, 적의 핵심 지휘관을 제거하여 전황을 뒤집는 참수 작전을 계획합니다.
> 당신은 특수 요원이 되어 적진 깊숙이 침투하고, 적의 장교를 암살하는 임무를 완수해야 합니다.


## **Team Members & Roles**

| 직책 | 이름 & GitHub | 담당 업무 (Role & Responsibilities) |
|:---:|:---:|:---|
| **팀장** | [최준혁](https://github.com/OptimalTime99) | • **PM**: 전체 개발 일정 관리, 일일 스크럼 진행, Git-Flow 전략 수립 및 코드 리뷰 문화 정착<br>• **Design**: 전체 클래스 설계, 폴더 구조 설계, UML 다이어그램 작성<br>• **Dev**: `Flyweight Pattern`을 적용하여 메모리 효율을 최적화한 **Item/Inventory** 구현<br>• **QA/Etc**: 테스트 케이스 작성/관리, 발표 자료(PPT) 준비 및 진행 |
| **부팀장** | [박원종](https://github.com/WonJongPark) | • **Core**: `Singleton`, `Facade Pattern`을 활용한 **GameManager** 구현<br>• **Content**: **BattleSystem** 로직 구현, 랜덤 난수 유틸리티 함수 제작<br>• **DevOps**: 형상 관리(Git Management) 담당 |
| **부팀장** | [정주현](https://github.com/wjdwngus2056-jpg) | • **System**: `Deque` 자료구조를 활용한 **UISystem** 구현<br>• **Content**: **ShopSystem** 구현<br>• **Doc**: 게임 로직 플로우 차트(Flow Chart) 작성 |
| **팀원** | [이재현](https://github.com/zazang70-hue) | • **Content**: `추상 클래스`를 활용한 다형성 기반 **Monster** 구현<br>• **Media**: 프로젝트 시연 영상 편집 및 제작 |
| **팀원** | [변유민](https://github.com/voov-v) | • **Content**: **Player** 클래스 및 성장 시스템(**LevelSystem**) 구현<br>• **QA**: 버그 리포팅 및 QA 진행 |

## **Tech Stack**
- **Language**: C++ 17 Standard
- **Key Concepts**:
    - **OOP (Object-Oriented Programming)**: 상속(Inheritance), 다형성(Polymorphism), 캡슐화(Encapsulation)를 준수한 설계
    - **Design Patterns**:
        - `Singleton`: 매니저 클래스 관리
        - `Flyweight`: 아이템/인벤토리 메모리 최적화
        - `Facade`: 복잡한 서브 시스템의 통합 인터페이스 제공
    - **STL (Standard Template Library)**:
        - `std::vector`, `std::map`을 활용한 데이터 관리
        - `std::deque`을 활용한 UI 시스템 구현


## **시연 영상 링크**
https://www.youtube.com/watch?v=29JPRCF0YcE

## **Gameplay Flow**
### **게임시작 ~ 스토리**
![타이틀과 스토리](https://github.com/user-attachments/assets/4b09cbf1-44b7-49be-acde-cb51ab85ad1c)

---

### **캐릭터 생성**
![캐릭터 생성](https://github.com/user-attachments/assets/fdfa5661-01fa-43ba-b42c-45a0150326e9)

---

### **전투 / 아이템 사용**
![전투와 아이템 사용](https://github.com/user-attachments/assets/86a22ccd-de39-45c8-8f90-85f0552ccbf0)


---

### **상점 이용(구매/판매)**
![상점 이용](https://github.com/user-attachments/assets/80078767-cdcf-4690-8b3a-15cf2578e149)

---

### **보스 전투 / 게임 클리어**
![보스](https://github.com/user-attachments/assets/5f25762d-5feb-4153-9414-b5a39b7631a8)

---

### **게임 오버**
<img width="1483" height="888" alt="image" src="https://github.com/user-attachments/assets/7a3d120c-ce8f-4290-be8b-2af319b794b8" />

---

## **System Architecture**
### **플로우 차트**
<img width="1356" height="921" alt="image" src="https://github.com/user-attachments/assets/09d10a8b-39f5-4315-b3a1-663dd17049cd" />

---

### **Class Diagram**
<img width="1676" height="1127" alt="image" src="https://github.com/user-attachments/assets/a2ab5fc2-6b15-4428-b603-8de81860756e" />

- **유지보수**를 위해 '**중앙 제어'와 '기능 모듈화**'에 초점을 맞췄습니다.
- 다이어그램 중앙의 **GameManager**가 컨트롤 타워로서 게임 전체의 생명주기를 관리합니다.
- GameManager가 모든 것을 처리하지 않고, BattleSystem, ShopSystem 등으로 역할을 분리해서 **단일 책임 원칙을** 준수했습니다. 
- BattleSystem은 전투 시 몬스터를 직접 생성하고 관리하고, 전투 종료 시 소멸시킵니다.

---

### **Project Structure**
<img width="1795" height="1008" alt="image" src="https://github.com/user-attachments/assets/1ede8174-05ec-425d-aec5-b080856b9794" />

- 프로젝트의 유지보수성과 확장성을 위해 언리얼 엔진의 아키텍처를 차용했습니다.
- 물리적 구조는 언리얼의 모듈 시스템을 따라 헤더를 Public에, 소스를 Private에 분리해서, 코드의 은닉성을 높이고 의존성을 관리했습니다.
- 논리적 구조는 언리얼의 4대 클래스 개념을 도입하여 역할을 명확히 했습니다.
  - GameManager: 전체 생명 주기 관리
  - GameMode: 흐름 제어
  - GameState: 데이터
  - UIManager: 표시
 
---

### **Git Flow**
<img width="1799" height="1009" alt="image" src="https://github.com/user-attachments/assets/28049dfd-f43c-4167-8ee9-027a09073909" />
- `main`과 `develop`, 그리고 기능별 `feature` 브랜치를 분리해서 개발 중인 코드가 안정 버전에 영향을 주지 않도록 격리했습니다.

---

## **Testing**
<img width="1786" height="1260" alt="image" src="https://github.com/user-attachments/assets/695ac57c-b695-4cca-b506-a9eeccab42db" />

---

## **Technology**
<img width="1798" height="1012" alt="image" src="https://github.com/user-attachments/assets/2922c1da-55db-47ef-a76e-5e23847cfc8c" />

- 싱글톤 패턴을 적용해서 인스턴스의 유일성을 보장했고,
- 퍼사드 패턴을 적용해서 복잡한 서브 시스템을 내부로 숨겨 외부 호출 인터페이스를 단순화했습니다.
---

<img width="1797" height="1011" alt="image" src="https://github.com/user-attachments/assets/16c32d3e-0066-42c7-8c2a-21fbb96c9818" />

- 공통 로직은 부모 클래스로 통합해서 **코드 중복을 최소화**했고, `GenerateStatus` 함수를 오버라이딩해서 **다형성**을 확보했습니다.
---

<img width="1795" height="1008" alt="image" src="https://github.com/user-attachments/assets/cd863279-1805-43a3-ae27-0c14ed568b27" />

### **플라이웨이트 패턴을 통한 인벤토리 메모리 최적화**
- **Problem**: 초기 개발 시, `Inventory` 내의 모든 아이템을 개별 객체로 생성(`new`)하여 `Vector`로 관리했습니다. 하지만 동일한 아이템(예: '포션')이 100개 있을 때 100개의 객체가 생성되는 비효율적인 메모리 구조임을 인지했습니다.
- **Approach**: 팩토리 패턴을 고려했으나 근본적인 중복 데이터 해결이 필요했습니다. "인벤토리가 굳이 아이템의 모든 정보를 가질 필요가 있을까?"라는 의문 끝에 **Flyweight Pattern**을 도입했습니다.
- **Result**:
    - 아이템의 고유 정보(이름, 설명, 기본 스탯)는 **원형(Prototype) 객체 하나만 생성**하여 공유.
    - 인벤토리는 해당 아이템의 이름과 개수만 관리하도록 구조 변경.
    - 결과적으로 객체 생성 비용을 최소화하고 메모리 사용량을 획기적으로 줄였습니다.
 
---

<img width="1795" height="1009" alt="image" src="https://github.com/user-attachments/assets/7329486d-91e7-4fbf-8a02-b28404323838" />

---

## **Team Retrospective**

1.  **아키텍처와 의존성 (Architecture & Dependency)**
    - `GameManager`에 너무 많은 시스템이 의존하는 문제가 발생했습니다. (God Class 문제)
    - 향후 **Component Pattern**을 도입하여 각 시스템의 결합도를 낮추고 모듈화하기로 논의했습니다.
2.  **디자인 패턴의 필요성 (Design Patterns)**
    - UI 업데이트 시 **Observer Pattern**을 적용했다면 상태 변화를 더 효율적으로 감지했을 것이라는 피드백이 있었습니다.
    - 상점 시스템 등에서 **Strategy Pattern**이나 판매 테이블 분리를 통해 확장성을 높일 필요성을 느꼈습니다.
3.  **Modern C++ 메모리 관리**
    - `new/delete`를 직접 사용하는 방식에서 오는 메모리 관리의 어려움을 겪었습니다.
    - 차기 프로젝트에서는 **Smart Pointer(shared_ptr, unique_ptr)** 도입을 통해 메모리 누수(Memory Leak)를 원천 차단하기로 했습니다.

