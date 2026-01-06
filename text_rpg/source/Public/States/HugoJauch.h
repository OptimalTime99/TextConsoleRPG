#pragma once

#include "States/Monster.h"

class HugoJauch : public Monster
{
public:
    HugoJauch(int Level);

    void GenerateStatus(int Level)override;

};