#pragma once
#include <vector>

constexpr size_t COORDINATE_MIN = 0;
constexpr size_t COORDINATE_MAX = 99;
constexpr size_t ISLANDS_COUNT = 10;

class Island;
class Coordinates;

class Map {
public:
    Map();
    void DebugPrintIsland();
    Island* getIsland(const Coordinates& coordinate);
    void addIsland(Coordinates& coordinate);
private:
    Island *current_pos_;
    std::vector<Island> islands_;
    bool contains(const std::vector<Coordinates>& vec, const Coordinates& c);
    void SetUpRandomIsland();
};
