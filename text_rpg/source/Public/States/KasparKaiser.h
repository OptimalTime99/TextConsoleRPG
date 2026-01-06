#pragma once

#include "States/Monster.h"
#include "States/player.h"
#include <string>
#include <iostream>
#include <random>

class KasparKaiser : public Monster
{
public:
    KasparKaiser(int Level);

    void GenerateStatus(int Level)override;

};