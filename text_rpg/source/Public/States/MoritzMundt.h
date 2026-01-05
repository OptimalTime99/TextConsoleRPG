#pragma once

#include "States/Monster.h"
#include "States/player.h"
#include <string>
#include <iostream>
#include <random>

class MoritzMundt : public Monster
{
public:
    MoritzMundt(std::string Monstername_, int Level);

    void GenerateStatus(int Level)override;

};