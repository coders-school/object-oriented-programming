#include "Map.hpp"

#include <algorithm>
#include <cstddef>
#include <random>

Map::Map() {
    islandsLocations_.reserve(amountOfIslands);
    generateIslands(amountOfIslands);
}

void Map::generateIslands(int numOfIslandsToGenerate) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(minPositionXY, maxPositionXY);

    size_t positionX{};
    size_t positionY{};
    do {
        positionX = distrib(gen);
        positionY = distrib(gen);
        if (std::any_of(islandsLocations_.begin(), islandsLocations_.end(),
                        [positionX, positionY](const auto& island) {
                            return island.getPosition() == Coordinates(positionX, positionY);
                        })) {
            addIsland({positionX, positionY});
        }
    } while (--numOfIslandsToGenerate);
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

void placeMarkersOnMapScreen(std::ostream& out, const std::vector<Island>& islandLocations, const Coordinates& cord, size_t& columnIndex, const Coordinates& currentPosition) {
    const std::string islandMarker = "O";
    const std::string currentLocation = "X";
    const std::string waterMarker = " ";

    for (auto& loc : islandLocations) {
        if (loc.getPosition() == cord) {
            columnIndex++;
            if (loc.getPosition() == currentPosition)
                out << currentLocation << "\t";
            else
                out << islandMarker << "\t";
            break;
        }
    }
    out << waterMarker << '\t';
}

void populateMapScreen(std::ostream& out, const Map& map) {
    auto playerPosition = map.currentPosition_->getPosition();
    for (size_t row = minPositionXY + 1; row <= maxPositionXY; row++) {
        out << row << '\t';
        for (size_t column = minPositionXY + 1; column <= maxPositionXY; column++) {
            Coordinates cord(column, row);
            placeMarkersOnMapScreen(out, map.islandsLocations_, cord, column, playerPosition);
        }
        out << "\n";
    }
}

void fillXCoordinatesRow(std::ostream& out) {
    for (size_t i = minPositionXY + 1; i <= maxPositionXY; i++) {
        out << '\t' << i;
    }
    out << '\n';
}

//End of helper functions for operator<<

std::ostream& operator<<(std::ostream& out, const Map& map) {
    fillXCoordinatesRow(out);
    populateMapScreen(out, map);

    return out;
}
