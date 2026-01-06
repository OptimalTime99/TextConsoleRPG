#pragma once

#include "States/Monster.h"
#include "States/player.h"
#include <string>
#include <iostream>
#include <random>

class NormalMonster : public Monster
{
public:
    NormalMonster(int Level);

    void GenerateStatus(int Level)override;

};
