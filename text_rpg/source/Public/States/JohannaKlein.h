#pragma once

#include "States/Monster.h"

class JohannaKlein : public Monster
{
public:
    JohannaKlein(int Level);

    void GenerateStatus(int Level)override;

};