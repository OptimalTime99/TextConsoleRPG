#pragma once

#include "States/Monster.h"
#include "States/player.h"
#include <string>
#include <iostream>
#include <random>

class SebastianHorn : public Monster
{
public:
    SebastianHorn(int Level);

    void GenerateStatus(int Level)override;

};

