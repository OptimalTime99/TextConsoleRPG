#pragma once

#include "States/Monster.h"

class StefanSommer : public Monster
{
public:
    StefanSommer(int Level);

    void GenerateStatus(int Level)override;

};