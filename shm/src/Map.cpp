#include "Map.hpp"

#include <random>

constexpr int COORDINATE_MIN = 0;
constexpr int COORDINATE_MAX = 99;

Map::Map() {
    std::random_device rd;
    std::mt19937 generator(rd);
    std::uniform_int_distribution<> distribution{
        COORDINATE_MIN, COORDINATE_MAX
    };
}
