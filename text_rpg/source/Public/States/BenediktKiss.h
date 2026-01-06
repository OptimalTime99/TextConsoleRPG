#pragma once

#include "States/Monster.h"

class BenediktKiss : public Monster
{
public:
    BenediktKiss(int Level);

    void GenerateStatus(int Level)override;

};