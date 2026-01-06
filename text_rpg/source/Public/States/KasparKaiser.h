#pragma once

#include "States/Monster.h"

class KasparKaiser : public Monster
{
public:
    KasparKaiser(int Level);

    void GenerateStatus(int Level)override;

};