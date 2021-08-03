#pragma once

#include <random>

class RandomNumberGenerator {
public:
    RandomNumberGenerator(size_t distributionMin, size_t distributionMax)
        : generator_{std::random_device{}()}, distribution_(distributionMin, distributionMax) {}
    size_t nextRandomNumber() {
        return distribution_(generator_);
    }

private:
    std::mt19937 generator_;
    std::uniform_int_distribution<size_t> distribution_;
};
