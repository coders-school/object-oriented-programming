#include "Map.hpp"

#include <algorithm>
#include <random>

Map::Map() : sizeX_(10), sizeY_(10) {
    islandGenerator(10);
}
Map::Map(size_t sizeX, size_t sizeY, size_t islandAmount)
    : sizeX_(sizeX), sizeY_(sizeY) {
    islandGenerator(islandAmount);
}

void Map::islandGenerator(size_t amount) {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::vector<int> temporaryMap_(sizeX_ * sizeY_);
    std::iota(std::begin(temporaryMap_), std::end(temporaryMap_), 0);
    std::shuffle(std::begin(temporaryMap_), std::end(temporaryMap_), gen);

    for(size_t i = 0; i < amount; ++i) {
        islandsArrangement_.push_back(Island(temporaryMap_[i] % sizeX_,
                                            (temporaryMap_[i] / sizeX_)  % sizeY_));
    }
}
Island* Map::getIsland(const Coordinates& coordinates) {
    auto islandIterator = std::find_if(std::begin(islandsArrangement_),
                               std::end(islandsArrangement_),
                               [&coordinates](const auto& island) {
                                   return island.getPosition() == coordinates;
                               });
    if(islandIterator != std::end(islandsArrangement_)) {
        return &(*islandIterator);
    }
    return nullptr;
}
