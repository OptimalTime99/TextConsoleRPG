#include "Utils/RandomUtil.h"
#include <random>

bool RandomUtil::GetRandomBoolean(double probability)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::bernoulli_distribution dis(probability);

    return dis(gen);
}

int RandomUtil::GetRandomInt(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dis(min, max);

    return dis(gen);
}
