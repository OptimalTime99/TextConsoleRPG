#include "Modes/AchievementSystem.h"

void AchievementSystem::AddKillCount(std::string name)
{
    if (MonsterKillCount_.find(name) != MonsterKillCount_.end())
    {
        MonsterKillCount_[name] += 1;
    }
    else
    {
        MonsterKillCount_.insert(std::pair<std::string, int>(name, 1));
    }
}

std::map<std::string, int> AchievementSystem::GetAllKillCount()
{
    return MonsterKillCount_;
}
