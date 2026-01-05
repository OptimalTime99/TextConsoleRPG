#pragma once

#include "States/Monster.h"
#include "States/player.h"
#include <string>
#include <iostream>
#include <random>

class KasparKaiser : public Monster
{
public:
    KasparKaiser(std::string Monstername_, int Level);

    void GenerateStatus(int Level)override;

};