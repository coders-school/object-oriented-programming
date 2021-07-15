#pragma once
#include <vector>
#include <functional>
#include <random>
#include <memory>

class Map {
public:
    Map();
    Island* const getIsland(const Coordinates& coordinate);

private:
    const int maxWidth_ = 99;
    const int maxHeight_ = 99;
    const int islandsQuantity_ = 10;
    std::vector<Island> islands_;
    Island* currentPostion_;
    std::random_device randomDevice_;
    // std::mt19937 gen(rd());
    std::mt19937 randomGenerator_(std::random_device::result_type);
    std::uniform_int_distribution<> widthDistribution(std::mt19937);
    std::uniform_int_distribution<> heightDistribution(std::mt19937);
};