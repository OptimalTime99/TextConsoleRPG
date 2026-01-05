#pragma once

#include "States/Monster.h"
#include "States/player.h"
#include <string>
#include <iostream>
#include <random>

class StefanSommer : public Monster
{
public:
    StefanSommer(std::string Monstername_, int Level);

    void GenerateStatus(int Level)override;

};