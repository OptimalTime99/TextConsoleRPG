#pragma once

#include "States/Monster.h"

class MoritzMundt : public Monster
{
public:
    MoritzMundt(int Level);

    void GenerateStatus(int Level)override;

};