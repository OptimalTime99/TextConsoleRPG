#pragma once

#include "States/Monster.h"

class DominikYork : public Monster
{
public:
    DominikYork(int Level);

    void GenerateStatus(int Level)override;

};

