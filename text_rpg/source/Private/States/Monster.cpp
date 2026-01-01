#include "States/Monster.h"
#include "States/player.h"
#include <string>
#include <iostream>
#include <random>

Monster::Monster(std::string MonsterName,int Level,bool bisBoss) : MonsterName_(MonsterName), MonsterLevel_(Level), bisBoss_(bisBoss)
{
    if (bisBoss)
    {
        GenerateBoss(MonsterLevel_);
    }
    else
    {
        GenerateNomal(MonsterLevel_);
    }
}

void Monster::GenerateNomal(int Level_)
{
    bisBoss_ = false;
    MonsterName_ = "Unknown";
    MonsterLevel_ = Level_;
    if (MonsterLevel_ == 0)
    {
        return;
    }
    
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> Dist(Level_ * 20, Level_ * 30);

    this->HP_ = Dist(gen);
    this->Attack_ = Dist(gen);

    std::cout << "이름: " << MonsterName_ << "(Lv." << MonsterLevel_ << ")" << std::endl;
    std::cout << "HP: " << HP_ << " /  Attack: " << Attack_ << std::endl;
}

void Monster::GenerateBoss(int Level_)
{
    bisBoss_ = true;
    MonsterName_ = "카르파르 카이저";
    MonsterLevel_ = Level_ + 5;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> Dist(Level_ * 30, Level_ * 45);

    this->HP_ = Dist(gen);
    this->Attack_ = Dist(gen);



    std::cout << "이름: " << MonsterName_ << "(Lv." << MonsterLevel_ << ")" << std::endl;
    std::cout << "HP: " << HP_ << " /  Attack: " << Attack_ << std::endl;
}

void Monster::TakeDamage(int dmg)
{
    if (dmg < 0)
    {
        dmg = 0;
    }

    HP_ -= dmg;

    if (HP_ < 0)
    {
        HP_ = 0;
    }

}

bool Monster::isDead() const
{
    return HP_ <= 0;
}