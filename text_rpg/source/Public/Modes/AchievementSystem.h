#pragma once
#include <map>
#include <string>

class AchievementSystem
{
public:
    AchievementSystem() {};
    ~AchievementSystem() {};

    void AddKillCount(std::string);
    std::map<std::string, int> GetAllKillCount();

private:
    std::map<std::string, int> MonsterKillCount_;
};