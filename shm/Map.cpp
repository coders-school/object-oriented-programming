#include "Map.hpp"

#include <algorithm>
#include <cstddef>
#include <random>

Map::Map() {
    islandsLocations_.reserve(amountOfIslands);
    generateIslands(amountOfIslands);
    setCurrentPosition(&islandsLocations_[0]);
}

void Map::generateIslands(int numOfIslandsToGenerate) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(minPositionXY, maxPositionXY);

    size_t positionX{};
    size_t positionY{};
    while (numOfIslandsToGenerate){
        positionX = distrib(gen);
        positionY = distrib(gen);
        if (std::none_of(islandsLocations_.begin(), islandsLocations_.end(),
                        [positionX, positionY](const auto& island) {
                            return island.getPosition() == Coordinates(positionX, positionY);
                        })) {
            addIsland({positionX, positionY});
            --numOfIslandsToGenerate;
        }
    }
}

void Map::setCurrentPosition(Island* const currentPosition) {
    currentPosition_ = currentPosition;
}

void Map::addIsland(const Island& newIsland) {
    islandsLocations_.push_back(newIsland);
}

Island* Map::getIsland(const Coordinates& coordinate) {
    auto island = std::find_if(islandsLocations_.begin(), islandsLocations_.end(),
                               [&coordinate](const auto& isld) {
                                   return isld.Island::getPosition() == coordinate;
                               });

    return (island != islandsLocations_.end()) ? &(*island) : nullptr;
}

size_t Map::getDistanceToIsland(Island* destination) {
    return Coordinates::distance(currentPosition_->getPosition(), destination->getPosition());
}

//Start of helper functions for operator<<

void placeMarkersOnMapScreen(std::ostream& out, const std::vector<Island>& islandLocations, const Coordinates& cord, const Coordinates& currentPosition) {
    const std::string islandMarker = "O";
    const std::string currentLocationMarker = "X";
    const std::string waterMarker = " ";

    auto foundLocation = std::find_if(islandLocations.begin(), islandLocations.end(), [&cord](const auto& el) { return el.getPosition() == cord; });

    if (foundLocation != islandLocations.end()) {
        out << ((foundLocation->getPosition() == currentPosition) ? currentLocationMarker : islandMarker) << "\t";
    }
    else {
        out << waterMarker << '\t';
    }
}

void Map::populateMapScreen(std::ostream& out) const {
    auto playerPosition = currentPosition_->getPosition();
    for (size_t row = minPositionXY; row <= maxPositionXY; row++) {
        out << row << '\t';
        for (size_t column = minPositionXY; column <= maxPositionXY; column++) {
            Coordinates cord(column, row);
            placeMarkersOnMapScreen(out, islandsLocations_, cord, playerPosition);
        }
        out << "\n";
    }
}

void fillXCoordinatesRow(std::ostream& out) {
    for (size_t i = minPositionXY; i <= maxPositionXY; i++) {
        out << '\t' << i;
    }
    out << '\n';
}

//End of helper functions for operator<<

std::ostream& operator<<(std::ostream& out, const Map& map) {
    fillXCoordinatesRow(out);
    map.populateMapScreen(out);

    return out;
}
