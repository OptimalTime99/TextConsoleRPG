#pragma once

#include "States/Monster.h"

class EliasBeck : public Monster
{
public:
    EliasBeck(int Level);

    void GenerateStatus(int Level)override;

};