#pragma once

#include "States/Monster.h"
#include "States/player.h"
#include <string>
#include <iostream>
#include <random>

class HugoJauch : public Monster
{
public:
    HugoJauch(std::string Monstername_, int Level);

    void GenerateStatus(int Level)override;

};