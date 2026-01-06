#pragma once

#include "States/Monster.h"

class KevinKruger : public Monster
{
public:
    KevinKruger(int Level);

    void GenerateStatus(int Level)override;

};