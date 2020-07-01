#pragma once

#include <memory>
#include <vector>

#include "island.hpp"

constexpr size_t MAP_SIZE = 10;  // 10 x 10
constexpr size_t MAX_ISLANDS = 10;

class Map {
public:
    Map();
    std::shared_ptr<Island> getCurrentPosition() const;
    std::shared_ptr<Island> getIsland(const Coordinates& coordinate) const;
    size_t getDistanceToIsland(std::shared_ptr<Island> destination) const;
    void travel(std::shared_ptr<Island> destination);
    friend std::ostream& operator<<(std::ostream& out, const Map& map);

private:
    std::vector<std::shared_ptr<Island>> islands_;
    std::shared_ptr<Island> currentPosition_;
};
