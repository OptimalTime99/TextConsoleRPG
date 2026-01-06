#pragma once

#include "States/Monster.h"
#include "States/player.h"
#include <string>
#include <iostream>
#include <random>

class BenediktKiss : public Monster
{
public:
    BenediktKiss(int Level);

    void GenerateStatus(int Level)override;

};