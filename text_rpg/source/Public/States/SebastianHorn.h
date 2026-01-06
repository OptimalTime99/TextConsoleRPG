#pragma once

#include "States/Monster.h"

class SebastianHorn : public Monster
{
public:
    SebastianHorn(int Level);

    void GenerateStatus(int Level)override;

};

