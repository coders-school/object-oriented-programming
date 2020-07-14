#include "map.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <set>
#include <utility>

#include "store.hpp"

constexpr size_t kMapWidth = 50;
constexpr size_t kMapHeight = 50;

Map::Map() {
    generateIslands();
    currentPosition_ = &islands_.front();
}

void Map::travel(size_t option) {
    currentPosition_ = new Island(islands_[option]);
}

size_t Map::getDaysToArrive(size_t option) {
    return Coordinates::distance(currentPosition_->getPosition(), islands_[option].getPosition());
}

Island* Map::getIsland(const Coordinates& coordinates) {
    auto island = std::find_if(islands_.begin(), islands_.end(),
                               [&](const auto& island) {
                                   return coordinates == island.getPosition();
                               });
    return island != std::end(islands_) ? &*island : nullptr;
}

void Map::generateIslands() {
    std::random_device rd;
    std::mt19937 eng(rd());
    islands_.reserve(kIslandAmt);

    std::vector<unsigned int> positionsX(kMapWidth);
    std::vector<unsigned int> positionsY(kMapHeight);

    std::iota(positionsX.begin(), positionsX.end(), 0);
    std::iota(positionsY.begin(), positionsY.end(), 0);

    std::shuffle(positionsX.begin(), positionsX.end(), eng);
    std::shuffle(positionsY.begin(), positionsY.end(), eng);

    for (int i = 0; i < kIslandAmt; i++) {
        islands_.push_back(Island(positionsX[i], positionsY[i]));
    }
}

std::ostream& operator<<(std::ostream& out, Map& map) {
    std::sort(map.islands_.begin(), map.islands_.end(),
              [&](const auto& lhs, const auto& rhs) {
                  return Coordinates::distance(lhs.getPosition(), map.currentPosition_->getPosition()) <
                         Coordinates::distance(rhs.getPosition(), map.currentPosition_->getPosition());
              });

    out << "Islands that you can choose:\n";
    out << "-----------------------------\n";
    std::for_each(map.islands_.begin() + 1, map.islands_.end(),
                  [&, counter{1}](const auto& island) mutable {
                      out << counter++ << ") Coordinates: ";
                      out << island.getPosition();
                      out << " Distance: "
                          << Coordinates::distance(island.getPosition(), map.currentPosition_->getPosition()) << '\n';
                  });
    out << "-----------------------------\n";
    return out;
}
