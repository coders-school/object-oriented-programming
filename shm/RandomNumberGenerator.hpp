#pragma once

#include <random>

class RandomNumberGenerator {
public:
    RandomNumberGenerator()
        : generator_{std::random_device{}()}, distribution_(0, 10) {}
    int nextRandomNumber() {
        return distribution_(generator_);
    }

private:
    std::mt19937 generator_;
    std::uniform_int_distribution<int> distribution_;
};
