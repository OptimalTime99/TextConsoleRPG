#pragma once

#include "States/Monster.h"
#include "States/player.h"
#include <string>
#include <iostream>
#include <random>

class KevinKruger : public Monster
{
public:
    KevinKruger(int Level);

    void GenerateStatus(int Level)override;

};